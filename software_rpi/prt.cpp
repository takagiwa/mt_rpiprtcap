#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <pigpiod_if2.h>

enum PRT_PORTS {
  PRT_O_DDir = 2,
  PRT_O_DOE,
  PRT_O_OE,
  PRT_O_IE,
  PRT_I_D1 = 8,
  PRT_I_D2,
  PRT_I_D3,
  PRT_I_D4,
  PRT_I_D5,
  PRT_I_D6,
  PRT_I_D7,
  PRT_I_D8,
  PRT_O_nFault,
  PRT_O_nSelectIn,
  PRT_O_PError,
  PRT_O_nAck,
  PRT_O_Busy,
  PRT_O_OSCTX,
  PRT_I_nStrobe = 24,
  PRT_I_nAutoFd,
  PRT_I_nInit,
  PRT_I_Select
};

/* https://qiita.com/supaiku2452/items/10772cbd2706dede06b9 */
void abrt_handler(int sig, siginfo_t *info, void *ctx);
volatile sig_atomic_t eflag = 0;

int my_set_mode(int pi, unsigned int gpio, unsigned int mode)
{
  int ret;
  ret = set_mode(pi, gpio, mode);
  if (ret < 0) {
    printf("[ERROR] set_mode error for %d: %s\n", gpio, pigpio_error(ret));
    return -1;
  }
  return 0;
}

int my_gpio_write(int pi, unsigned int gpio, unsigned level)
{
  int ret;
  ret = gpio_write(pi, gpio, level);
  if (ret < 0) {
    printf("[ERROR] gpio_write error for %d: %s\n", gpio, pigpio_error(ret));
    return -1;
  }
  return 0;
}

int main(void)
{
  unsigned int v;
  int pi;
  uint32_t r;
  int ret;
  unsigned int rd, prev_rd;
  int i, j, b, prev_b;
  uint32_t st, t;
  FILE *fp;
  char s[256];

  struct sigaction sa_sigabrt;
  memset(&sa_sigabrt, 0, sizeof(sa_sigabrt));
  sa_sigabrt.sa_sigaction = abrt_handler;
  sa_sigabrt.sa_flags = SA_SIGINFO;

  if ( sigaction(SIGINT, &sa_sigabrt, NULL) < 0 ) {
    exit(1);
  }

  v = pigpiod_if_version();
  printf("[INFO] pigpiod_if2 version: %d\n", v);

  pi = pigpio_start(0, 0);
  if (pi < 0) {
    printf("[ERROR] pigpio_start() failed: %s\n", pigpio_error(pi));
    return -1;
  }
  printf("[INFO] pi: %d\n", pi);

  r = get_pigpio_version(pi);
  printf("[INFO] pigpio version: %d\n", r);

  r = get_hardware_revision(pi);
  printf("[INFO] hardware revision: %d\n", r);

  /* set initial output data */
  ret = 0;
  ret += my_gpio_write(pi, PRT_O_DDir, 0); /* input */
  ret += my_gpio_write(pi, PRT_O_DOE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_OE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_IE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_nFault, 1); /* low when error */
  ret += my_gpio_write(pi, PRT_O_nSelectIn, 1); /* high when selected and ready */
  ret += my_gpio_write(pi, PRT_O_PError, 0); /* high to "empty" */
  ret += my_gpio_write(pi, PRT_O_nAck, 1); /* low when ack */
  ret += my_gpio_write(pi, PRT_O_Busy, 0); /* high when not ready to receive */
  ret += my_gpio_write(pi, PRT_O_OSCTX, 0); /* should not used */
  if (ret != 0) {
    printf("[ERROR] initial gpio_write error.\n");
    pigpio_stop(pi);
    return -1;
  }

  /* direction setup */
  ret = 0;
  if (0) ret += my_set_mode(pi, 0, PI_INPUT);  /* pullup */
  if (0) ret += my_set_mode(pi, 1, PI_INPUT);  /* pullup */
  ret += my_set_mode(pi, 2, PI_OUTPUT); /* DDir */
  ret += my_set_mode(pi, 3, PI_OUTPUT); /* DOE */
  ret += my_set_mode(pi, 4, PI_OUTPUT); /* OE */
  ret += my_set_mode(pi, 5, PI_OUTPUT); /* IE */
  ret += my_set_mode(pi, 6, PI_INPUT);  /* N.C. */
  ret += my_set_mode(pi, 7, PI_INPUT);  /* N.C. */
  ret += my_set_mode(pi, 8, PI_INPUT);  /* D1 */
  ret += my_set_mode(pi, 9, PI_INPUT);  /* D2 */
  ret += my_set_mode(pi, 10, PI_INPUT); /* D3 */
  ret += my_set_mode(pi, 11, PI_INPUT); /* D4 */
  ret += my_set_mode(pi, 12, PI_INPUT); /* D5 */
  ret += my_set_mode(pi, 13, PI_INPUT); /* D6 */
  ret += my_set_mode(pi, 14, PI_INPUT); /* D7 */
  ret += my_set_mode(pi, 15, PI_INPUT); /* D8 */
  ret += my_set_mode(pi, 16, PI_OUTPUT); /* nFault */
  ret += my_set_mode(pi, 17, PI_OUTPUT); /* nSelectIn */
  ret += my_set_mode(pi, 18, PI_OUTPUT); /* PError */
  ret += my_set_mode(pi, 19, PI_OUTPUT); /* nAck */
  ret += my_set_mode(pi, 20, PI_OUTPUT); /* Busy */
  ret += my_set_mode(pi, 21, PI_OUTPUT); /* OSCTX */
  ret += my_set_mode(pi, 22, PI_INPUT); /* N.C. */
  ret += my_set_mode(pi, 23, PI_INPUT); /* N.C. */
  ret += my_set_mode(pi, 24, PI_INPUT); /* nStrobe */
  ret += my_set_mode(pi, 25, PI_INPUT); /* nAutoFd */
  ret += my_set_mode(pi, 26, PI_INPUT); /* nInit */
  ret += my_set_mode(pi, 27, PI_INPUT); /* Select */
  if (ret != 0) {
    printf("[ERROR] set_mode error.\n");
    pigpio_stop(pi);
    return -1;
  }

  ret = 0;
  ret += my_gpio_write(pi, PRT_O_DDir, 0); /* input */
  ret += my_gpio_write(pi, PRT_O_DOE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_OE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_IE, 0); /* active */
  ret += my_gpio_write(pi, PRT_O_nFault, 1); /* low when error */
  ret += my_gpio_write(pi, PRT_O_nSelectIn, 1); /* high when selected and ready */
  ret += my_gpio_write(pi, PRT_O_PError, 0); /* high to "empty" */
  ret += my_gpio_write(pi, PRT_O_nAck, 1); /* low when ack */
  ret += my_gpio_write(pi, PRT_O_Busy, 0); /* high when not ready to receive */
  ret += my_gpio_write(pi, PRT_O_OSCTX, 0); /* should not used */
  if (ret != 0) {
    printf("[ERROR] initial gpio_write error.\n");
    pigpio_stop(pi);
    return -1;
  }

  fp = fopen("prt.bin", "wb");
  if (fp == NULL) {
    printf("[ERROR] Failed to open file.\n");
    pigpio_stop(pi);
    return -1;
  }

  st = get_current_tick(pi);

  i = 0;
  j = 0;
  prev_rd = 0xFFFFFFFF;
  prev_b = 1;
  while (!eflag) {
    if (0) {
    rd = 0;
    for (i = 0; i < 28; i++) {
      b = gpio_read(pi, i);
      rd |= (b & 0x1) << i;
    }
    if (rd != prev_rd) {
      t = get_current_tick(pi) - st;
      printf("@%d: ", t);

      printf("nStrobe: %d, nAutoFd: %d, nInit: %d, Select: %d, Data: 0x%02X\n",
        (rd >> PRT_I_nStrobe) & 0x1, (rd >> PRT_I_nAutoFd) & 0x1,
        (rd >> PRT_I_nInit) & 0x1, (rd >> PRT_I_Select) & 0x1,
        (rd >> PRT_I_D1) & 0xF);
      printf("nFault: %d, nSelectIn: %d, PError: %d, nAck: %d, Busy: %d\n",
        gpio_read(pi, PRT_O_nFault) & 0x1, gpio_read(pi, PRT_O_nSelectIn) & 0x1,
        gpio_read(pi, PRT_O_PError) & 0x1, gpio_read(pi, PRT_O_nAck) & 0x1,
        gpio_read(pi, PRT_O_Busy) & 0x1);

      if (((rd >> PRT_I_nStrobe) & 0x1) == 0) {
        ret = my_gpio_write(pi, PRT_O_Busy, 1);
        ret = my_gpio_write(pi, PRT_O_nAck, 0);
        ret = my_gpio_write(pi, PRT_O_nAck, 1);
        ret = my_gpio_write(pi, PRT_O_Busy, 0);
        for (j = 0; j < 1000; j++) {
          b = gpio_read(pi, PRT_I_nStrobe);
          if (b == 1) {
            break;
          }
        }
      }

      prev_rd = rd;
    }
    }
    if (0) {
      ret = my_gpio_write(pi, PRT_O_OSCTX, i%2);
      i++;
      time_sleep(0.5);
    }
    if (1) {
      b = gpio_read(pi, PRT_I_nStrobe);
      if ((prev_b == 1) && ((b & 0x1) == 0)) {
        ret = my_gpio_write(pi, PRT_O_Busy, 1);

        if (1) {
          rd = 0;
          for (i = 0; i < 8; i++) {
            rd |= (gpio_read(pi, i+PRT_I_D1) & 0x1) << i;
          }
          if (0) {
            sprintf(s, "%02x\n", rd);
            fputs(s, fp);
          } else {
            putc(rd, fp);
          }
        }

        ret = my_gpio_write(pi, PRT_O_nAck, 0);
        ret = my_gpio_write(pi, PRT_O_nAck, 1);
        if (0) ret = my_gpio_write(pi, PRT_O_Busy, 0);

        j++;
      } else {
        ret = my_gpio_write(pi, PRT_O_Busy, 0);
      }
      prev_b = b;
    }
  }

  printf("j: %d\n", i);

  fclose(fp);
  pigpio_stop(pi);
  return 0;
}

void abrt_handler(int sig, siginfo_t *info, void *ctx) {
  printf("si_signo:%d\nsi_code:%d\n", info->si_signo, info->si_code);
  printf("si_pid:%d\nsi_uid:%d\n", (int)info->si_pid, (int)info->si_uid);
  eflag = 1;
}


EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "mt_rpiprtcap"
Date "2020-10-04"
Rev "0.1"
Comp ""
Comment1 "Masayuki Takagiwa"
Comment2 "https://github.com/takagiwa/mt_rpiprtcap"
Comment3 ""
Comment4 "GPLv2"
$EndDescr
$Comp
L Connector:Raspberry_Pi_2_3 J1
U 1 1 5FCE0138
P 4750 3550
F 0 "J1" H 4750 5031 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 4750 4940 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20_Pitch2.54mm" H 4750 3550 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/rpi_SCH_3bplus_1p0_reduced.pdf" H 4750 3550 50  0001 C CNN
	1    4750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FCE5F65
P 4250 4950
F 0 "#PWR02" H 4250 4700 50  0001 C CNN
F 1 "GND" H 4255 4777 50  0000 C CNN
F 2 "" H 4250 4950 50  0001 C CNN
F 3 "" H 4250 4950 50  0001 C CNN
	1    4250 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5FCE62F7
P 4050 2150
F 0 "#PWR01" H 4050 2000 50  0001 C CNN
F 1 "+5V" H 4065 2323 50  0000 C CNN
F 2 "" H 4050 2150 50  0001 C CNN
F 3 "" H 4050 2150 50  0001 C CNN
	1    4050 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR03
U 1 1 5FCE66C1
P 5450 2150
F 0 "#PWR03" H 5450 2000 50  0001 C CNN
F 1 "+3V3" H 5465 2323 50  0000 C CNN
F 2 "" H 5450 2150 50  0001 C CNN
F 3 "" H 5450 2150 50  0001 C CNN
	1    5450 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2250 4550 2200
Wire Wire Line
	4550 2200 4050 2200
Wire Wire Line
	4050 2200 4050 2150
Wire Wire Line
	4650 2250 4650 2200
Wire Wire Line
	4650 2200 4550 2200
Connection ~ 4550 2200
Wire Wire Line
	4850 2250 4850 2200
Wire Wire Line
	4850 2200 4950 2200
Wire Wire Line
	5450 2200 5450 2150
Wire Wire Line
	4950 2250 4950 2200
Connection ~ 4950 2200
Wire Wire Line
	4950 2200 5450 2200
Wire Wire Line
	5050 4850 5050 4900
Wire Wire Line
	5050 4900 4950 4900
Wire Wire Line
	4250 4900 4250 4950
Wire Wire Line
	4350 4850 4350 4900
Connection ~ 4350 4900
Wire Wire Line
	4350 4900 4250 4900
Wire Wire Line
	4450 4850 4450 4900
Connection ~ 4450 4900
Wire Wire Line
	4450 4900 4350 4900
Wire Wire Line
	4550 4850 4550 4900
Connection ~ 4550 4900
Wire Wire Line
	4550 4900 4450 4900
Wire Wire Line
	4650 4850 4650 4900
Connection ~ 4650 4900
Wire Wire Line
	4650 4900 4550 4900
Wire Wire Line
	4750 4850 4750 4900
Connection ~ 4750 4900
Wire Wire Line
	4750 4900 4650 4900
Wire Wire Line
	4850 4850 4850 4900
Connection ~ 4850 4900
Wire Wire Line
	4850 4900 4750 4900
Wire Wire Line
	4950 4850 4950 4900
Connection ~ 4950 4900
Wire Wire Line
	4950 4900 4850 4900
$Comp
L Device:R R1
U 1 1 5FCE96DD
P 5650 2400
F 0 "R1" H 5720 2446 50  0000 L CNN
F 1 "3.9k" H 5720 2355 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5580 2400 50  0001 C CNN
F 3 "~" H 5650 2400 50  0001 C CNN
	1    5650 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FCE9CF2
P 5950 2400
F 0 "R2" H 6020 2446 50  0000 L CNN
F 1 "3.9k" H 6020 2355 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5880 2400 50  0001 C CNN
F 3 "~" H 5950 2400 50  0001 C CNN
	1    5950 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR04
U 1 1 5FCE9F4F
P 5950 2150
F 0 "#PWR04" H 5950 2000 50  0001 C CNN
F 1 "+3V3" H 5965 2323 50  0000 C CNN
F 2 "" H 5950 2150 50  0001 C CNN
F 3 "" H 5950 2150 50  0001 C CNN
	1    5950 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2650 5650 2650
Wire Wire Line
	5650 2650 5650 2550
Wire Wire Line
	5950 2550 5950 2750
Wire Wire Line
	5950 2750 5550 2750
Wire Wire Line
	5650 2250 5650 2200
Wire Wire Line
	5650 2200 5950 2200
Wire Wire Line
	5950 2200 5950 2250
Wire Wire Line
	5950 2150 5950 2200
Connection ~ 5950 2200
Text GLabel 6300 2950 2    50   Output ~ 0
rpi_DDir
Text GLabel 6300 3050 2    50   Output ~ 0
rpi_DOE
Text GLabel 6300 3250 2    50   Output ~ 0
rpi_OE
Text GLabel 6300 3350 2    50   Output ~ 0
rpi_IE
Wire Wire Line
	6300 2950 5550 2950
Wire Wire Line
	5550 3050 6300 3050
Wire Wire Line
	6300 3250 5550 3250
Wire Wire Line
	5550 3350 6300 3350
NoConn ~ 5550 3450
NoConn ~ 5550 3650
Text GLabel 6300 3750 2    50   BiDi ~ 0
rpi_D1
Text GLabel 6300 3850 2    50   BiDi ~ 0
rpi_D2
Text GLabel 6300 3950 2    50   BiDi ~ 0
rpi_D3
Text GLabel 6300 4050 2    50   BiDi ~ 0
rpi_D4
Text GLabel 6300 4250 2    50   BiDi ~ 0
rpi_D5
Text GLabel 3450 2650 0    50   BiDi ~ 0
rpi_D7
Text GLabel 3450 2750 0    50   BiDi ~ 0
rpi_D8
Wire Wire Line
	5550 3750 6300 3750
Wire Wire Line
	6300 3850 5550 3850
Wire Wire Line
	5550 3950 6300 3950
Wire Wire Line
	6300 4050 5550 4050
Wire Wire Line
	5550 4250 6300 4250
Text GLabel 6300 4350 2    50   BiDi ~ 0
rpi_D6
Wire Wire Line
	6300 4350 5550 4350
Wire Wire Line
	3950 2650 3450 2650
Wire Wire Line
	3450 2750 3950 2750
Text GLabel 3450 3150 0    50   Output ~ 0
rpi_PError
Text GLabel 3450 3050 0    50   Output ~ 0
rpi_nSelectIn
Text GLabel 3450 2950 0    50   Output ~ 0
rpi_nFault
Text GLabel 3450 3350 0    50   Output ~ 0
rpi_nAck
Text GLabel 3450 3450 0    50   Output ~ 0
rpi_Busy
Text GLabel 3450 3950 0    50   Input ~ 0
rpi_nStrobe
Text GLabel 3450 4050 0    50   Input ~ 0
rpi_nAutoFd
Text GLabel 3450 4150 0    50   Input ~ 0
rpi_nInit
Text GLabel 3450 4250 0    50   Input ~ 0
rpi_Select
Wire Wire Line
	3450 2950 3950 2950
Wire Wire Line
	3950 3050 3450 3050
Wire Wire Line
	3450 3150 3950 3150
Wire Wire Line
	3950 3350 3450 3350
Wire Wire Line
	3450 3450 3950 3450
Wire Wire Line
	3950 3950 3450 3950
Wire Wire Line
	3450 4050 3950 4050
Wire Wire Line
	3950 4150 3450 4150
Wire Wire Line
	3450 4250 3950 4250
NoConn ~ 3950 3750
NoConn ~ 3950 3850
Text GLabel 3450 3550 0    50   Output ~ 0
rpi_OSCTX
Wire Wire Line
	3950 3550 3450 3550
$Comp
L Mechanical:MountingHole H1
U 1 1 5F70B44B
P 8400 2700
F 0 "H1" H 8500 2746 50  0000 L CNN
F 1 "MountingHole" H 8500 2655 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_2.7mm_M2.5" H 8400 2700 50  0001 C CNN
F 3 "~" H 8400 2700 50  0001 C CNN
	1    8400 2700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5F70B6E4
P 8400 3100
F 0 "H2" H 8500 3146 50  0000 L CNN
F 1 "MountingHole" H 8500 3055 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_2.7mm_M2.5" H 8400 3100 50  0001 C CNN
F 3 "~" H 8400 3100 50  0001 C CNN
	1    8400 3100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5F70B90B
P 8400 3600
F 0 "H3" H 8500 3646 50  0000 L CNN
F 1 "MountingHole" H 8500 3555 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_2.7mm_M2.5" H 8400 3600 50  0001 C CNN
F 3 "~" H 8400 3600 50  0001 C CNN
	1    8400 3600
	1    0    0    -1  
$EndComp
$EndSCHEMATC

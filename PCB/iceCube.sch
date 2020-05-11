EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny85-20PU U1
U 1 1 5E977C42
P 5350 3450
F 0 "U1" H 4821 3496 50  0000 R CNN
F 1 "ATtiny85-20PU" H 4821 3405 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 5350 3450 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 5350 3450 50  0001 C CNN
	1    5350 3450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J3
U 1 1 5E97918F
P 7750 2600
F 0 "J3" H 7722 2574 50  0000 R CNN
F 1 "RTC" H 7722 2483 50  0000 R CNN
F 2 "Module:RTC_Module" H 7750 2600 50  0001 C CNN
F 3 "~" H 7750 2600 50  0001 C CNN
	1    7750 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:R_PHOTO Photo1
U 1 1 5E979D1B
P 8450 3450
F 0 "Photo1" H 8520 3496 50  0000 L CNN
F 1 "R_PHOTO" H 8520 3405 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" V 8500 3200 50  0001 L CNN
F 3 "~" H 8450 3400 50  0001 C CNN
	1    8450 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E97B1D6
P 8450 3900
F 0 "R1" H 8520 3946 50  0000 L CNN
F 1 "75K" H 8520 3855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 8380 3900 50  0001 C CNN
F 3 "~" H 8450 3900 50  0001 C CNN
	1    8450 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 5E97C31A
P 7500 4550
F 0 "D1" H 7500 4766 50  0000 C CNN
F 1 "1N4001" H 7500 4675 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" H 7500 4550 50  0001 C CNN
F 3 "~" H 7500 4550 50  0001 C CNN
	1    7500 4550
	1    0    0    -1  
$EndComp
$Comp
L dc_dc_mini-360:DC_DC_Mini-360 K1
U 1 1 5E9856E4
P 6900 4900
F 0 "K1" H 7230 4946 50  0000 L CNN
F 1 "DC_DC_Mini-360" H 7230 4855 50  0000 L CNN
F 2 "Regulator:DC_DC_Mini-360" H 7250 4850 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 6900 4900 50  0001 C CNN
	1    6900 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0101
U 1 1 5E987243
P 7100 5450
F 0 "#PWR0101" H 7100 5200 50  0001 C CNN
F 1 "GNDD" H 7104 5295 50  0000 C CNN
F 2 "" H 7100 5450 50  0001 C CNN
F 3 "" H 7100 5450 50  0001 C CNN
	1    7100 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0102
U 1 1 5E9889B9
P 5350 4250
F 0 "#PWR0102" H 5350 4000 50  0001 C CNN
F 1 "GNDD" H 5354 4095 50  0000 C CNN
F 2 "" H 5350 4250 50  0001 C CNN
F 3 "" H 5350 4250 50  0001 C CNN
	1    5350 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0103
U 1 1 5E988E07
P 8250 5050
F 0 "#PWR0103" H 8250 4800 50  0001 C CNN
F 1 "GNDD" H 8254 4895 50  0000 C CNN
F 2 "" H 8250 5050 50  0001 C CNN
F 3 "" H 8250 5050 50  0001 C CNN
	1    8250 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0104
U 1 1 5E9890C2
P 7500 2950
F 0 "#PWR0104" H 7500 2700 50  0001 C CNN
F 1 "GNDD" H 7504 2795 50  0000 C CNN
F 2 "" H 7500 2950 50  0001 C CNN
F 3 "" H 7500 2950 50  0001 C CNN
	1    7500 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0105
U 1 1 5E989124
P 8450 4150
F 0 "#PWR0105" H 8450 3900 50  0001 C CNN
F 1 "GNDD" H 8454 3995 50  0000 C CNN
F 2 "" H 8450 4150 50  0001 C CNN
F 3 "" H 8450 4150 50  0001 C CNN
	1    8450 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 5200 7100 5200
Wire Wire Line
	7100 5450 7100 5200
Connection ~ 7100 5200
Wire Wire Line
	5350 4250 5350 4050
Wire Wire Line
	8450 4050 8450 4150
$Comp
L Connector:Conn_01x02_Male Power1
U 1 1 5E98E87D
P 8450 4850
F 0 "Power1" H 8422 4824 50  0000 R CNN
F 1 "Power" H 8422 4733 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8450 4850 50  0001 C CNN
F 3 "~" H 8450 4850 50  0001 C CNN
	1    8450 4850
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5E992262
P 6700 4450
F 0 "#PWR0106" H 6700 4300 50  0001 C CNN
F 1 "+5V" H 6715 4623 50  0000 C CNN
F 2 "" H 6700 4450 50  0001 C CNN
F 3 "" H 6700 4450 50  0001 C CNN
	1    6700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4600 6700 4450
Wire Wire Line
	7350 4550 7100 4550
Wire Wire Line
	7100 4550 7100 4600
Wire Wire Line
	8250 4950 8250 5050
Wire Wire Line
	8250 4850 7650 4850
Wire Wire Line
	7650 4850 7650 4550
$Comp
L power:GNDD #PWR0107
U 1 1 5E995B63
P 6700 1700
F 0 "#PWR0107" H 6700 1450 50  0001 C CNN
F 1 "GNDD" H 6704 1545 50  0000 C CNN
F 2 "" H 6700 1700 50  0001 C CNN
F 3 "" H 6700 1700 50  0001 C CNN
	1    6700 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5E9988D6
P 8450 3250
F 0 "#PWR0109" H 8450 3100 50  0001 C CNN
F 1 "+5V" H 8465 3423 50  0000 C CNN
F 2 "" H 8450 3250 50  0001 C CNN
F 3 "" H 8450 3250 50  0001 C CNN
	1    8450 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5E998A30
P 6250 2250
F 0 "#PWR0110" H 6250 2100 50  0001 C CNN
F 1 "+5V" H 6265 2423 50  0000 C CNN
F 2 "" H 6250 2250 50  0001 C CNN
F 3 "" H 6250 2250 50  0001 C CNN
	1    6250 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 3300 8450 3250
$Comp
L Connector:Conn_01x03_Male LEDRing1
U 1 1 5E99B11F
P 6750 2400
F 0 "LEDRing1" H 6722 2424 50  0000 R CNN
F 1 "LEDs" H 6722 2333 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6750 2400 50  0001 C CNN
F 3 "~" H 6750 2400 50  0001 C CNN
	1    6750 2400
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0111
U 1 1 5E99D41C
P 6250 2750
F 0 "#PWR0111" H 6250 2500 50  0001 C CNN
F 1 "GNDD" H 6254 2595 50  0000 C CNN
F 2 "" H 6250 2750 50  0001 C CNN
F 3 "" H 6250 2750 50  0001 C CNN
	1    6250 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 3600 8450 3650
Wire Wire Line
	5950 3450 7300 3450
Wire Wire Line
	7300 3450 7300 3650
Wire Wire Line
	7300 3650 8450 3650
Connection ~ 8450 3650
Wire Wire Line
	8450 3650 8450 3750
Wire Wire Line
	6550 2400 6250 2400
Wire Wire Line
	6250 2400 6250 2250
Wire Wire Line
	6550 2300 6450 2300
Wire Wire Line
	7550 2800 7550 2950
Wire Wire Line
	7550 2950 7500 2950
$Comp
L power:+5V #PWR0112
U 1 1 5E9AE7A9
P 7350 2200
F 0 "#PWR0112" H 7350 2050 50  0001 C CNN
F 1 "+5V" H 7365 2373 50  0000 C CNN
F 2 "" H 7350 2200 50  0001 C CNN
F 3 "" H 7350 2200 50  0001 C CNN
	1    7350 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2200 7350 2700
Wire Wire Line
	7350 2700 7550 2700
Wire Wire Line
	7550 2600 6900 2600
Wire Wire Line
	6900 2600 6900 3150
Wire Wire Line
	7550 2500 7150 2500
Wire Wire Line
	7150 2500 7150 3350
Wire Wire Line
	7150 3350 5950 3350
Wire Wire Line
	5950 3150 6900 3150
$Comp
L Switch:SW_Push SW1
U 1 1 5E9CED00
P 6400 1600
F 0 "SW1" H 6400 1885 50  0000 C CNN
F 1 "SW_Push" H 6400 1794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6400 1800 50  0001 C CNN
F 3 "~" H 6400 1800 50  0001 C CNN
	1    6400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1600 6700 1600
Wire Wire Line
	6700 1600 6700 1700
Wire Wire Line
	6200 1600 6100 1600
Wire Wire Line
	6100 3250 5950 3250
$Comp
L Device:CP C1
U 1 1 5E9DA904
P 4900 2450
F 0 "C1" H 5018 2496 50  0000 L CNN
F 1 "10uF" H 5018 2405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4938 2300 50  0001 C CNN
F 3 "~" H 4900 2450 50  0001 C CNN
	1    4900 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5E998455
P 5350 2250
F 0 "#PWR0108" H 5350 2100 50  0001 C CNN
F 1 "+5V" H 5365 2423 50  0000 C CNN
F 2 "" H 5350 2250 50  0001 C CNN
F 3 "" H 5350 2250 50  0001 C CNN
	1    5350 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR01
U 1 1 5E9DCA0A
P 4900 2700
F 0 "#PWR01" H 4900 2450 50  0001 C CNN
F 1 "GNDD" H 4904 2545 50  0000 C CNN
F 2 "" H 4900 2700 50  0001 C CNN
F 3 "" H 4900 2700 50  0001 C CNN
	1    4900 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2250 5350 2300
Wire Wire Line
	4900 2300 5350 2300
Connection ~ 5350 2300
Wire Wire Line
	5350 2300 5350 2850
Wire Wire Line
	4900 2600 4900 2700
$Comp
L Device:CP C2
U 1 1 5E9DF2F5
P 6250 2550
F 0 "C2" H 6368 2596 50  0000 L CNN
F 1 "100uF" H 6368 2505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P5.00mm" H 6288 2400 50  0001 C CNN
F 3 "~" H 6250 2550 50  0001 C CNN
	1    6250 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3550 6450 3550
Connection ~ 6250 2400
Wire Wire Line
	6100 1600 6100 3250
$Comp
L Device:R R2
U 1 1 5E9E376B
P 6450 2900
F 0 "R2" H 6520 2946 50  0000 L CNN
F 1 "300R" H 6520 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6380 2900 50  0001 C CNN
F 3 "~" H 6450 2900 50  0001 C CNN
	1    6450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3550 6450 3050
Wire Wire Line
	6450 2750 6450 2300
Wire Wire Line
	6250 2750 6250 2700
Wire Wire Line
	6250 2700 6550 2700
Wire Wire Line
	6550 2700 6550 2500
Connection ~ 6250 2700
$EndSCHEMATC

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
L Device:R R1
U 1 1 5DF39B55
P 1600 -3150
F 0 "R1" H 1670 -3104 50  0000 L CNN
F 1 "R" H 1670 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1530 -3150 50  0001 C CNN
F 3 "~" H 1600 -3150 50  0001 C CNN
	1    1600 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5DF3A52F
P 2350 -3150
F 0 "R2" H 2420 -3104 50  0000 L CNN
F 1 "R" H 2420 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2280 -3150 50  0001 C CNN
F 3 "~" H 2350 -3150 50  0001 C CNN
	1    2350 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5DF3A64A
P 1600 -2850
F 0 "D1" V 1547 -2772 50  0000 L CNN
F 1 "LED" V 1638 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 1600 -2850 50  0001 C CNN
F 3 "~" H 1600 -2850 50  0001 C CNN
	1    1600 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q1
U 1 1 5DF3D29D
P 2250 -2800
F 0 "Q1" H 2440 -2754 50  0000 L CNN
F 1 "SFH300" H 2440 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2730 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 2250 -2800 50  0001 C CNN
	1    2250 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 -3300 1600 -3300
Wire Wire Line
	2350 -2600 1600 -2600
Wire Wire Line
	1600 -2600 1600 -2700
$Comp
L 74xx:74HC4051 U1
U 1 1 5DF3FCD1
P 6800 -900
F 0 "U1" V 6896 -356 50  0000 L CNN
F 1 "74HC4051" V 6805 -356 50  0000 L CNN
F 2 "Package_SO:SOP-16_4.55x10.3mm_P1.27mm" H 6800 -1300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd74hc4051.pdf" H 6800 -1300 50  0001 C CNN
	1    6800 -900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 -3000 2800 -3000
Connection ~ 2350 -3000
$Comp
L Device:R R3
U 1 1 5DF435BC
P 2950 -3150
F 0 "R3" H 3020 -3104 50  0000 L CNN
F 1 "R" H 3020 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2880 -3150 50  0001 C CNN
F 3 "~" H 2950 -3150 50  0001 C CNN
	1    2950 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5DF435C2
P 3700 -3150
F 0 "R4" H 3770 -3104 50  0000 L CNN
F 1 "R" H 3770 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3630 -3150 50  0001 C CNN
F 3 "~" H 3700 -3150 50  0001 C CNN
	1    3700 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5DF435C8
P 2950 -2850
F 0 "D2" V 2897 -2772 50  0000 L CNN
F 1 "LED" V 2988 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 2950 -2850 50  0001 C CNN
F 3 "~" H 2950 -2850 50  0001 C CNN
	1    2950 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q2
U 1 1 5DF435CE
P 3600 -2800
F 0 "Q2" H 3790 -2754 50  0000 L CNN
F 1 "SFH300" H 3790 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4080 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 3600 -2800 50  0001 C CNN
	1    3600 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 -3300 2950 -3300
Wire Wire Line
	3700 -2600 2950 -2600
Wire Wire Line
	2950 -2600 2950 -2700
Wire Wire Line
	3700 -3000 4150 -3000
Connection ~ 3700 -3000
$Comp
L Device:R R5
U 1 1 5DF44267
P 4350 -3150
F 0 "R5" H 4420 -3104 50  0000 L CNN
F 1 "R" H 4420 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4280 -3150 50  0001 C CNN
F 3 "~" H 4350 -3150 50  0001 C CNN
	1    4350 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5DF4426D
P 5100 -3150
F 0 "R6" H 5170 -3104 50  0000 L CNN
F 1 "R" H 5170 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5030 -3150 50  0001 C CNN
F 3 "~" H 5100 -3150 50  0001 C CNN
	1    5100 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5DF44273
P 4350 -2850
F 0 "D3" V 4297 -2772 50  0000 L CNN
F 1 "LED" V 4388 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 4350 -2850 50  0001 C CNN
F 3 "~" H 4350 -2850 50  0001 C CNN
	1    4350 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q3
U 1 1 5DF44279
P 5000 -2800
F 0 "Q3" H 5190 -2754 50  0000 L CNN
F 1 "SFH300" H 5190 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5480 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 5000 -2800 50  0001 C CNN
	1    5000 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 -3300 4750 -3300
Wire Wire Line
	5100 -2600 4350 -2600
Wire Wire Line
	4350 -2600 4350 -2700
Wire Wire Line
	5100 -3000 5550 -3000
Connection ~ 5100 -3000
$Comp
L Device:R R7
U 1 1 5DF459C8
P 5750 -3150
F 0 "R7" H 5820 -3104 50  0000 L CNN
F 1 "R" H 5820 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5680 -3150 50  0001 C CNN
F 3 "~" H 5750 -3150 50  0001 C CNN
	1    5750 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5DF459CE
P 6500 -3150
F 0 "R8" H 6570 -3104 50  0000 L CNN
F 1 "R" H 6570 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6430 -3150 50  0001 C CNN
F 3 "~" H 6500 -3150 50  0001 C CNN
	1    6500 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5DF459D4
P 5750 -2850
F 0 "D4" V 5697 -2772 50  0000 L CNN
F 1 "LED" V 5788 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 5750 -2850 50  0001 C CNN
F 3 "~" H 5750 -2850 50  0001 C CNN
	1    5750 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q4
U 1 1 5DF459DA
P 6400 -2800
F 0 "Q4" H 6590 -2754 50  0000 L CNN
F 1 "SFH300" H 6590 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6880 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 6400 -2800 50  0001 C CNN
	1    6400 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 -3300 5750 -3300
Wire Wire Line
	6500 -2600 5750 -2600
Wire Wire Line
	5750 -2600 5750 -2700
Wire Wire Line
	6500 -3000 6950 -3000
Connection ~ 6500 -3000
$Comp
L Device:R R9
U 1 1 5DF4C762
P 7150 -3150
F 0 "R9" H 7220 -3104 50  0000 L CNN
F 1 "R" H 7220 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7080 -3150 50  0001 C CNN
F 3 "~" H 7150 -3150 50  0001 C CNN
	1    7150 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5DF4C768
P 7900 -3150
F 0 "R10" H 7970 -3104 50  0000 L CNN
F 1 "R" H 7970 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7830 -3150 50  0001 C CNN
F 3 "~" H 7900 -3150 50  0001 C CNN
	1    7900 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5DF4C76E
P 7150 -2850
F 0 "D5" V 7097 -2772 50  0000 L CNN
F 1 "LED" V 7188 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 7150 -2850 50  0001 C CNN
F 3 "~" H 7150 -2850 50  0001 C CNN
	1    7150 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q5
U 1 1 5DF4C774
P 7800 -2800
F 0 "Q5" H 7990 -2754 50  0000 L CNN
F 1 "SFH300" H 7990 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8280 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 7800 -2800 50  0001 C CNN
	1    7800 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 -3300 7400 -3300
Wire Wire Line
	7900 -2600 7150 -2600
Wire Wire Line
	7150 -2600 7150 -2700
Wire Wire Line
	7900 -3000 8350 -3000
Connection ~ 7900 -3000
$Comp
L Device:R R11
U 1 1 5DF4C780
P 8500 -3150
F 0 "R11" H 8570 -3104 50  0000 L CNN
F 1 "R" H 8570 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8430 -3150 50  0001 C CNN
F 3 "~" H 8500 -3150 50  0001 C CNN
	1    8500 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5DF4C786
P 9250 -3150
F 0 "R12" H 9320 -3104 50  0000 L CNN
F 1 "R" H 9320 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9180 -3150 50  0001 C CNN
F 3 "~" H 9250 -3150 50  0001 C CNN
	1    9250 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D6
U 1 1 5DF4C78C
P 8500 -2850
F 0 "D6" V 8447 -2772 50  0000 L CNN
F 1 "LED" V 8538 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 8500 -2850 50  0001 C CNN
F 3 "~" H 8500 -2850 50  0001 C CNN
	1    8500 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q6
U 1 1 5DF4C792
P 9150 -2800
F 0 "Q6" H 9340 -2754 50  0000 L CNN
F 1 "SFH300" H 9340 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9630 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 9150 -2800 50  0001 C CNN
	1    9150 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 -3300 8500 -3300
Wire Wire Line
	9250 -2600 8500 -2600
Wire Wire Line
	8500 -2600 8500 -2700
Wire Wire Line
	9250 -3000 9700 -3000
Connection ~ 9250 -3000
$Comp
L Device:R R13
U 1 1 5DF4C79D
P 9900 -3150
F 0 "R13" H 9970 -3104 50  0000 L CNN
F 1 "R" H 9970 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9830 -3150 50  0001 C CNN
F 3 "~" H 9900 -3150 50  0001 C CNN
	1    9900 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 5DF4C7A3
P 10650 -3150
F 0 "R14" H 10720 -3104 50  0000 L CNN
F 1 "R" H 10720 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10580 -3150 50  0001 C CNN
F 3 "~" H 10650 -3150 50  0001 C CNN
	1    10650 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D7
U 1 1 5DF4C7A9
P 9900 -2850
F 0 "D7" V 9847 -2772 50  0000 L CNN
F 1 "LED" V 9938 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 9900 -2850 50  0001 C CNN
F 3 "~" H 9900 -2850 50  0001 C CNN
	1    9900 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q7
U 1 1 5DF4C7AF
P 10550 -2800
F 0 "Q7" H 10740 -2754 50  0000 L CNN
F 1 "SFH300" H 10740 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 11030 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 10550 -2800 50  0001 C CNN
	1    10550 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 -3300 9900 -3300
Wire Wire Line
	10650 -2600 9900 -2600
Wire Wire Line
	9900 -2600 9900 -2700
Wire Wire Line
	10650 -3000 11100 -3000
Connection ~ 10650 -3000
$Comp
L Device:R R15
U 1 1 5DF4C7BA
P 11300 -3150
F 0 "R15" H 11370 -3104 50  0000 L CNN
F 1 "R" H 11370 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11230 -3150 50  0001 C CNN
F 3 "~" H 11300 -3150 50  0001 C CNN
	1    11300 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5DF4C7C0
P 12050 -3150
F 0 "R16" H 12120 -3104 50  0000 L CNN
F 1 "R" H 12120 -3195 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11980 -3150 50  0001 C CNN
F 3 "~" H 12050 -3150 50  0001 C CNN
	1    12050 -3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D8
U 1 1 5DF4C7C6
P 11300 -2850
F 0 "D8" V 11247 -2772 50  0000 L CNN
F 1 "LED" V 11338 -2772 50  0000 L CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" H 11300 -2850 50  0001 C CNN
F 3 "~" H 11300 -2850 50  0001 C CNN
	1    11300 -2850
	0    1    1    0   
$EndComp
$Comp
L Sensor_Optical:SFH300 Q8
U 1 1 5DF4C7CC
P 11950 -2800
F 0 "Q8" H 12140 -2754 50  0000 L CNN
F 1 "SFH300" H 12140 -2845 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 12430 -2940 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 11950 -2800 50  0001 C CNN
	1    11950 -2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	12050 -3300 11300 -3300
Wire Wire Line
	12050 -2600 11300 -2600
Wire Wire Line
	11300 -2600 11300 -2700
Wire Wire Line
	12050 -3000 12500 -3000
Connection ~ 12050 -3000
Wire Wire Line
	6950 -3000 6950 -1950
Wire Wire Line
	6950 -1950 6800 -1950
Wire Wire Line
	6800 -1950 6800 -1300
Wire Wire Line
	6700 -1300 6700 -2200
Wire Wire Line
	6700 -2200 5550 -2200
Wire Wire Line
	5550 -2200 5550 -3000
Wire Wire Line
	6600 -1300 6600 -1850
Wire Wire Line
	6600 -1850 4150 -1850
Wire Wire Line
	4150 -1850 4150 -3000
Wire Wire Line
	6500 -1300 2800 -1300
Wire Wire Line
	2800 -3000 2800 -1300
Wire Wire Line
	2350 -2600 2950 -2600
Connection ~ 2350 -2600
Connection ~ 2950 -2600
Wire Wire Line
	3700 -2600 4350 -2600
Connection ~ 3700 -2600
Connection ~ 4350 -2600
Wire Wire Line
	5100 -2600 5400 -2600
Connection ~ 5100 -2600
Connection ~ 5750 -2600
Wire Wire Line
	6500 -2600 7150 -2600
Connection ~ 6500 -2600
Connection ~ 7150 -2600
Wire Wire Line
	7900 -2600 8500 -2600
Connection ~ 7900 -2600
Connection ~ 8500 -2600
Wire Wire Line
	9250 -2600 9900 -2600
Connection ~ 9250 -2600
Connection ~ 9900 -2600
Wire Wire Line
	10650 -2600 11300 -2600
Connection ~ 10650 -2600
Connection ~ 11300 -2600
Wire Wire Line
	7100 -1500 7100 -1300
Wire Wire Line
	6900 -1300 6900 -1800
Wire Wire Line
	8350 -3000 8350 -1800
Wire Wire Line
	6900 -1800 8350 -1800
Wire Wire Line
	7000 -1300 7000 -1650
Wire Wire Line
	7000 -1650 9700 -1650
Wire Wire Line
	9700 -1650 9700 -3000
Wire Wire Line
	7100 -1500 11100 -1500
Wire Wire Line
	11100 -1500 11100 -3000
Wire Wire Line
	7200 -1300 12500 -1300
Wire Wire Line
	12500 -1300 12500 -3000
Wire Wire Line
	11300 -3300 10650 -3300
Connection ~ 11300 -3300
Connection ~ 10650 -3300
Wire Wire Line
	9900 -3300 9250 -3300
Connection ~ 9900 -3300
Connection ~ 9250 -3300
Wire Wire Line
	8500 -3300 7900 -3300
Connection ~ 8500 -3300
Connection ~ 7900 -3300
Wire Wire Line
	7150 -3300 6500 -3300
Connection ~ 7150 -3300
Connection ~ 6500 -3300
Wire Wire Line
	5750 -3300 5100 -3300
Connection ~ 5750 -3300
Connection ~ 5100 -3300
Wire Wire Line
	4350 -3300 3700 -3300
Connection ~ 4350 -3300
Connection ~ 3700 -3300
Wire Wire Line
	2950 -3300 2350 -3300
Connection ~ 2950 -3300
Connection ~ 2350 -3300
Wire Wire Line
	5400 -2600 5400 -900
Wire Wire Line
	5400 -900 5550 -900
Connection ~ 5400 -2600
Wire Wire Line
	5400 -2600 5750 -2600
Wire Wire Line
	7400 -900 7400 -1000
Wire Wire Line
	7400 -1000 7400 -3300
Connection ~ 7400 -1000
Connection ~ 7400 -3300
Wire Wire Line
	7400 -3300 7150 -3300
$Comp
L Device:R R17
U 1 1 5DFA6CFC
P 7850 -600
F 0 "R17" V 7643 -600 50  0000 C CNN
F 1 "R" V 7734 -600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7780 -600 50  0001 C CNN
F 3 "~" H 7850 -600 50  0001 C CNN
	1    7850 -600
	0    1    1    0   
$EndComp
Wire Wire Line
	7100 -600 7700 -600
Wire Wire Line
	8000 -600 8000 -1000
Wire Wire Line
	8000 -1000 7400 -1000
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 5DFAF937
P 6600 -100
F 0 "J1" V 6662 144 50  0000 L CNN
F 1 "Conn_01x06_Male" V 6753 144 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 6600 -100 50  0001 C CNN
F 3 "~" H 6600 -100 50  0001 C CNN
	1    6600 -100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4750 -3300 4750 -300
Wire Wire Line
	4750 -300 5550 -300
Connection ~ 4750 -3300
Wire Wire Line
	4750 -3300 4350 -3300
Wire Wire Line
	6300 -900 6300 -400
Wire Wire Line
	6300 -400 6500 -400
Wire Wire Line
	6500 -400 6500 -300
Connection ~ 6300 -900
Wire Wire Line
	6500 -450 6600 -450
Wire Wire Line
	6600 -450 6600 -300
Wire Wire Line
	6500 -600 6500 -450
Wire Wire Line
	6700 -600 6700 -300
Wire Wire Line
	6800 -600 6800 -300
Wire Wire Line
	6900 -600 6900 -300
$Comp
L Device:C C1
U 1 1 5DFC55BC
P 5550 -600
F 0 "C1" H 5665 -554 50  0000 L CNN
F 1 "C" H 5665 -645 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5588 -750 50  0001 C CNN
F 3 "~" H 5550 -600 50  0001 C CNN
	1    5550 -600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 -750 5550 -900
Connection ~ 5550 -900
Wire Wire Line
	5550 -900 6300 -900
Wire Wire Line
	5550 -450 5550 -300
Connection ~ 5550 -300
Wire Wire Line
	5550 -300 6400 -300
$EndSCHEMATC

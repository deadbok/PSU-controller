v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 43300 46300 1 90 0 resistor-2.sym
{
T 42950 46700 5 10 0 0 90 0 1
device=RESISTOR
T 43000 46500 5 10 1 1 90 0 1
refdes=R1
T 43300 46300 5 10 1 1 0 0 1
value=5.6k
}
C 43300 43700 1 90 0 resistor-2.sym
{
T 42950 44100 5 10 0 0 90 0 1
device=RESISTOR
T 43000 43900 5 10 1 1 90 0 1
refdes=R2
T 43300 43700 5 10 1 1 0 0 1
value=100
}
C 43300 45000 1 90 0 resistor-variable-2.sym
{
T 42900 45550 5 10 1 1 90 0 1
refdes=R3
T 42400 45800 5 10 0 1 90 0 1
device=VARIABLE_RESISTOR
T 43300 45000 5 10 1 1 0 0 1
value=10k
}
C 43100 43200 1 0 0 gnd-1.sym
C 43100 48400 1 270 0 terminal-1.sym
{
T 43850 48090 5 10 0 0 270 0 1
device=terminal
T 43700 48090 5 10 0 0 270 0 1
footprint=CONNECTOR 1 1
T 43150 48150 5 10 1 1 270 6 1
refdes=T1
}
N 43200 47500 43200 47200 4
N 43200 46300 43200 45900 4
N 43200 45000 43200 44600 4
N 42700 45500 42600 45500 4
N 42600 45500 42600 44900 4
N 42600 44900 43200 44900 4
T 43700 45700 9 10 1 0 0 0 1
To PIC16F887 pin RA3
T 50100 40700 9 10 1 0 0 0 1
Voltage sense
T 50600 40100 9 10 1 0 0 0 1
1
T 51900 40100 9 10 1 0 0 0 1
1
T 54000 40400 9 10 1 0 0 0 1
1
T 53900 40100 9 10 1 0 0 0 1
deadbok
C 44800 46100 1 180 0 terminal-1.sym
{
T 44490 45350 5 10 0 0 180 0 1
device=terminal
T 44490 45500 5 10 0 0 180 0 1
footprint=CONNECTOR 1 1
T 44550 46050 5 10 1 1 180 6 1
refdes=T2
}
N 43900 46000 43200 46000 4
C 46900 46300 1 90 0 resistor-2.sym
{
T 46550 46700 5 10 0 0 90 0 1
device=RESISTOR
T 46600 46500 5 10 1 1 90 0 1
refdes=R4
T 46900 46600 5 10 1 1 0 0 1
value=5.6k
}
C 46900 43700 1 90 0 resistor-2.sym
{
T 46550 44100 5 10 0 0 90 0 1
device=RESISTOR
T 46600 43900 5 10 1 1 90 0 1
refdes=R5
T 46900 44000 5 10 1 1 0 0 1
value=100
}
C 46900 45000 1 90 0 resistor-variable-2.sym
{
T 46500 45550 5 10 1 1 90 0 1
refdes=R6
T 46000 45800 5 10 0 1 90 0 1
device=VARIABLE_RESISTOR
T 46900 45200 5 10 1 1 0 0 1
value=10k
}
C 46700 43200 1 0 0 gnd-1.sym
C 46700 48400 1 270 0 terminal-1.sym
{
T 47450 48090 5 10 0 0 270 0 1
device=terminal
T 47300 48090 5 10 0 0 270 0 1
footprint=CONNECTOR 1 1
T 46750 48150 5 10 1 1 270 6 1
refdes=T3
}
N 46800 47500 46800 47200 4
N 46800 46300 46800 45900 4
N 46800 45000 46800 44600 4
N 46300 45500 46200 45500 4
N 46200 45500 46200 44900 4
N 46200 44900 46800 44900 4
C 50300 45700 1 180 0 terminal-1.sym
{
T 49990 44950 5 10 0 0 180 0 1
device=terminal
T 49990 45100 5 10 0 0 180 0 1
footprint=CONNECTOR 1 1
T 50050 45650 5 10 1 1 180 6 1
refdes=T4
}
T 49300 45200 9 10 1 0 0 0 1
To PIC16F887 pin RA4
T 43400 47600 9 10 1 0 0 0 1
To positive supply
T 47000 47400 9 10 1 0 0 0 1
To negative supply
C 48100 46100 1 180 1 opamp-2.sym
{
T 48900 45100 5 10 0 0 180 6 1
device=OPAMP
T 48900 45300 5 10 1 1 180 6 1
refdes=U1
T 48900 44900 5 10 0 0 180 6 1
symversion=0.1
}
C 47800 44600 1 0 0 gnd-1.sym
N 49200 45600 49400 45600 4
N 47900 44900 47900 45300 4
N 47900 45300 48100 45300 4
C 47000 45800 1 0 0 resistor-2.sym
{
T 47400 46150 5 10 0 0 0 0 1
device=RESISTOR
T 47200 46100 5 10 1 1 0 0 1
refdes=R7
T 47400 45600 5 10 1 1 0 0 1
value=1k
}
C 48200 46800 1 0 0 resistor-2.sym
{
T 48600 47150 5 10 0 0 0 0 1
device=RESISTOR
T 48400 47100 5 10 1 1 0 0 1
refdes=R8
T 48500 46600 5 10 1 1 0 0 1
value=1k
}
N 47000 45900 46800 45900 4
N 47900 45900 48100 45900 4
N 48200 46900 48000 46900 4
N 48000 46900 48000 45900 4
N 49100 46900 49400 46900 4
N 49400 46900 49400 45600 4
N 43200 43700 43200 43500 4
N 46800 43500 46800 43700 4

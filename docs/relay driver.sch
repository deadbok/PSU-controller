v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 45300 49000 1 0 0 5V-plus-1.sym
C 45400 44600 1 0 0 gnd-1.sym
C 46900 47000 1 0 0 omron-G5V-1-DCx-1.sym
{
T 47000 48200 5 6 0 1 0 0 1
device=OMRON_G2R-24-DC5
T 47200 47700 5 8 0 1 0 1 1
device=OMRON G5V-1
T 47200 47800 5 10 1 1 0 0 1
refdes=K1
}
C 45700 46100 1 90 0 diode-1.sym
{
T 45100 46500 5 10 0 0 90 0 1
device=DIODE
T 45200 46400 5 10 1 1 90 0 1
refdes=D1
}
N 45500 48700 45500 49000 4
N 45500 47500 45500 47000 4
N 45500 46100 45500 44900 4
N 46900 47200 45500 47200 4
N 46900 45500 46900 47100 4
N 46900 45500 45500 45500 4
C 43200 48000 1 0 0 resistor-2.sym
{
T 43600 48350 5 10 0 0 0 0 1
device=RESISTOR
T 43400 48300 5 10 1 1 0 0 1
refdes=R1
T 43400 47800 5 10 1 1 0 0 1
value=1k
}
N 44100 48100 44800 48100 4
N 43200 48100 42100 48100 4
T 42000 48300 9 10 1 0 0 0 1
Control input
N 46900 47400 46900 48100 4
N 46900 48100 48400 48100 4
T 47800 47100 9 10 1 0 0 0 1
From PSU
T 47600 48200 9 10 1 0 0 0 1
To output
N 47900 47300 48400 47300 4
T 50200 40900 9 10 1 0 0 0 1
Relay driver
T 50500 40100 9 10 1 0 0 0 1
1
T 52000 40100 9 10 1 0 0 0 1
1
T 53800 40400 9 10 1 0 0 0 1
1
T 53900 40100 9 10 1 0 0 0 1
deadbok
C 44800 47500 1 0 0 BC547-2.sym
{
T 45800 48300 5 8 0 0 0 0 1
device=BC547
T 45800 48100 5 10 1 1 0 0 1
refdes=Q?
T 45800 48000 5 8 0 0 0 0 1
value=BC547
T 45800 48400 5 8 0 0 0 0 1
footprint=TO92
}

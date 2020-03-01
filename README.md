# Simple Quadrature Encoder Parsing

Tested with a Happ 3in trackball, 6 pins (gnd, +5V, and a pair of quadrature outputs per axis).
This logic does lose samples at high speeds, even despite using interrupts vs polling, but works well enough.

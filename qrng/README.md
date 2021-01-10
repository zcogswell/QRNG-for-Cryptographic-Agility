# QRNG
Quantum random number generators.
Currently making calls to IBM Qiskit.

## Prerequisites
Only seems to work inside of Anaconda base.

install qrng library:
`pip install qrng qiskit`

update qrng library:
`pip install qrng -U`

Package `libtestu01-dev` on Debian systems or equivalent for TestU01

## Usage
`make` will generate binaries for testing Qiskit simulators.

Running `src/qrng_sim.py` will constantly refresh `bin/rand.bin` with 32-bit random ints from IBMQ.

IBMQ simulators and remote quantum computers can be selected by creating `conf/ibmq.json` as mentioned in the help message for `qrng_sim.py`.

`qRand`, `qrngEngine.so`, and `qrngSmallCrush` all utilize this as their source of randomness.

## TODO
Currently `test_qrngEngine.sh` must be in the same directory as `qrngEngine.so` and it cannot utilize external functions.

qrngSmallCrush crashes quickly.
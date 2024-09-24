# PeakFQ for Linux

This program is a personal version of PeakFQ for Linux, which was modified from the official [USGS PeakFQ for Windows](https://water.usgs.gov/software/PeakFQ/). Their source code was missing some files and not compilable for Linux. I used the following methods to compile it on Linux:
* [How to install the Intel Fortran Compiler on Linux](https://clawiki.isnew.info/howtos/how_to_install_the_intel_fortran_compiler_on_linux)
* [How to compile PeakFQ on Linux](https://clawiki.isnew.info/howtos/how_to_compile_peakfq_on_linux)

## How to build

First, [install the Intel Fortran Compiler on Linux](https://clawiki.isnew.info/howtos/how_to_install_the_intel_fortran_compiler_on_linux).

Use make:
```bash
git clone https://github.com/HuidaeCho/peakfq-linux.git
cd peakfq-linux
make
```

Or you can directly download the source code and other files, and compile it:
```bash
wget -O compile_peakfq.sh https://clawiki.isnew.info/_export/code/howtos/how_to_compile_peakfq_on_linux?codeblock=0
chmod a+x compile_peakfq.sh
./compile_peakfq.sh
```

## How to use

Copy `pkfqms.wdm` to your input file directory and run `peakfq` from there.

## Disclaimer

This program is my personal work derived from the USGS PeakFQ and I am not responsible or liable for any loss or damage resulting from using it.

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

# copy peakfq to your PATH
```

Or you can directly download the source code and other files, and compile it:
```bash
wget -O compile_peakfq.sh https://clawiki.isnew.info/_export/code/howtos/how_to_compile_peakfq_on_linux?codeblock=0
chmod a+x compile_peakfq.sh
./compile_peakfq.sh
```

## How to use

Copy `pkfqms.wdm` to your input file directory and run `peakfq` from there.

## How to test

```bash
mkdir test
cd test
cp ../pkfqms.wdm .

wget -O NM.INP "https://nwis.waterdata.usgs.gov/nwis/peak?state_cd=nm&group_key=NONE&sitefile_output_format=html_table&column_name=agency_cd&column_name=site_no&column_name=station_nm&set_logscale_y=1&date_format=YYYY-MM-DD&rdb_compression=file&format=hn2&hn2_compression=file&list_of_search_criteria=state_cd"

for i in `grep ^Z NM.INP  | sed 's/ .*//;s/^Z//'`; do
        cat<<EOT > sta$i.psf
I ASCI STA$i.INP
O FILE STA$i.OUT
O DEBUG YES
O ADDITIONAL BOTH
STATION $i
  ANALYZE EMA
EOT
        grep "^.$i " NM.INP > STA$i.INP
        peakfq sta$i.psf
done
```

## Disclaimer

This program is my personal work derived from the USGS PeakFQ and I am not responsible or liable for any loss or damage resulting from using it.

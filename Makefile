FC=ifx
LDFLAGS=-nofor-main

all: peakfq

clean:
	$(RM) *.o EMAUtil/*.o *.mod peakfq

peakfq: \
	main.o \
	EMAUtil/dcdflib1.o \
	EMAUtil/imslfake.o \
	EMAUtil/probfun.o \
	compspecs.o \
	datsys90.o \
	emafit.o \
	emathresh.o \
	j407wc.o \
	j407xe.o \
	ktutil.o \
	peakfq.o \
	pkfqsta.o \
	pkwdm.o \
	qfdprs.o \
	scenmod.o \
	stationdata.o \
	stgaus.o \
	stutil.o \
	tsbufr.o \
	utchar.o \
	utcpgn.o \
	utdate.o \
	utgnrl.o \
	utj407.o \
	utnumb.o \
	utstat.o \
	utwdmd.o \
	utwdmf.o \
	utwdt1.o \
	wdatm1.o \
	wdatm2.o \
	wdatrb.o \
	wdatru.o \
	wdbtch.o \
	wdmchk.o \
	wdmess.o \
	wdmid.o \
	wdoppc90.o \
	wdpeak.o \
	wdtble.o \
	wdtms1.o \
	wdtms2.o
	$(FC) $(LDFLAGS) -o $@ $^

peakfq.o: emathresh.o compspecs.o

pkfqsta.o: scenmod.o

j407xe.o: emathresh.o stationdata.o

j407wc.o: emathresh.o

%.o: %.f90
	$(FC) $(FFLAGS) -c -o $@ $<

%.o: %.for
	$(FC) $(FFLAGS) -c -o $@ $<

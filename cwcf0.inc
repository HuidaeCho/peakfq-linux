C     common for Bulletin-17 computations
      COMMON/ WCFCM0 / MSG,MSL,NOPPOS,NOTRAN,NOSYS,NOEPFC,NOCLIM,
     $                 GSMIN,GSMAX,WEIBA,CLSIZE,
     $           INDX1,INDX2,NINDX,INDXPT,TXPROB,       WSKLAT,BIGLOG,
     $                 EPS1,EPS2,HRECWO,HRECWX,HRECWS,
     $                 RMSDGS,CPAMP1,CPAMP2,CPAMP3,
     $                 SIGLOT, SIGHOT, WCXAUX,IWXMOD
      INTEGER          MSG,MSL,NOPPOS,NOTRAN,NOSYS,NOEPFC,NOCLIM,
     $           INDX1,INDX2,NINDX,INDXPT(MXINT),
     $                                        IWXMOD
      REAL             GSMIN,GSMAX,WEIBA,CLSIZE,
     $                                    TXPROB(MXINT),WSKLAT,BIGLOG,
     $                 EPS1,EPS2,HRECWO,HRECWX,HRECWS,
     $                 RMSDGS,CPAMP1,CPAMP2,CPAMP3,
     $                 SIGLOT, SIGHOT, WCXAUX(2)
C
C MSG    - LOGICAL UNIT NUMBER FOR PRINTED MESSAGES
C MSL    - MESSAGE SCREENING LEVEL   0-4     0=NONE, 4=ALL
C NOPPOS - BYPASS CALC OF PROB-PLOT POSITIONS OF OBSERVED PEAKS
C NOTRAN - BYPASS LOG10 TRANSFORM OF INPUT PEAKS
C NOSYS  - BYPASS CALC OF SYSTEMATIC-RECORD FREQ CURVES
C NOEPFC - BYPASS CALC OF EXPECTED-PROBABILITY FREQ CURVE
C NOCLIM - BYPASS CALC OF CONFIDENCE LIMITS FOR WRC FREQ CURVE
C GSMIN  - GENERALIZED SKEW MINIMUM MAP VALUE
C GSMAX  - GENERALIZED SKEW MAXIMUM MAP VALUE
C WEIBA  - CONST A IN GENERAL WEIBULL PLOT POS (M-A)/(N+1-2*A)
C CLSIZE - CONFIDENCE LIMIT SIZE (ONE SIDED)
C INDX1  - FIRST ROW OF WRC-PEAR-3 TABLES AT WHICH TO CALC FREQ CURVE
C INDX2  - LAST ROW OF WRC-PEAR-3 TABLES AT WHICH TO CALC FREQ CURVE
C NINDX  - NUMBER OF NON-NULL INDEX PTS IN INDXPTS
C INDXPT - DIM(MXINT)- WRC PEARSON III TABLE ROWS FOR CAL CONFID LIMS & EXP PROB
C TXPROB - DIM(MXINT)- WRC TABULAR EXCEEDANCE PROBABILITIES
C WSKLAT - WRC WEIGHTED SKEW LATTICE SIZE                                  *
C BIGLOG - VALUE TO USE FOR LOG(INFINITY) MACHINE DEP. /75/                *
C EPS1   - LOWER LIMIT OF NEAR-ZERO SKEW FOR OUTLIER TEST SEQUENCE         *
C EPS2   - UPPER LIMIT OF NEAR-ZERO SKEW FOR OUTLIER TEST SEQUENCE         *
C HRECWO - HISTORIC RECORD WEIGHT FOR CALC LOW-OUTLIER TEST
C HRECWX - HISTORIC RECORD WEIGHT FOR CALC EXPECT PROB AND CONF LIMS       *
C HRECWS - HISTORIC RECORD WEIGHT FOR CALC WRC WEIGHTED SKEW               *
C RMSDGS - RMS DEFAULT ERROR OF GENERALIZED SKEW  /.55/
C CPAMP1 - COND PROB ADJ MATCH POINT 1 -- LOWER
C CPAMP2 - COND PROB ADJ MATCH POINT 2 -- MIDDLE
C CPAMP3 - COND PROB ADJ MATCH POINT 3 -- UPPER
C WCXAUX(2) - AUXILIARY DATA FOR EXPERIMENTAL RUNS (NOT USED AT PRESENT)
C IWXMOD - INDICATES RUN-TIME MODIFICATIONS OF WRC PARAMS (IF .EQ. 2)

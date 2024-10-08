C     frequency curve tables (computed results)
      COMMON/ WCFCM2 / WRCFC,       EPFC,       CLIML,
     $                 CLIMU,       SYSRFC,
     $                 VAREST
      REAL             WRCFC(MXINT),EPFC(MXINT),CLIML(MXINT),
     $                 CLIMU(MXINT),SYSRFC(MXINT)
      DOUBLE PRECISION VAREST(MXINT)
C
C WRCFC  - WRC FREQ CURVE LOGS
C EPFC   - EXPECTED-PROBABILITY FREQ CURVE LOGS
C CLIML  - CONFIDENCE LIMIT LOWER LOGS
C CLIMU  - CONFIDENCE LIMIT UPPER LOGS
C SYSRFC - SYS RECORD FREQ CURVE LOGS
C VAREST - VARIANCE OF ESTIMATE LOGS

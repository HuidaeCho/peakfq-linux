      MODULE EMAThresh

      PUBLIC ThreshSpec, IntervalSpec, PeakSpec

      TYPE ThreshSpec
        INTEGER :: THRBYR, THREYR, NOBS
        REAL    :: THRLWR, THRUPR, THPP
        CHARACTER*80 :: THRCOM
      END TYPE

      TYPE IntervalSpec
        INTEGER :: INTRVLYR
        REAL    :: INTRVLLWR, INTRVLUPR, INTRVLPP
        CHARACTER*80 :: INTRVLCOM
      END TYPE

      TYPE PeakSpec
        INTEGER :: PKYR
        REAL    :: PKVAL
        CHARACTER*5  :: PKCODE
        CHARACTER*80 :: PKCOM
      END TYPE

      TYPE (ThreshSpec), ALLOCATABLE :: THRESH(:)
      TYPE (IntervalSpec), ALLOCATABLE :: INTERVAL(:)
      TYPE (PeakSpec), ALLOCATABLE :: NEWPKS(:)
      INTEGER NTHRESH, THRDEF, NINTERVAL, NNEWPKS, NOBS
      INTEGER, ALLOCATABLE :: OPKSEQ(:)
      DOUBLE PRECISION, ALLOCATABLE :: QL(:),QU(:),TL(:),TU(:)
      DOUBLE PRECISION, ALLOCATABLE :: Q(:),PET(:),PEX(:),THR(:)
      CHARACTER*4, ALLOCATABLE :: DTYPE(:)

      END


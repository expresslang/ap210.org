EXEC_NAME =prog
XSRCS = _ex_init.x
GENSRCS =  \
  schema_ap210_arm.cxx \
  schema_ap210_arm_1.cxx \
  schema_ap210_arm_2.cxx \
  schema_ap210_arm_3.cxx \
  schema_ap210_arm_4.cxx \
  schema_ap210_arm_5.cxx
CSRCS=rpo.c
SPFX=st
LIBS=-linterp
FLAGS=  
include C:/PROGRA~1/PDTec/ECCO-E~1.2/lib/Makefile.gnu

# $Id: Makefile,v 1.7 1998/11/12 18:51:03 keenan Exp keenan $
# Auth: Michael Keenan
#

AP210 = electronic_assembly_interconnect_and_packaging_design

AP210_ROSE_DICT = $(AP210)_SDAI_DICT.rose

AP210_ROSE      = $(AP210).rose $(AP210_ROSE_DICT)

AP210_EXP       = $(AP210).exp

AP210_WS       = $(AP210).ws

IDF_ROSE_DICT = idf_v2_SDAI_DICT.rose

IDF_ROSE      = idf_v2.rose $(IDF_ROSE_DICT)

IDF_EXP       = idf_v2.exp

CFLAGS	      = -c -Aa -I $(ROSE_INCLUDE)/sdaidis

YACC          = bison

YFLAGS        = -v -d -t

LEX           = flex

LFLAGS        = -i

DEST	      = ../../bin/schemas

EXTHDRS	      =

HDRS	      =

INSTALL	      = cp

LD	      = cc

LDFLAGS	      = 

ROSELIBS      = -L$(ROSE_LIB) -lsdaidis -lrose

LIBS	      =

MAKEFILE      = Makefile

OBJS	      =

DERIVED       = $(IDF_ROSE)

PRINT	      = pr

PROGRAM       = idfsdai

SHELL	      = /usr/bin/sh

SRCS	      =

# Commenting out SYSHDRS lets Solaris and HPUX
# share makefiles created with mkmk.
#SYSHDRS	      = 

# Define RCS suffixes as source to mkmf
SUFFIX = .c,v:s .C,v:s .tab.y:s .yy.l:s

# Define RCS suffixes as source to make
.SUFFIXES: .C,v .h,v .l,v .y,v .brd,v .lib,v

.brd,v.brd:
	$(CO) $(COFLAGS) $<

.lib,v.lib:
	$(CO) $(COFLAGS) $<

.C,v.C:
	$(CO) $(COFLAGS) $<

.h,v.h:
	$(CO) $(COFLAGS) $<

.l,v.l:
	$(CO) $(COFLAGS) $<

.l.o:
	$(LEX) $(LFLAGS) $<
	mv lex.yy.c $*.c
	$(CC) $(CFLAGS) $*.c

.l.c:
	$(LEX) $(LFLAGS) $<
	mv lex.yy.c $*.c

.y,v.y:
	$(CO) $(COFLAGS) $<

.y.o:
	$(YACC) $(YFLAGS) $<
	mv $*.tab.c $*.c
	mv $*.tab.h $*_tab.h
	$(CC) $(CFLAGS) $*.c

.y.c:
	$(YACC) $(YFLAGS) $<
	mv $*.tab.c $*.c
	mv $*.tab.h $*_tab.h

all:		$(AP210_ROSE)

$(IDF_ROSE):	$(IDF_EXP)
		express2sdai_dis $(IDF_EXP)
#		mv IDF_V2_SDAI_DICT.rose  $(IDF_ROSE_DICT)

$(AP210_ROSE):	$(AP210_EXP) $(AP210_WS)
		-rm $(AP210_ROSE)
		expxfront -validate -intermed $(AP210)_EXPX $(AP210_EXP) 
		expfront -rose -ws $(AP210_WS) $(AP210_EXP) 
		gendict_dis $(AP210)_EXPX 

$(DEST):	../../bin
		mkdir $(DEST)

../../bin:;	mkdir ../../bin

clean:;		@rm -f $(OBJS) core

clobber:;	@rm -f $(OBJS) $(PROGRAM) core tags $(IDF_EXP) $(SRCS) $(HDRS) $(DERIVED)

depend:;	@mkmf -f $(MAKEFILE) ROOT=$(ROOT)

echo:;		@echo $(HDRS) $(SRCS)

index:;		@ctags -wx $(HDRS) $(SRCS)

install:	$(IDF_ROSE) $(DEST)  
		@echo Installing $(IDF_ROSE) in $(DEST)
		@if [ $(DEST) != . ]; then \
		($(INSTALL) -f $(IDF_ROSE) $(DEST)); fi

print:;		@$(PRINT) $(HDRS) $(SRCS)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)

update:		$(DEST)/$(IDF_ROSE) $(DEST)  


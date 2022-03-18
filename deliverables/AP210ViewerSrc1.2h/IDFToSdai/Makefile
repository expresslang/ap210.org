# $Id: Makefile,v 1.24 1998/01/20 22:11:41 keenan Exp $ 
# Auth: Michael Keenan 
#

# Testcase design name
DESIGN        = mech

# Makefile defs from $ROSE/etc
include $(ROSE_CONFIG)

CFLAGS	      =  -I$(ROSE_INCLUDE)/sdaidis -I$(ROSE_INCLUDE)

YACC          = bison

YFLAGS        = -v -d -t

LEX           = flex

LFLAGS        = -i

DEST	      = ../../bin

EXTHDRS	      =

HDRS	      = map.h \
		map_tab.h

INSTALL	      = /usr/sbin/install

LD	      = CC 

LDFLAGS	      = 

ROSELIBS      = -L$(ROSE_LIB) -lsdaidis -lrose

LIBS	      =

MAKEFILE      = Makefile

OBJS	      = idfsdai.o \
		map.o \
		map.yy.o

DERIVED       = map.c \
                map.output \
                map.yy.c

PRINT	      = pr

PROGRAM       = idfsdai

SHELL	      = /usr/bin/sh

SRCS	      = idfsdai.c \
		map.y \
		map.yy.l

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
	$(CXX_COMPILE) $*.c

.l.c:
	$(LEX) $(LFLAGS) $<
	mv lex.yy.c $*.c

.y,v.y:
	$(CO) $(COFLAGS) $<

.y.o:
	$(YACC) $(YFLAGS) $<
	mv $*.tab.c $*.c
	mv $*.tab.h $*_tab.h
	$(CXX_COMPILE) $*.c

.y.c:
	$(YACC) $(YFLAGS) $<
	mv $*.tab.c $*.c
	mv $*.tab.h $*.h

all:		$(PROGRAM) mech.brd mech.lib
		@-rm $(DESIGN).stp
		./$(PROGRAM) $(DESIGN)

debug.txt:      $(PROGRAM)
		@-rm $(DESIGN).stp
		./$(PROGRAM) $(DESIGN) >debug.txt

$(PROGRAM):     $(OBJS)
		@echo "Linking $(PROGRAM) ..."
		$(LD) $(LDFLAGS) $(OBJS) $(ROSELIBS) $(LIBS) -o $(PROGRAM)
		@echo "done"

clean:;		@rm -f $(OBJS) core $(DERIVED)

clobber:;	@rm -f $(OBJS) $(PROGRAM) core tags $(DESIGN).* $(SRCS) $(HDRS) $(DERIVED)

depend:;	@mkmf -f $(MAKEFILE) ROOT=$(ROOT)

echo:;		@echo $(HDRS) $(SRCS)

index:;		@ctags -wx $(HDRS) $(SRCS)

$(DEST):;	mkdir $(DEST)

install:	$(PROGRAM) $(DEST)
		@echo Installing $(PROGRAM) in $(DEST)
		@-strip $(PROGRAM)
		@if [ $(DEST) != . ]; then \
		(rm -f $(DEST)/$(PROGRAM); $(INSTALL) -f $(DEST) $(PROGRAM)); fi

print:;		@$(PRINT) $(HDRS) $(SRCS)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)

update:		$(DEST)/$(PROGRAM) $(DEST)
###
map.yy.o: map_tab.h

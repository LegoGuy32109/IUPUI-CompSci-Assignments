#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -D_REENTRANT
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"."
CCC           = $(CXX)
MAKEFILE      = Makefile.shared_exe
DEPENDENCIES  = .depend.$(MAKEFILE)
BTARGETDIR    = ./
BIN           = $(BTARGETDIR)shared_exe$(EXESUFFIX)$(EXEEXT)
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = 
GENFLAGS      = -O
LDLIBS        = -l"my_shared_lib$(LIBSUFFIX)" -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = shared_exe$(OBJEXT)
SRC           = shared_exe.cpp
LINK.cc       = $(LD) $(LDFLAGS)
EXPORTFLAGS   = 
DEPLIBS       = $(foreach lib, my_shared_lib$(LIBSUFFIX) , $(foreach libpath, ., $(wildcard $(libpath)/lib$(lib).a)))

#----------------------------------------------------------------------------
#       Local targets
#----------------------------------------------------------------------------

all: $(BIN)

$(BIN): $(OBJS) $(DEPLIBS)
	@$(TESTDIRSTART) "$(BTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(BTARGETDIR)"
	$(LINK.cc) $(OBJS) $(LDLIBS) $(OUTPUT_OPTION)

generated: $(GENERATED_DIRTY)
	@-:

shared_exe$(OBJEXT): shared_exe.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) shared_exe.cpp

clean:
	-$(RM) $(OBJS)

realclean: clean
	-$(RM) $(BIN)

check-syntax:
	$(COMPILE.cc) $(EXPORTFLAGS) -Wall -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

#----------------------------------------------------------------------------
#       Dependencies
#----------------------------------------------------------------------------


depend:
	-$(MPC_ROOT)/depgen.pl  $(CFLAGS) $(CCFLAGS) $(CPPFLAGS) -f $(DEPENDENCIES) $(SRC) 2> $(NUL)

-include $(DEPENDENCIES)

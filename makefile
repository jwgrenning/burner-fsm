#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Tools and dependencies ----#
COMPONENT_NAME = BurnerControl

#--- Inputs ----#
PROJECT_HOME_DIR = .

SRC_FILES = BurnerControl.c BurnerControl_sm.c BurnerControlActions.c 

TEST_SRC_FILES = AllTests.cpp
TEST_SRC_FILES += BurnerControlTest.cpp
TEST_SRC_FILES += MockBurnerControlActions.cpp

INCLUDE_DIRS =\
  .\
  $(SMC_HOME)/lib/C \
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\

CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default  -Wfatal-errors
CPPUTEST_CXXFLAGS =  -std=c++0x
CPPUTEST_CFLAGS = -std=c99

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


# adding transitive dependency for generated sm headers  
BurnerControlTest.cpp : BurnerControl_sm.h 

SMC=            java -jar $(SMC_HOME)/bin/Smc.jar
SMC_FLAGS=      -c $(TRACE)
RM_F = rm -f

# SMC Rules.

%_sm.h %_sm.c : %.sm
		@echo Generating sm files
		$(SMC) $(SMC_FLAGS) $<

%_sm.dot :      %.sm
		$(SMC) -graph -glevel 1 $<

%_sm.png :      %_sm.dot
		dot -T png -o $@ $<

%_sm.html :     %.sm
		$(SMC) -table $<
		
graph :         $(SM_SOURCES:%.sm=%_sm.dot)

png :           $(SM_SOURCES:%.sm=%_sm.png)

table :         $(SM_SOURCES:%.sm=%_sm.html)

clean : smcclean
smcclean :
		-$(RM_F) $(TARGET)
		-$(RM_F) $(OBJECTS)
		-$(RM_F) *_sm.h
		-$(RM_F) *_sm.c
		-$(RM_F) *_sm.dot
		-$(RM_F) *_sm.png
		-$(RM_F) *_sm.html


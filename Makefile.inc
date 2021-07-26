mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	Walker.o \
	LineTracer.o \
	Scenario.o \
	ScenarioTracer.o \
	RandomWalker.o \
	LineMonitor.o \
	Starter.o \
	SimpleTimer.o \
	Main_Measure.o \
	Bright.o \
	Tail.o\
	ColorMeasure.o\
	Angular.o\
	Arm.o\
	Get_tsk\
	Odometer.o\
	Speedometer.o\
	TAil.o\
	Turn.o\
	Xpounter.o


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit $(mkfile_path)measure

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)unit \
	-I$(mkfile_path)measure 

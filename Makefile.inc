 mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	Drive.o \
	LineTracer.o \
	Scenario.o \
	ScenarioTracer.o \
	RandomWalker.o \
	Starter.o \
	SimpleTimer.o \
	Main_Measure.o \
	Bright.o \
	ColorMeasure.o\
	Angular.o\
	Arm.o\
	Odometer.o\
	Speedmeter.o\
	Tail.o\
	Turn.o\
	Xpointer.o\
	Ypointer.o\
	MotorControl.o\
	PID.o\
	Walker.o\
	VirtualPointer.o\
	VirtualCurve.o\
	Main_Judge.o\
	Bright_Judge.o\
	Turn_Judge.o\
	Distance_Judge.o\
	VirtualStraight.o\
	Section.o


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit $(mkfile_path)measure $(mkfile_path)Judge $(mkfile_path)section

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)unit \
	-I$(mkfile_path)measure \
	-I$(mkfile_path)Judge \
	-I$(mkfile_path)section


mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

LIB_CXXOBJS += MyString.o
BL_CXXOBJS += Bluetooth.o

APPL_COBJS += 

APPL_CXXOBJS += $(LIB_CXXOBJS) $(BL_CXXOBJS)

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# C++ Version API
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

# C++ Version API Extra
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
    $(mkfile_path)Cognition \
		$(mkfile_path)Judgement \
		$(mkfile_path)Operation \
		$(mkfile_path)Library \
		$(mkfile_path)Bluetooth \

# -I$./hoge
INCLUDES += \
    -I$(mkfile_path)Cognition \
		-I$(mkfile_path)Judgement \
		-I$(mkfile_path)Operation \
		-I$(mkfile_path)Library \
		-I$(mkfile_path)Bluetooth \
		
COPTS += -fno-use-cxa-atexit
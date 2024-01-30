###########################################

#build output
BUILD_DIR := build


##########################################

# Cmake command

CMAKE_CMD =
CMAKE_CMD += -B build
CMAKE_CMD += -DCMAKE_TOOLCHAIN_FILE=gcc-arm-none-eabi.cmake


##########################################

# openOCD definition

BINARY = build/BLE_Project.elf

OPENOCD_PATH=
OPENOCD_PATH+=-f interface/stlink.cfg
OPENOCD_PATH+=-f target/stm32f4x.cfg

OPENOCD=openocd
OPENOCD_FLAGS=$(OPENOCD_PATH) -c "program $(BINARY) verify reset exit"

###########################################


.PHONY: all build erase flash

all: build


build:
ifeq (,$(wildcard $(BUILD_DIR)/Makefile))
	cmake $(CMAKE_CMD)
endif
	$(MAKE) -C ${BUILD_DIR} --no-print-directory
	
clean-all:
	rm -rf ${BUILD_DIR}/*

clean:
	$(MAKE) -s -C ${BUILD_DIR} clean

flash: build erase
	$(OPENOCD) $(OPENOCD_FLAGS)

erase:
	openocd $(OPENOCD_PATH) -c "init; reset halt; stm32f2x mass_erase 0; exit"
include config.mk

DEBUG         ?= 1
VERBOSE_BUILD ?= 0

ifeq ($(DEBUG),0)
    COPT_FLGS := -Os -ggdb -flto
    AOPT_FLGS := -ggdb
    GLOBAL_DEFS += -DNDEBUG
else
    COPT_FLGS := -Og -ggdb
    AOPT_FLGS := -gdgb
endif

WARNINGS    := -Wall -Wextra -Wdouble-promotion -Wpointer-arith -Wcast-qual -Wno-missing-field-initializers -Wformat=2 \
               -Wswitch-default -Wswitch-enum -Wcast-align -Wbad-function-cast -Wstrict-overflow=5 -Winline \
               -Wnested-externs -Wshadow -Wunreachable-code

GLOBAL_DEFS += -D$(TARGET_MCU)
CFLAGS      := $(WARNINGS) $(CPU_DEFS) $(GLOBAL_DEFS) -ffunction-sections -fdata-sections -fsingle-precision-constant -ffast-math
LDFLAGS     := -Wl,-Map,$(EXECUTABLE).map,--gc-sections --specs=nano.specs --specs=rdimon.specs -lrdimon

CROSS_COMPILE := arm-none-eabi-
CC      := $(CROSS_COMPILE)gcc
AS      := $(CROSS_COMPILE)as
SIZE    := $(CROSS_COMPILE)size
OBJCOPY := $(CROSS_COMPILE)objcopy
READELF := $(CROSS_COMPILE)readelf
NM      := $(CROSS_COMPILE)nm

CFLAGS += $(COPT_FLGS)
INCLPATHS := $(shell find -L . -type d -exec echo -n "-I{} " \;)
C_SRC  := $(shell find -L . -type f -name '*.c' | grep -v "_template")
C_OBJ  := $(C_SRC:.c=.o)
S_SRC  := $(shell find -L . -type f -name '*.s' | grep -v "_template")
S_OBJ  := $(S_SRC:.s=.o)
LDSCRIPT  := $(shell find -L . -type f -name '*.ld' | head -n 1)
DEPFILES  := $(C_OBJ:.o=.d)

LDFLAGS += -T$(LDSCRIPT)

UNAME := $(shell uname)

ifeq ($(LDSCRIPT),)
  $(error Linker script not found, linking not possible)
endif

.PHONY: all clean

all:showbuildinfo $(EXECUTABLE) qtproject

ifeq ($(VERBOSE_BUILD), 1)
	@echo
	@echo ------------------ Functions ------------------
	@$(READELF) -s $(EXECUTABLE).elf | grep FUNC | sort -k 3,3 -r -n | head -n 5 | awk '{printf " %-36.36s %-8.8s\n", $$8, $$3}'
	@echo ------------------ Variables ------------------
	@$(READELF) -s $(EXECUTABLE).elf | grep OBJECT | sort -k 3,3 -r -n | head -n 5 | awk '{printf " %-36.36s %s\n", $$8, $$3}'
	@echo -----------------------------------------------
endif
	@$(SIZE) $(EXECUTABLE).elf | tail -n 1 | awk '{printf "\nFlash: %8.8s (%.5s%%)\nRAM:   %8.8s (%.5s%%)\n\n", $$1+$$2, 100*($$1+$$2)/($(FLASH_SIZE)), $$2+$$3, 100*($$2+$$3)/($(RAM_SIZE))}'

showbuildinfo:
ifeq ($(VERBOSE_BUILD), 1)
	$(info [__] Building $(EXECUTABLE) ...)
	$(info [__] COPT_FLGS:   "$(COPT_FLGS)")
	$(info [__] AOPT_FLGS:   "$(AOPT_FLGS)")
	$(info [__] CPU_DEFS:    "$(CPU_DEFS)")
	$(info [__] GLOBAL_DEFS: "$(GLOBAL_DEFS)")
endif

qtproject: $(EXECUTABLE)
	@echo [__] Updating project files
	@find -L . -name '*.[chs]' -or -name '*.ld' -or -name '*.mk' -or -name '*.map' -or -name 'Makefile' > $(EXECUTABLE).files
	@find -L . -type d > $(EXECUTABLE).includes
	@touch $(EXECUTABLE).creator
	@echo "/* Automatically detected defines */" > $(EXECUTABLE).config
	@touch $(EXECUTABLE).config
	@echo "" >> $(EXECUTABLE).config;
	@for GLOBAL_DEF in $(GLOBAL_DEFS); do \
		echo $$GLOBAL_DEF | sed "s/-D/#define /;s/=/ /" >> $(EXECUTABLE).config; \
	done

$(EXECUTABLE):$(C_OBJ) $(S_OBJ) $(LDSCRIPT)
	@echo [LD] `basename $(LDSCRIPT)`
	@$(CC) $(CFLAGS) $(LDFLAGS) $(C_OBJ) $(S_OBJ) $(LIBS) -o $@.elf
	@$(OBJCOPY) -Obinary $@.elf $@.bin
	@$(OBJCOPY) -Oihex $@.elf $@.hex

-include $(DEPFILES)

%.o:%.c config.mk
	@echo [CC] `basename $*.c`
	@$(CC) $(CFLAGS) $(INCLPATHS) -c $*.c -o $*.o
ifeq ($(UNAME), Linux)
	@$(CC) -MM $(CFLAGS) $(INCLPATHS) $*.c > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp
endif

%.o:%.s config.mk
	@echo [AS] `basename $*.s`
	@$(AS) $(AOPT_FLGS) -c $*.s -o $*.o

clean:
	@echo Cleaning up ...
	@rm -rf $(EXECUTABLE).elf $(EXECUTABLE).map $(EXECUTABLE).hex $(EXECUTABLE).bin $(C_OBJ) $(S_OBJ) $(DEPFILES)
	@find . -name *.[od] -delete

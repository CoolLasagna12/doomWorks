Q ?= @
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
BUILD_DIR = target
NWLINK = npx --yes -- nwlink@0.0.16
LINK_GC = 1
LTO = 1

define object_for
$(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(1))))
endef

src = $(addprefix src/,\
  main.cpp \
)
src += $(addprefix src/HANDLERS/,\
  graphics_handler.cpp \
  input_handler.cpp \
)
src += $(addprefix src/EADK/,\
  eadk_vars.cpp \
)
src += $(addprefix src/CHARACTERS/,\
  player.cpp \
)
src += $(addprefix src/LIBS/,\
  math.cpp \
)
src += $(addprefix src/RAYCASTING/,\
  raycasting.cpp \
)
src += $(addprefix src/GUI/,\
  menu.cpp \
)

DIRS := $(sort $(dir $(call object_for,$(src))))

CPPFLAGS = -std=c++11 -fno-exceptions
CPPFLAGS += -Os -Wall
CPPFLAGS += $(shell $(NWLINK) eadk-cflags)
CPPFLAGS += -D__RODATA_EADK_API_LEVEL__=\"1.0\" -D__RODATA_EADK_APP_NAME__=\"doomWorks\"
CPPFLAGS += -lm
LDFLAGS = -Wl,--relocatable
LDFLAGS += -nostartfiles
LDFLAGS += --specs=nano.specs
LDFLAGS += -lm

ifeq ($(LINK_GC),1)
CPPFLAGS += -fdata-sections -ffunction-sections
LDFLAGS += -Wl,-e,main -Wl,-u,eadk_app_name -Wl,-u,eadk_app_icon -Wl,-u,eadk_api_level
LDFLAGS += -Wl,--gc-sections
endif

ifeq ($(LTO),1)
CPPFLAGS += -flto -fno-fat-lto-objects
CPPFLAGS += -fwhole-program
CPPFLAGS += -fvisibility=internal
LDFLAGS += -flinker-output=nolto-rel
endif

.PHONY: build
build: $(BUILD_DIR)/doomWorks.bin

.PHONY: run
run: $(BUILD_DIR)/doomWorks.nwa
	@echo "INSTALL $<"
	$(Q) $(NWLINK) install-nwa $<

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.nwa
	@echo "BIN     $@"
	$(Q) $(NWLINK) nwa-bin $< $@

$(BUILD_DIR)/doomWorks.nwa: $(call object_for,$(src)) $(BUILD_DIR)/icon.o
	@echo "LD      $@"
	$(Q) $(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

$(addprefix $(BUILD_DIR)/,%.o): %.cpp | $(DIRS)
	@echo "CXX     $^"
	$(Q) $(CXX) -c $^ -o $@ $(CPPFLAGS) $(SFLAGS)

$(BUILD_DIR)/icon.o: src/icon.png
	@echo "ICON    $<"
	$(Q) $(NWLINK) png-icon-o $< $@

.PRECIOUS: $(BUILD_DIR) $(DIRS)
$(DIRS):
	$(Q) mkdir -p $@

.PHONY: clean
clean:
	@echo "CLEAN"
	$(Q) rm -rf $(BUILD_DIR)
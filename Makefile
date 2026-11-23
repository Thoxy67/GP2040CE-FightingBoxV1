# GP2040-CE FightingBox V1 build
#
#   make                                   build against GP2040-CE main (cloned into build/)
#   make GP2040_REF=v0.7.12                build against a specific tag / branch / commit
#   make GP2040_DIR=~/GP2040-CE            build against an existing local checkout (never pulled or modified)
#   make PICO_SDK_PATH=~/pico-sdk          use an existing pico-sdk instead of cloning one
#   make clean                             remove build/
#
# Output: build/out/GP2040-CE_<version>_FightingBoxV1.uf2

BOARD          := FightingBoxV1
REPO_PATH      := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR      := $(REPO_PATH)/build
BOARD_SRC      := $(REPO_PATH)/configs/$(BOARD)

GP2040_REPO    ?= https://github.com/OpenStickCommunity/GP2040-CE.git
GP2040_REF     ?= main
GP2040_DIR     ?= $(BUILD_DIR)/GP2040-CE

PICO_SDK_REPO  ?= https://github.com/raspberrypi/pico-sdk.git
PICO_SDK_PATH  ?= $(BUILD_DIR)/pico-sdk
# Default: the exact SDK version GP2040-CE declares in its CMakeLists.txt (evaluated lazily,
# after GP2040-CE has been checked out)
PICO_SDK_REF   ?= $(shell sed -n 's/^set(sdkVersion \([0-9.]*\))/\1/p' "$(GP2040_DIR)/CMakeLists.txt" 2>/dev/null)

CMAKE_DIR      := $(BUILD_DIR)/cmake
OUT_DIR        := $(BUILD_DIR)/out
BOARD_DST      := $(GP2040_DIR)/configs/$(BOARD)
MARKER         := .fightingbox-temp

# Only clone/update repos that live inside build/ (never touch a user-provided checkout)
MANAGED_GP2040 := $(filter $(BUILD_DIR)/%,$(abspath $(GP2040_DIR)))
MANAGED_SDK    := $(filter $(BUILD_DIR)/%,$(abspath $(PICO_SDK_PATH)))

NPROC          := $(shell nproc 2>/dev/null || echo 4)
CMAKE_ARGS     ?=

.PHONY: all build gp2040 pico-sdk board configure compile collect cleanup clean help
.NOTPARALLEL:

all: build

# Run each step in order; always remove the temporary board dir from GP2040-CE, even on failure
build:
	@$(MAKE) --no-print-directory gp2040 pico-sdk board compile collect; \
		status=$$?; $(MAKE) --no-print-directory cleanup; exit $$status

gp2040:
ifneq ($(MANAGED_GP2040),)
	@echo ">> GP2040-CE $(GP2040_REF)"
	@if [ ! -d "$(GP2040_DIR)/.git" ]; then git clone $(GP2040_REPO) "$(GP2040_DIR)"; fi
	git -C "$(GP2040_DIR)" fetch --tags --force origin
	git -C "$(GP2040_DIR)" -c advice.detachedHead=false checkout -q $(GP2040_REF)
	@if git -C "$(GP2040_DIR)" symbolic-ref -q HEAD >/dev/null; then \
		git -C "$(GP2040_DIR)" merge --ff-only -q origin/$(GP2040_REF); \
	fi
	git -C "$(GP2040_DIR)" submodule update --init
else
	@echo ">> Using existing GP2040-CE at $(GP2040_DIR)"
endif
	@echo ">> GP2040-CE $$(git -C "$(GP2040_DIR)" describe --tags --always)"

pico-sdk:
ifneq ($(MANAGED_SDK),)
	@test -n "$(PICO_SDK_REF)" || { echo "error: could not detect pico-sdk version; pass PICO_SDK_REF=x.y.z"; exit 1; }
	@echo ">> pico-sdk $(PICO_SDK_REF)"
	@if [ ! -d "$(PICO_SDK_PATH)/.git" ]; then \
		git -c advice.detachedHead=false clone --depth 1 --branch $(PICO_SDK_REF) $(PICO_SDK_REPO) "$(PICO_SDK_PATH)"; \
	elif [ "$$(git -C "$(PICO_SDK_PATH)" describe --tags --exact-match 2>/dev/null)" != "$(PICO_SDK_REF)" ]; then \
		git -C "$(PICO_SDK_PATH)" fetch --depth 1 origin tag $(PICO_SDK_REF) && \
		git -C "$(PICO_SDK_PATH)" -c advice.detachedHead=false checkout -q $(PICO_SDK_REF); \
	fi
	git -C "$(PICO_SDK_PATH)" submodule update --init
else
	@echo ">> Using existing pico-sdk at $(PICO_SDK_PATH)"
endif

board:
	@echo ">> Installing board config $(BOARD)"
	@if [ -e "$(BOARD_DST)" ] && [ ! -e "$(BOARD_DST)/$(MARKER)" ]; then \
		echo "error: $(BOARD_DST) already exists and was not created by this Makefile"; exit 1; \
	fi
	rm -rf "$(BOARD_DST)"
	cp -r "$(BOARD_SRC)" "$(BOARD_DST)"
	touch "$(BOARD_DST)/$(MARKER)"

configure:
	PICO_SDK_PATH="$(PICO_SDK_PATH)" cmake -S "$(GP2040_DIR)" -B "$(CMAKE_DIR)" \
		-DGP2040_BOARDCONFIG=$(BOARD) -DCMAKE_BUILD_TYPE=Release $(CMAKE_ARGS)

compile: configure
	GP2040_BOARDCONFIG=$(BOARD) cmake --build "$(CMAKE_DIR)" --parallel $(NPROC)

collect:
	@mkdir -p "$(OUT_DIR)"
	@rm -f "$(OUT_DIR)"/*.uf2
	@cp "$(CMAKE_DIR)"/GP2040-CE_*_$(BOARD).uf2 "$(OUT_DIR)/"
	@echo ">> Firmware: $$(ls "$(OUT_DIR)"/*.uf2)"

cleanup:
	@if [ -e "$(BOARD_DST)/$(MARKER)" ]; then rm -rf "$(BOARD_DST)"; fi

clean: cleanup
	rm -rf "$(BUILD_DIR)"

help:
	@sed -n '3,10p' $(firstword $(MAKEFILE_LIST)) | sed 's/^# \{0,1\}//'

# GP2040-CE FightingBoxV1 Build Makefile

# Variables
REPO_PATH := $(shell pwd)
BUILD_DIR := $(REPO_PATH)/build
PICO_SDK_DIR := $(BUILD_DIR)/pico-sdk
GP2040_DIR := $(BUILD_DIR)/GP2040-CE
CMAKE_DIR := $(BUILD_DIR)/cmake
BOARD_CONFIG := FightingBoxV1
CONFIG_DIR := $(GP2040_DIR)/configs/$(BOARD_CONFIG)
NPROC := $(shell nproc)

# Default target
.PHONY: all
all: build

# Main build target
.PHONY: build
build: setup-dirs setup-pico-sdk setup-gp2040 configure-board cmake-build cleanup

# Setup build directories
.PHONY: setup-dirs
setup-dirs:
	@echo "Setting up build directories..."
	mkdir -p $(BUILD_DIR)

# Setup or update pico-sdk
.PHONY: setup-pico-sdk
setup-pico-sdk: setup-dirs
	@echo "Setting up pico-sdk..."
	cd $(BUILD_DIR) && \
	if [ -d "pico-sdk" ]; then \
		echo "pico-sdk already exists, updating..."; \
		cd pico-sdk && \
		git pull origin master && \
		git submodule update --init; \
	else \
		git clone https://github.com/raspberrypi/pico-sdk.git --branch master && \
		cd pico-sdk && \
		git submodule update --init; \
	fi
	@echo "Applying mbedtls workaround..."
	cd $(PICO_SDK_DIR)/lib/mbedtls && git checkout mbedtls-2.28.10

# Setup or update GP2040-CE
.PHONY: setup-gp2040
setup-gp2040: setup-dirs
	@echo "Setting up GP2040-CE..."
	cd $(BUILD_DIR) && \
	if [ -d "GP2040-CE" ]; then \
		echo "GP2040-CE already exists, updating..."; \
		cd $(GP2040_DIR) && \
		git pull origin main && \
		git submodule update --init; \
	else \
		git clone https://github.com/OpenStickCommunity/GP2040-CE.git && \
		cd $(GP2040_DIR) && \
		git submodule update --init; \
	fi

# Configure board configuration
.PHONY: configure-board
configure-board: setup-gp2040
	@echo "Configuring board $(BOARD_CONFIG)..."
	mkdir -p $(CONFIG_DIR)
	cp $(REPO_PATH)/BoardConfig.h $(CONFIG_DIR)/

# CMake configuration and build
.PHONY: cmake-build
cmake-build: configure-board
	@echo "Running CMake and build..."
	mkdir -p $(CMAKE_DIR)
	cd $(CMAKE_DIR) && \
	PICO_SDK_PATH=$(PICO_SDK_DIR) cmake $(GP2040_DIR) -DGP2040_BOARDCONFIG=$(BOARD_CONFIG) && \
	$(MAKE) -j$(NPROC)

# Cleanup temporary files
.PHONY: cleanup
cleanup:
	@echo "Cleaning up temporary files..."
	rm -rf $(CONFIG_DIR)

# Clean build directory
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# Show help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all       - Build the project (default)"
	@echo "  build     - Build the project"
	@echo "  clean     - Remove build directory"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Individual targets:"
	@echo "  setup-dirs      - Create build directories"
	@echo "  setup-pico-sdk  - Setup/update pico-sdk"
	@echo "  setup-gp2040    - Setup/update GP2040-CE"
	@echo "  configure-board - Configure board settings"
	@echo "  cmake-build     - Run CMake and build"
	@echo "  cleanup         - Remove temporary config files"

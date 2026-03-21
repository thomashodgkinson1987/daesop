CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Isrc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data
DIST_DIR = dist

# Extract version from config.h
VERSION = $(shell grep 'DAESOP_VERSION "' $(SRC_DIR)/config.h | cut -d'"' -f2)
PACKAGE_NAME = daesop-$(VERSION)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = daesop

.PHONY: all build clean package release

all: build

build: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR) $(DIST_DIR):
	mkdir -p $@

package: build | $(DIST_DIR)
	cp $(BIN_DIR)/$(TARGET) $(DIST_DIR)/
	cp $(DATA_DIR)/bytecode.def $(DIST_DIR)/

release: build | $(DIST_DIR)
	rm -rf $(DIST_DIR)/$(PACKAGE_NAME)
	mkdir -p $(DIST_DIR)/$(PACKAGE_NAME)
	cp $(BIN_DIR)/$(TARGET) $(DIST_DIR)/$(PACKAGE_NAME)/
	cp $(DATA_DIR)/bytecode.def $(DIST_DIR)/$(PACKAGE_NAME)/
	tar -czf $(DIST_DIR)/$(PACKAGE_NAME).tar.gz -C $(DIST_DIR) $(PACKAGE_NAME)
	rm -rf $(DIST_DIR)/$(PACKAGE_NAME)
	@echo "Created $(DIST_DIR)/$(PACKAGE_NAME).tar.gz"

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(DIST_DIR)

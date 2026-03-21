CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Isrc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DIST_DIR = dist

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = daesop

DATA_DIR = data

.PHONY: all build clean package

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

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(DIST_DIR)

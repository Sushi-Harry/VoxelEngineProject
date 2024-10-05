# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := build

# Libraries
LIBS := -lglfw -lGLEW -lGL -lm -ldl -lpthread

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET := $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo "Build complete: $(TARGET)"

# Compiling source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and binary files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned up."

.PHONY: all clean

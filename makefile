CC := g++
CFLAGS := -Wall
SRCDIR := src
OBJDIR := obj
BINDIR := .

# Recursively find all source files
SOURCES := $(shell find $(SRCDIR) -type f -name '*.cpp')
# Create corresponding object file names
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
# The name of the final binary file
TARGET := $(BINDIR)/main

# Default target to build the binary
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

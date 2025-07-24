# Makefile for cross-compilation using Mingw-w64 on WSL 2
CXX := g++
CXXFLAGS := -std=c++11 -Wall -g -static-libgcc -static-libstdc++
LDFLAGS := -lpthread

SRCS := main.cpp Warrior.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := Dungeon-Smash.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)


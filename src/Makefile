# Compiler type
CXX = g++
CXXFLAGS = -std=c++11 -Wall
# Output executable name
TARGET = main
# All files with .cpp file extension 
SRCS = $(wildcard *.cpp)
# All files with .o file extension 
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

# Make the executable
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule: compile each .cpp file into a .o object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Remove all compiled object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
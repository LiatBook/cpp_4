# # Compiler to use
# CXX = g++

# # Compiler flags
# CXXFLAGS = -std=c++11 -Wall -Wextra

# # Name of the executable
# TARGET = demo

# # Source files
# SRCS = Demo.cpp

# # Object files
# OBJS = $(SRCS:.cpp=.o)

# SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system  

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(SFML_FLAGS) -o $(TARGET) $(OBJS)

# .cpp.o:
# 	$(CXX) $(CXXFLAGS) -c $<  -o $@

# clean:
# 	$(RM) $(OBJS) $(TARGET) Test.o TestCounter.o 

CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) 

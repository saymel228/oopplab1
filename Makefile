CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -finput-charset=UTF-8 -fexec-charset=UTF-8
SRC = main.cpp safe_array.cpp matrix_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = oopplab1.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
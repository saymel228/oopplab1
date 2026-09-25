CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
SRC = main.cpp safe_array.cpp matrix_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = oopplab1

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
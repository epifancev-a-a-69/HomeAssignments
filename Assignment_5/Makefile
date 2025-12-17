PROJECT = matrix
CXX = g++
CXXFLAGS = -lgtest -lgtest_main -pthread -Werror -Wpedantic -Wall -Wextra
SRC = rational.cpp test_matrix.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)

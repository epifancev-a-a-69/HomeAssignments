PROJECT = testy
CXX = g++
CXXFLAGS = -lgtest -lgtest_main -pthread -Wall -Wextra
SRC = Engine.cpp Weapon.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Dinobot.cpp test_autobot.cpp test_decepticon.cpp test_dinobot.cpp test_virtualmethods.cpp		
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)

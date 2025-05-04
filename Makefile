#dael12345@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRC = SquareMat.cpp
HDR = SquareMat.hpp
TEST = test_SquareMat.cpp
MAIN = Main.cpp

TARGET_MAIN = Main.out
TARGET_TEST = test.out

all: Main

Main: $(SRC) $(HDR) $(MAIN)
	$(CXX) $(CXXFLAGS) $(SRC) $(MAIN) -o $(TARGET_MAIN)

test: $(SRC) $(HDR) $(TEST)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -o $(TARGET_TEST)

valgrind: test
	valgrind --leak-check=full ./$(TARGET_TEST)

clean:
	rm -f $(TARGET_MAIN) $(TARGET_TEST)

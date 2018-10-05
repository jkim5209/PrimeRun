CXX = g++
CXXFLAGS = -std=c++17 -pedantic-errors -lprimesieve -Wall -o3

build: CountingFunctions.o main.cpp
	$(CXX) $(CXXFLAGS) $^ -o main.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rfv *.o *.exe

CXX=g++
CXXFLAGS=-std=c++11

all: proj_4 

debug: CXXFLAGS += -g
debug: proj_4

proj_4.o: proj_4.cpp
	$(CXX) $(CXXFLAGS) -c proj_4.cpp

hash_table.o: hash_table.cpp
	$(CXX) $(CXXFLAGS) -c hash_table.cpp

binary_tree.o: binary_tree.cpp
	$(CXX) $(CXXFLAGS) -c binary_tree.cpp

proj_4: proj_4.o
	$(CXX) $(CXXFLAGS) proj_4.o -o proj_4

clean:
	rm -f *.o proj_4

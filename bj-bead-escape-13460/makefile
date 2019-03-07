OBJECTS = main.o
SRC = bj-bead-escape-13460.cpp

CXXFLAGS = -std=c++11
TARGET = a.out

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

clear :
	$(RM) $(OBJECTS) $(TARGET) core

main.o : bj-bead-escape-13460.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ bj-bead-escape-13460.cpp

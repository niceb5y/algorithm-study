CXX       = clang++
CXXFLAGS   = -W -Wall -std=c++17

main.out: main.cpp
	@$(CXX) $(CXXFLAGS) -o main.out main.cpp

.PHONY: clean
clean:
	@rm -f ./main.out ./output

.PHONY: test
test:
	@./main.out < input > output
	@diff output answer
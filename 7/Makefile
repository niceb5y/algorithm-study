CXX       = clang++
CXXFLAGS   = -W -Wall -std=c++17

main.out: main.cpp
	@$(CXX) $(CXXFLAGS) -o ./main.out ./main.cpp

.PHONY: clean
clean:
	@rm -f ./main.out ./test/*.output

.PHONY: test
test:
	@./main.out < ./test/1.input > ./test/1.output
	@diff ./test/1.output ./test/1.answer

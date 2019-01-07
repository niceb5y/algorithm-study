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
	@./main.out < ./test/2.input > ./test/2.output
	@diff ./test/2.output ./test/2.answer
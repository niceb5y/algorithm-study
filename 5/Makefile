CXX       = clang++
CXXFLAGS   = -W -Wall -std=c++17

main.out: main.cpp
	@$(CXX) $(CXXFLAGS) -o ./main.out ./main.cpp

.PHONY: clean
clean:
	@rm -f ./main.out ./test/*.output

.PHONY: test
test:
	@for answer in ./test/*.answer; do \
		output=$${answer/"answer"/"output"}; \
		input=$${answer/"answer"/"input"}; \
		if [ -f $$input ]; then \
			./main.out < $$input > $$output; \
		else \
			./main.out > $$output; \
		fi; \
		diff $$output $$answer; \
	done

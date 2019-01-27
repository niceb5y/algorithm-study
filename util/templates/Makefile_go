GO         = go
SHELL      = /bin/bash

main.out: main.go
	@$(GO) build -o ./main.out ./main.go

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

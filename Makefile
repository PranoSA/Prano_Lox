#flags = -Wall -Wextra -Werror -g -I ./include
flags = -I ./include
name = pranolox
#C_SOURCES := $(wildcard ./src/**.c)
C_SOURCES := $(shell find ./src -name '*.c')
#TEST_SOURCES := $(wildcard ./tests/*.c)
TEST_SOURCES := $(shell find ./tests -name '*.c')
C_SOURCES_TEST := $(filter-out ./src/core/main.c,$(C_SOURCES))

build:
	@echo $(C_SOURCES)
	gcc $(flags) $(C_SOURCES) -o ./bin/$(name)

build_debug:
	@echo $(C_SOURCES)
	gcc $(flags) $(C_SOURCES) -g -o ./bin/$(name)

# Test Actually Runs the software and sees if it returns an exit code
list_tests:
	@echo $(TEST_SOURCES)

test: build_test
	@echo "Running Tests"
	@for test in $(TEST_SOURCES); do \
		@echo "Running Test: $$test" \
		test_name=`basename $$test .c`; \
		gcc $(flags) $(C_SOURCES) $$test -o ./bin/test/$$test_name; \
	done

build_test:
	@echo "Building Tests"
	@for test in $(TEST_SOURCES); do \
		echo "Building Test: $$test"; \
        test_name=`basename $$test .c`; \
		echo $$test_name; \
        gcc $(flags) $(C_SOURCES_TEST) $$test -o ./bin/tests/$$test_name; \
	done


test-%:
	@echo "Running Test: $*"
	@./bin/tests/$*




# How do you extrapolate the name from the source code file name?
#build_test:
 #   for test in $(TEST_SOURCES); do \
  #      test_name=`basename $$test .c`; \
   #     gcc $(FLAGS) $(C_SOURCES) $$test -o ./bin/$(NAME)_$$test_name; \
   # done

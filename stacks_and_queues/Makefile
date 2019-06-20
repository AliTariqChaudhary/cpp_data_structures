CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Wzero-as-null-pointer-constant
all: test_queue.cpp
	g++  $(CXXFLAGS)  test_queue.cpp  -o  test_queue
	g++  $(CXXFLAGS)  test_stack.cpp -o test_stack
clean:
	echo -----------------------------removing executable-------------------
	/bin/rm test_queue
	/bin/rm test_stack

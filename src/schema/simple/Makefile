export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(OBJS)

%.o: %.cpp
	$(cc) $(cpp_flags) -c $< -o $@

clean:
	rm -f *.o

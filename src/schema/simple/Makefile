export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

export src_dir := src
export obj_dir := ../../../build

src_files = $(wildcard $(src_dir)/*.cpp)
obj_files = $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files))

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(OBJS)

%.o: %.cpp
	$(cc) $(cpp_flags) -c $< -o $(obj_dir)/$@

clean:
	rm -f *.o

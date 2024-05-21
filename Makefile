export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: path.o query.o element.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so path.o query.o element.o xml.o
	ar -rcs libxml.a path.o query.o element.o xml.o

clean:
	rm -f *.o *.so *.a

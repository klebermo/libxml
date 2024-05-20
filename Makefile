export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

libxml: element.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so element.o xml.o
	ar -rcs libxml.a element.o xml.o

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

clean:
	rm -f *.o *.so *.a

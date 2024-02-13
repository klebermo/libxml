export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

libxml: tag.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so tag.o xml.o
	ar -rcs libxml.a tag.o xml.o

tag.o: src/tag.cpp
	$(cc) $(cpp_flags) -c src/tag.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

clean:
	rm -f *.o *.so *.a

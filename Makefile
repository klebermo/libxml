export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

document.o: src/document.cpp
	$(cc) $(cpp_flags) -c src/document.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: element.o path.o query.o document.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so element.o path.o query.o document.o xml.o
	ar -rcs libxml.a element.o path.o query.o document.o xml.o

clean:
	rm -f *.o *.so *.a

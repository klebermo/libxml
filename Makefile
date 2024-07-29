export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

all: libxml

any.o: src/any.cpp
	$(cc) $(cpp_flags) -c src/any.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

node.o: src/node.cpp
	$(cc) $(cpp_flags) -c src/node.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

document.o: src/document.cpp
	$(cc) $(cpp_flags) -c src/document.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: any.o element.o node.o path.o query.o document.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so any.o element.o node.o path.o query.o document.o xml.o
	ar -rcs libxml.a any.o element.o node.o path.o query.o document.o xml.o

clean:
	rm -f *.o *.so *.a

export cc := g++
export cpp_flags := -Wall -pedantic -fPIC

all: libxml

simple.o: src/schema/simple.cpp
	$(cc) $(cpp_flags) -c src/schema/simple.cpp

complex.o: src/schema/complex.cpp
	$(cc) $(cpp_flags) -c src/schema/complex.cpp

any.o: src/schema/any.cpp
	$(cc) $(cpp_flags) -c src/schema/any.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

node.o: src/node.cpp
	$(cc) $(cpp_flags) -c src/node.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

namespace.o: src/namespace.cpp
	$(cc) $(cpp_flags) -c src/namespace.cpp

document.o: src/document.cpp
	$(cc) $(cpp_flags) -c src/document.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: simple.o complex.o any.o element.o node.o path.o query.o namespace.o document.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so simple.o complex.o any.o element.o node.o path.o query.o namespace.o document.o xml.o
	ar -rcs libxml.a simple.o complex.o any.o element.o node.o path.o query.o namespace.o document.o xml.o

clean:
	rm -f *.o *.so *.a

export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

namespace.o: src/namespace.cpp
	$(cc) $(cpp_flags) -c src/namespace.cpp

document.o: src/document.cpp
	$(cc) $(cpp_flags) -c src/document.cpp

prolog.o: src/prolog.cpp
	$(cc) $(cpp_flags) -c src/prolog.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: element.o path.o query.o namespace.o document.o prolog.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so element.o path.o query.o namespace.o document.o prolog.o xml.o
	ar -rcs libxml.a element.o path.o query.o namespace.o document.o prolog.o xml.o

clean:
	rm -f *.o *.so *.a

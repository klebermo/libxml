export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

model.o: src/model.cpp
	$(cc) $(cpp_flags) -c src/model.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

namespace.o: src/namespace.cpp
	$(cc) $(cpp_flags) -c src/namespace.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: element.o model.o path.o query.o namespace.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so element.o model.o path.o query.o namespace.o xml.o
	ar -rcs libxml.a element.o model.o path.o query.o namespace.o xml.o

clean:
	rm -f *.o *.so *.a

export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

model.o: src/model.cpp
	$(cc) $(cpp_flags) -c src/model.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

text.o: src/text.cpp
	$(cc) $(cpp_flags) -c src/text.cpp

path.o: src/path.cpp
	$(cc) $(cpp_flags) -c src/path.cpp

query.o: src/query.cpp
	$(cc) $(cpp_flags) -c src/query.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

libxml: model.o element.o text.o path.o query.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so model.o element.o text.o path.o query.o xml.o
	ar -rcs libxml.a model.o element.o text.o path.o query.o xml.o

clean:
	rm -f *.o *.so *.a

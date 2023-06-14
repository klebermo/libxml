export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

libxml: tag.o atributo.o elemento.o comentario.o declaration.o type.o data.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so tag.o atributo.o elemento.o comentario.o declaration.o type.o data.o xml.o

tag.o: src/tag.cpp
	$(cc) $(cpp_flags) -c src/tag.cpp

atributo.o: src/atributo.cpp
	$(cc) $(cpp_flags) -c src/atributo.cpp

elemento.o: src/elemento.cpp
	$(cc) $(cpp_flags) -c src/elemento.cpp

comentario.o: src/comentario.cpp
	$(cc) $(cpp_flags) -c src/comentario.cpp

declaration.o: src/declaration.cpp
	$(cc) $(cpp_flags) -c src/declaration.cpp

type.o: src/type.cpp
	$(cc) $(cpp_flags) -c src/type.cpp

data.o: src/data.cpp
	$(cc) $(cpp_flags) -c src/data.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

clean:
	rm -f *.o *.so

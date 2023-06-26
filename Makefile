export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

libxml: tag.o attribute.o text.o element.o comment.o type.o data.o syntaxNode.o syntaxTree.o xquery.o xpath.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so tag.o attribute.o text.o element.o comment.o type.o data.o syntaxNode.o syntaxTree.o xquery.o xpath.o xml.o

tag.o: src/tag.cpp
	$(cc) $(cpp_flags) -c src/tag.cpp

attribute.o: src/attribute.cpp
	$(cc) $(cpp_flags) -c src/attribute.cpp

text.o: src/text.cpp
	$(cc) $(cpp_flags) -c src/text.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

comment.o: src/comment.cpp
	$(cc) $(cpp_flags) -c src/comment.cpp

type.o: src/type.cpp
	$(cc) $(cpp_flags) -c src/type.cpp

data.o: src/data.cpp
	$(cc) $(cpp_flags) -c src/data.cpp

syntaxNode.o: src/syntaxNode.cpp
	$(cc) $(cpp_flags) -c src/syntaxNode.cpp

syntaxTree.o: src/syntaxTree.cpp
	$(cc) $(cpp_flags) -c src/syntaxTree.cpp

xquery.o: src/xquery.cpp
	$(cc) $(cpp_flags) -c src/xquery.cpp

xpath.o: src/xpath.cpp
	$(cc) $(cpp_flags) -c src/xpath.cpp

xml.o: src/xml.cpp
	$(cc) $(cpp_flags) -c src/xml.cpp

clean:
	rm -f *.o *.so

export cc := g++
export cpp_flags := -Wall -pedantic -fPIC -g

all: libxml

libxml: tag.o attr.o element.o comment.o decl.o type.o data.o syntaxNode.o syntaxTree.o xquery.o xpath.o model.o instruction.o xml.o
	$(cc) $(cpp_flags) -shared -o libxml.so tag.o attr.o element.o comment.o decl.o type.o data.o syntaxNode.o syntaxTree.o xquery.o xpath.o model.o instruction.o xml.o

tag.o: src/tag.cpp
	$(cc) $(cpp_flags) -c src/tag.cpp

attr.o: src/attr.cpp
	$(cc) $(cpp_flags) -c src/attr.cpp

element.o: src/element.cpp
	$(cc) $(cpp_flags) -c src/element.cpp

comment.o: src/comment.cpp
	$(cc) $(cpp_flags) -c src/comment.cpp

decl.o: src/decl.cpp
	$(cc) $(cpp_flags) -c src/decl.cpp

type.o: src/type.cpp
	$(cc) $(cpp_flags) -c src/type.cpp

data.o: src/data.cpp
	$(cc) $(cpp_flags) -c src/data.cpp

model.o: src/model.cpp
	$(cc) $(cpp_flags) -c src/model.cpp

instruction.o: src/instruction.cpp
	$(cc) $(cpp_flags) -c src/instruction.cpp

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

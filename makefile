hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/AVLDynamicArray.o -c ./src/AVLDynamicArray.cpp
	g++ -I ./include/ -o ./lib/AVLNode.o -c ./src/AVLNode.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/StackDynamicArray.o -c ./src/StackDynamicArray.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/AVL.o ./lib/AVLDynamicArray.o ./lib/AVLNode.o ./lib/Stack.o ./lib/StackDynamicArray.o ./src/main.cpp

calistir:
	./bin/Test
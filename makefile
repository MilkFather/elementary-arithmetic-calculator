build : main.o calc.o
	g++ -o calculator main.o calc.o lexize.o tokenize.o rpn.o stacking.o utils.o

main.o : main.cpp
	g++ -c main.cpp

calc.o : calc.cpp lexize.cpp tokenize.cpp rpn.cpp stacking.cpp utils.cpp
	g++ -c calc.cpp lexize.cpp tokenize.cpp rpn.cpp stacking.cpp utils.cpp

clean :
	rm main.o lexize.o tokenize.o rpn.o stacking.o utils.o calc.o
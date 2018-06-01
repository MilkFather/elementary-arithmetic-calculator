build : main.o lexize.o tokenize.o rpn.o stacking.o utils.o calc.o
	g++ -o calculator main.o calc.o lexize.o tokenize.o rpn.o stacking.o utils.o

main.o : main.cpp calc.cpp
	g++ -c main.cpp

calc.o : calc.cpp lexize.cpp tokenize.cpp rpn.cpp stacking.cpp utils.cpp
	g++ -c calc.cpp

lexize.o : lexize.cpp utils.cpp
	g++ -c lexize.cpp 

tokenize.o : tokenize.cpp utils.cpp
	g++ -c tokenize.cpp 

rpn.o : rpn.cpp utils.cpp
	g++ -c rpn.cpp

stacking.o : stacking.cpp utils.cpp
	g++ -c stacking.cpp

utils.o : utils.cpp utils.cpp
	g++ -c utils.cpp

clean :
	rm main.o lexize.o tokenize.o rpn.o stacking.o utils.o calc.o
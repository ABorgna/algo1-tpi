
all: fatFood

clean:
	rm *.o
	rm fatFood

fatFood: fatFood.cpp interfaz.cpp local.o pedido.o combo.o auxiliar.o
	g++ -std=gnu++11 -o fatFood $^

%.o: %.cpp
	g++ -std=gnu++11 -c $<

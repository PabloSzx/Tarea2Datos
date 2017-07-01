all:
	c++ -std=c++11 main.cc -o main
	c++ -std=c++11 clear.cc -o clear
	./clear
	# Ejecutar con ./main n

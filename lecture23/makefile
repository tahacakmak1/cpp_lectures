out: main.o Audi.o Mercedes.o
	g++ -std=c++17 -Wpedantic main.o Audi.o Mercedes.o -o out

main.o: ICar.h main.cpp
	g++ -std=c++17 -Wpedantic -c main.cpp

Mercedes.o: ICar.h Mercedes.h Mercedes.cpp
	g++ -std=c++17 -Wpedantic -c Mercedes.cpp

Audi.o: ICar.h Audi.h Audi.cpp
	g++ -std=c++17 -Wpedantic -c Audi.cpp

cleanup:
	rm *.o out *.s

assem:
	g++ -std=c++17 -Wpedantic -S *.cpp

format:
	clang-format -i -style=file *.cpp

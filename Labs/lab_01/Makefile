util.o: util.cpp util.h
	g++ -c util.cpp

lab_01.o: lab_01.cpp util.h
	g++ -c lab_01.cpp

lab_01: util.o lab_01.o
	g++ lab_01.o util.o -o lab_01

clean:
	rm *.o
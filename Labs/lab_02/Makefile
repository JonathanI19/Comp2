student.o: student.cpp student.h
	g++ -c student.cpp

lab_02.o: lab_02.cpp student.h
	g++ -c lab_02.cpp

lab_02: student.o lab_02.o
	g++ lab_02.o student.o -o lab_02

clean:
	rm *.o
classroomRun: date.o address.o student.o classroom.o main.o
	g++ date.o address.o student.o classroom.o main.o -o classroomRun
classroom.o: classroom.cpp classroom.h
	g++ -c classroom.cpp
date.o: date.cpp date.h
	g++ -c date.cpp
address.o: address.cpp address.h
	g++ -c address.cpp
student.o: student.cpp student.h
	g++ -c student.cpp
main.o: main.cpp 
	g++ -c main.cpp
clean:
	rm -f *.o
	rm classroomRun
	rm -f *.txt
valgrind: classroomRun
	valgrind --leak-chec`k=full -s ./classroomRun
run: classroomRun
	./classroomRun

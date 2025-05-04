classroomRun: date.o address.o student.o main.o
	g++ date.o address.o student.o main.o -o classroomRun
date.o: date.cpp date.h
	g++ -c date.cpp
address.o: address.cpp address.h
	g++ -c address.cpp
student.o: student.cpp student.h
	g++ -c student.cpp
classroom.o: main.cpp 
	g++ -c main.cpp
clean:
	rm -f *.o
	rm classroomRun
	rm fullReport.txt
	rm shortReport.txt
valgrind: classroomRun
	valgrind --leak-check=full -s ./classroomRun
run: classroomRun
	./classroomRun

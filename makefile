bin/unixShell: obj/main.o obj/calc.o obj/get.o obj/path.o obj/put.o obj/shellTime.o obj/sys.o functions.h
	mkdir -p bin
	gcc -g obj/main.o obj/calc.o obj/get.o obj/path.o obj/put.o obj/shellTime.o obj/sys.o -o bin/unixShell
obj/main.o: functions.h main.c
	mkdir -p obj
	gcc -c main.c -o obj/main.o
obj/calc.o: functions.h calc.c
	gcc -c calc.c -o obj/calc.o
obj/get.o: functions.h get.c
	gcc -c get.c -o obj/get.o
obj/path.o: functions.h path.c
	gcc -c path.c -o obj/path.o
obj/shellTime.o: functions.h shellTime.c
	gcc -c shellTime.c -o obj/shellTime.o
obj/sys.o: functions.h sys.c
	gcc -c sys.c -o obj/sys.o
obj/put.o: functions.h put.c
	gcc -c put.c -o obj/put.o

clean:
	rm -rf bin obj



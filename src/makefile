all: comp301_ass2

comp301_ass2: main.o Dlist.o scheduler.o
	gcc main.o Dlist.o scheduler.o -o comp301_ass2

main.o: main.c
	gcc -c main.c
	
Dlist.o: Dlist.c
	gcc -c Dlist.c
	
scheduler.o: scheduler.c
	gcc -c scheduler.c

clean:
	rm -rf *o comp301_ass2
sched: sched.o functionsPA4.o print_progress.o
	gcc sched.o functionsPA4.o print_progress.o functionsPA4.h -Wall -Wextra -g -pthread -o sched

functionsPA4.o: functionsPA4.c functionsPA4.h
	gcc -c -Wall -Wextra -g functionsPA4.c

sched.o:  sched.c functionsPA4.h
	gcc -c -Wall -Wextra -g -pthread -c sched.c

print_progress.o: print_progress.c functionsPA4.h
	gcc -c -Wall -Wextra -g print_progress.c

make clean:
	rm *.o sched
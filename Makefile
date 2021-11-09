CC=mpicc
CFLAGS=-std=c99 -g -Og -fopenmp -w
TARGETS= bin/HelloWorld bin/HelloWorld_debug  bin/OpenMP bin/MPI bin/SegFault bin/InfLoop

all:  $(TARGETS) 

bin/HelloWorld: src/HelloWorld.c
	$(CC)  -std=c99  $< -o $@

bin/HelloWorld_debug: src/HelloWorld.c
	$(CC) $(CFLAGS)  $< -o $@


bin/% : src/%.c
	$(CC)  $(CFLAGS)  $< -o $@

slides:
	cd doc && latexmk -pdf main.tex

clean:
	$(RM) -f $(TARGETS)

clean_slides:
	 cd doc && latexmk -C main.tex

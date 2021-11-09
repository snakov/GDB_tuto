CC=gcc
CFLAGS=-g -Og 
TARGETS= bin/HelloWorld bin/HelloWorld_debug 

all:  $(TARGETS) 

bin/HelloWorld: src/HelloWorld.c
	$(CC)   $< -o $@

bin/HelloWorld_debug: src/HelloWorld.c
	$(CC) $(CFLAGS)  $< -o $@


bin/% : src/%.c
	$(CC)  $(CFLAGS)  $< -o $@

slides:
	cd doc && latexmk -pdf main.tex

clean:
	$(RM) -f $(TARGETS) && cd doc && latexmk -C main.tex

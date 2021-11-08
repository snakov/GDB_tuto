CC=gcc
CFLAGS=-g 
TARGETS= bin/1_1_HelloWorld bin/1_2_HelloWorld

all:  $(TARGETS) 

bin/1_1_HelloWorld: src/1_1_HelloWorld.c
	$(CC)   $< -o $@

bin/1_2_HelloWorld: src/1_1_HelloWorld.c
	$(CC) $(CFLAGS)  $< -o $@


bin/% : src/%.c
	$(CC)  $(CFLAGS)  $< -o $@

slides:
	cd doc && latexmk -pdf main.tex

clean:
	$(RM) -f $(TARGETS)

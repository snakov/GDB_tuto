CC=gcc

TARGETS= bin/1_1_HelloWorld

all:  $(TARGETS) 

bin/% : src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

slides:
	cd doc && latexmk -pdf main.tex

clean:
	$(RM) -f $(TARGETS)

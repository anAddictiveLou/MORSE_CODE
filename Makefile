.PHONY: all clean

all: 
	gcc -o morse src/main.c src/file_.c src/convert_.c -I ./inc
clean: 
	rm -rf obj/* morse




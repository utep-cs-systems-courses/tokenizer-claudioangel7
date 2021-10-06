tokenizerT: tokenizer.o history.o simpleUI.o
	gcc -o tokenizer tokenizer.o history.o simpleUI.o 

tokenizer.o: tokenizer.c tokenizer.h

history.o: history.c history.h

simpleUI.o: simpleUI.c tokenizer.c history.c

clean:
	rm -f *.o

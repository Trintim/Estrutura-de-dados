CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
LIBS=-lm
EXECUTAVEL=EP3

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Util.o ArvoresBinAvl.o Fila.o
	gcc main.o Util.o ArvoresBinAvl.o Fila.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Util.o: Util.c
	gcc $(CFLAGS) -c Util.c

ArvoresBinAvl.o: ArvoresBinAvl.c
	gcc $(CFLAGS) -c ArvoresBinAvl.c

Fila.o: Fila.c
	gcc $(CFLAGS) -c Fila.c

clean:
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) -d Dicionario.txt -t TextoExemplo.txt

run: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d Dicionario.txt -t Texto.txt -avl

run1: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d 100000.txt -t Movimento.txt -avl

run2: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d 100000.txt -t Noticia.txt -avl

run3: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d 100000.txt -t Noticia2.txt -avl

run4: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d 100000.txt -t texto.txt -avl

run22: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d Dicionario2.txt -t TextoExemplo2.txt -avl



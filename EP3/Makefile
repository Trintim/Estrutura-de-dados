CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
LIBS=-lm
EXECUTAVEL=EP3

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Util.o Fila.o ArvoreAVL.o
	gcc main.o Util.o ArvoreAVL.o Fila.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Util.o: Util.c
	gcc $(CFLAGS) -c Util.c

Fila.o: Fila.c
	gcc $(CFLAGS) -c Fila.c

ArvoreAVL.o: ArvoreAVL.c
	gcc $(CFLAGS) -c ArvoreAVL.c

clean:
	rm -rf *.o $(EXECUTAVEL)

# Para executar com a árvore AVL adicione um '-avl':
# run: $(EXECUTAVEL)
# 	./$(EXECUTAVEL) -d Dicionario.txt -t TextoEP3.txt -avl

run: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d Dicionario.txt -t TextoEP3.txt

run1: $(EXECUTAVEL)
	./$(EXECUTAVEL) -d teste.txt -t TextoTeste.txt

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) -d Dicionario.txt -t TextoEP3.txt
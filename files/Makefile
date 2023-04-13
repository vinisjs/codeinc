CC=gcc
flag=-c
CFLAGS= 
EXEC=principal
SRC=principal.c
lib=estrutura.c
libo=estrutura.o
liba=estrutura.a

all: limpar compilar
compilar:
	$(CC) $(CFLAGS) -o $(EXEC) $(lib) $(SRC)
compilaro:limpar
	$(CC) $(flag) $(lib) -o $(libo)
	$(CC) $(CFLAGS) -o $(EXEC) $(libo) $(SRC)
compilara:limpar
	$(CC) $(flag) $(lib) -o $(libo)
	ar -cr $(liba) $(libo)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC) $(liba)
limpar:
	rm -f $(EXEC)
	rm -f $(libo)
	rm -f $(liba)
executar:
	clear
	./$(EXEC)
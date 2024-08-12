# CC = gcc  # comme une variable qui contient le compilateur C à utiliser, ici gcc (GNU Compiler Collection)
# CFLAGS = -Wall -Wextra -Werror # contient les options de compilation 
# SRCS = my_ls.c utils.c display.c # contient la liste des fichiers source .c à compiler.
# OBJS = $(SRCS:.c=.o) #  transformer une liste de fichiers source avec l'extension .c en une liste de fichiers objets avec l'extension .o
# NAME = my_ls #variable qui contient le nom du fichier exécutable à générer

# all: $(NAME) #all est une cible par défaut qui dépend de la cible $(NAME), c'est-à-dire my_ls

# $(NAME): $(OBJS) #définit comment construire l'exécutable my_ls à partir des fichiers objets listés dans $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# clean: # Pour nettoyer les fichiers objets, utilisez 
# 	rm -f $(OBJS)

# fclean: clean #Pour nettoyer tous les fichiers générés, et my_ls
# 	rm -f $(NAME)

# re: fclean all # Pour forcer une reconstruction complète du projet
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: my_ls

my_ls: my_ls.o utils.o display.o flags_pars.o flag_l.o flag_r.o flag_t.o flag_-R.o flag_-L.o
	$(CC) $(CFLAGS) -o my_ls my_ls.o utils.o display.o flags_pars.o flag_l.o flag_r.o flag_t.o flag_-R.o flag_-L.o

my_ls.o: my_ls.c my_ls.h
	$(CC) $(CFLAGS) -c my_ls.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

display.o: display.c display.h
	$(CC) $(CFLAGS) -c display.c

flags_pars.o: flags_pars.c flags_pars.h
	$(CC) $(CFLAGS) -c flags_pars.c
	
flag_l.o: flag_l.c flag_l.h
	$(CC) $(CFLAGS) -c flag_l.c

flag_r.o: flag_r.c flag_r.h
	$(CC) $(CFLAGS) -c flag_r.c

flag_t.o: flag_t.c flag_t.h
	$(CC) $(CFLAGS) -c flag_t.c
	
flag_-R.o: flag_-R.c flag_R.h
	$(CC) $(CFLAGS) -c flag_-R.c
	
flag_-L.o: flag_-L.c flag_L.h
	$(CC) $(CFLAGS) -c flag_-L.c

clean:
	rm -f *.o my_ls

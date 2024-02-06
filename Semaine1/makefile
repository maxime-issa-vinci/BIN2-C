CC=gcc
CFLAGS=-I.

# La cible 'all' qui dépend de 'encrypt' et 'decrypt'
all: encrypt decrypt

# Compilation de crypt.o
crypt.o: crypt.c crypt.h
	$(CC) -c crypt.c $(CFLAGS)

# Compilation de encrypt.o
encrypt.o: encrypt.c crypt.h utils_v1.h
	$(CC) -c encrypt.c $(CFLAGS)

# Compilation de decrypt.o
decrypt.o: decrypt.c crypt.h utils_v1.h
	$(CC) -c decrypt.c $(CFLAGS)

# Compilation de utils.o, remplacez utils.c et utils_v1.h par vos fichiers réels
utils.o: utils.c utils_v1.h
	$(CC) -c utils.c $(CFLAGS)

# Lien pour créer l'exécutable 'encrypt'
encrypt: encrypt.o crypt.o utils.o
	$(CC) -o encrypt encrypt.o crypt.o utils.o

# Lien pour créer l'exécutable 'decrypt'
decrypt: decrypt.o crypt.o utils.o
	$(CC) -o decrypt decrypt.o crypt.o utils.o

# Nettoyage des fichiers compilés
clean:
	rm -f *.o encrypt decrypt

CFLAGS=-std=c17 -pedantic -Wvla -Werror -Wall -D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809

# La cible 'all' qui dépend de 'encrypt' et 'decrypt'
all: encrypt decrypt

# Lien pour créer l'exécutable 'encrypt'
encrypt: encrypt.o crypt.o utils_v1.o
	gcc ${CFLAGS} -o encrypt encrypt.o crypt.o utils_v1.o 

# Lien pour créer l'exécutable 'decrypt'
decrypt: decrypt.o crypt.o utils_v1.o 
	gcc ${CFLAGS} -o decrypt decrypt.o crypt.o utils_v1.o 

encryptPolybe:
	gcc ${CFLAGS} -o encryptPolybe encryptPolybe.o crypt.o utils_v1.o

decryptPolybe:
	gcc ${CFLAGS} -o decryptPolybe decryptPolybe.o crypt.o utils_v1.o 


# Compilation de crypt.o
crypt.o: crypt.c crypt.h
	gcc ${CFLAGS} -c crypt.c

# Compilation de encrypt.o
encrypt.o: encrypt.c crypt.h utils_v1.h
	gcc ${CFLAGS} -c encrypt.c

# Compilation de decrypt.o
decrypt.o: decrypt.c crypt.h utils_v1.h
	gcc ${CFLAGS} -c decrypt.c

# Compilation de utils.o, remplacez utils.c et utils_v1.h par vos fichiers réels
utils_v1.o: utils_v1.c utils_v1.h
	gcc ${CFLAGS} -c utils_v1.c

cryptPolybe.o: cryptPolybe.c cryptPolybe.h utils_v1.h
	gcc ${CFLAGS} -c cryptPolybe.c

encryptPolybe.o: encryptPolybe.c cryptPolybe.h utils_v1.h
	gcc ${CFLAGS} -c encryptPolybe.c

decryptPolybe.o: decryptPolybe.c cryptPolybe.h utils_v1.h
	gcc ${CFLAGS} -c decryptPolybe.c



# Nettoyage des fichiers compilés
clean:
	rm -f *.o encrypt decrypt encryptPolybe decryptPolybe

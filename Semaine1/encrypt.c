#include <stdio.h>
#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* line = readLine(); // Lire une ligne de l'entrée standard
    if (line != NULL) { // Vérifier si la lecture a réussi
        char* c = encrypt(line); // Chiffrer la ligne lue
        if (c != NULL) { // Vérifier si le chiffrement a réussi
            printf("%s\n", c); // Afficher la chaîne chiffrée
            free(c); // Libérer la mémoire allouée par encrypt
        }
        free(line); // Libérer la mémoire allouée par readLine
    }
    return 0;
}

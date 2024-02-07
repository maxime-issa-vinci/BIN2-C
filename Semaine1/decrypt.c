#include <stdio.h>
#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
    char* line = readLine();
    if (line != NULL) {
        char* c = decrypt(line);
        if (c != NULL) {
            printf("%s\n", c);
            free(c); // Libère la mémoire allouée par decrypt (si decrypt alloue de la mémoire)
        }
        free(line); // Libère la mémoire allouée par readLine
    }
    return 0;
}

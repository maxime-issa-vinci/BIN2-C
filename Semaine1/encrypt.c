#include <stdio.h>
#include "crypt.h"
#include "utils_v1.h"

int main(int argc, char const *argv[])
{
	char* line = readLine();
	char* c = encrypt(line);
	printf("%s", c);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *test = malloc(1);
	printf("%c", test[3]);
	return 0;
}

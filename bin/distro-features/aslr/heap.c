#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *ptr = malloc(40);
	// If we are passed an address, then lets just
	// do a compare to see if it was guessed by the user.
	// Returns 1 if guessed and 0 if not.
	if (argc == 2) {
		snprintf(ptr, 40, "%018p", ptr);
		if (strcmp(argv[1], ptr) == 0)
			return 1;
		return 0;
	}
	printf("%018p\n", ptr);
	free(ptr);
	return 0;
}


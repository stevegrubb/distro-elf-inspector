#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *f;
	unsigned long long and, or;
	size_t size = 0;
	ssize_t len;
	char *buf = NULL;

	and = ~0LL;
	or = 0LL;
	f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "Unable to open %s\n", argv[1]);
		return 1;
	}
	while ((len = getline(&buf, &size, f)) > 0) {
		unsigned long long num;
		errno = 0;
		num = strtoull(buf, NULL, 16);
		if (errno)
			break;

		and &= num;
		or |= num;
	}
	fclose(f);

	if (and == or)
		printf( "00 bits\n" );
	else {
		int bits = 0;
		unsigned long long tmp;
		tmp = and ^ ~or;
		tmp = or & ~tmp;
		while (tmp != 0) {
			bits += (tmp%2);
			tmp >>= 1;
		}

		printf("%d bits\n", bits);
	}
	return 0;
}


#include <stdio.h>
#include <sys/mman.h>

#define SIZE 4096

int main(void)
{
	char *ptr = mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	printf("%018p\n", ptr);
	munmap(ptr, SIZE);
	return 0;
}


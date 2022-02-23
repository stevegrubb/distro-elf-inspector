#include <stdio.h>
#include <sys/prctl.h>

int main(void)
{
#ifdef PR_SET_SECCOMP
	printf("seccomp\n");
#endif
	return 0;
}


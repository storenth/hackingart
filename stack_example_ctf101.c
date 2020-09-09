/* https://ctf101.org/binary-exploitation/what-is-the-stack/ */
/* Examine the stack using say_hi call */

#include <stdio.h>

void say_hi(const char *name)
{
	printf("Hello %s!\n", name);
}

int main(int argc, char **argv)
{
	char *name;
	if (argc != 2)
	{
		return 1;
	}
	name = argv[1];
	say_hi(name);
	return 0;
}

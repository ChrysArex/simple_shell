#include "main.h"
/**
 * main - entry point of our shell
 * @argc: number of arguments
 * @argv: array of args
 * @env: array of environment variables
 * Return: zero on succes
 */

int main(int argc, char **argv, char **env)
{
	char *buff = NULL;
	int i = argc;
	ssize_t len;
	size_t n = 0;

	while (1)
	{
		if (isatty(0))
			write(1, "simple_shell ", 13);
		len = getline(&buff, &n, stdin);
		if (len == EOF)
			break;
		i = wd_count(buff) + 1;
		if (i == 1)
			continue;
		exe_cmd(buff, i, argv[0], env);
	}
	free(buff);
	return (0);
}

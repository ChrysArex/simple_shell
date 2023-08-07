#include "main.h"

/**
 * free_arg - free an array of pointers
 * @arg: array of char
 * Return: nothing
 */
void free_arg(char **arg)
{
	int j = 0;

	for (; arg[j]; j++)
		free(arg[j]);
	free(arg[j]);
	free(arg);
}

/**
 * wd_count - count the number of word
 * @p: pointer to the string
 * Return: the number of word in the string
 */
int wd_count(char *p)
{
	int count = 0;
	/*int i = 0, j = strlen(p);*/

	for (; *p != '\n';)
	{
		if (*p != ' ')
		{
			for (; (*p != ' ') && (*p != '\n'); p++)
				;
			count++;
		}
		else
			p++;
	}
	return (count);
}
/**
 * exe_cmd- exeute the command typed by the user
 * @buff: the buffer containing the commande typed
 * @i: the number of word in the commande
 * @script: the name of the exe file (argv[0])
 * @env: array of environment variables
 * Return: nothing
 */
void exe_cmd(char *buff, int i, char *script, char **env)
{
	char **arg;
	int exit_status = 0;
	int status, p = 1;
	pid_t child_id;

	arg = malloc(sizeof(*arg) * i);
	rm_end(&arg[0], strtok(buff, " "));
	while (p < (i - 1))
	{
		rm_end(&arg[p], strtok(NULL, " "));
		p++;
	}
	arg[p] = NULL;
	if (_strcmp("env", arg[0]) == 0)
	{
		_printenv();
		free_arg(arg);
		return;
	}
	else if (_strcmp("exit", arg[0]) == 0)
	{
		if (arg[1] != NULL)
			check_int(arg[1], &exit_status);

		free_arg(arg);
		free(buff);
		_exit(exit_status);
	}
	if (checkcmd(&arg[0], env) != 0)
		perror(script);
	else
	{
		child_id = fork();
		if (child_id == 0)
			execve(arg[0], arg, env);
		else
			wait(&status);
	}
	free_arg(arg);
}

/**
 * checkcmd - checks if the command can be run
 * @cmd: pointer to string
 * @env: array of environment variables
 *
 * Return: 0 if command can be run successfully; -1 otherwise
 */
int checkcmd(char **cmd, char **env)
{
	char *path, *cmdpath, *tmp = NULL;
	int dirlen, cmdlen;
	struct stat st;

	if (stat(*cmd, &st) == 0)
		return (0);
	path = strtok(_getenv("PATH", env, &tmp), ":");
	while (path != NULL)
	{
		dirlen = _strlen(path);
		cmdlen = _strlen(*cmd);
		cmdpath = malloc(sizeof(char) * (dirlen + cmdlen + 2));
		if (cmdpath == NULL)
		{
			free(tmp);
			return (-1);
		}
		_strncpy(cmdpath, path, dirlen);
		cmdpath[dirlen] = '/';
		_strncpy(&cmdpath[dirlen + 1], *cmd, cmdlen);
		cmdpath[dirlen + cmdlen + 1] = '\0';
		if (stat(cmdpath, &st) == 0)
		{
			free(*cmd);
			*cmd = malloc(sizeof(char) * _strlen(cmdpath) + 1);
			if (*cmd == NULL)
			{
				free(tmp);
				return (-1);
			}
			_strncpy(*cmd, cmdpath, _strlen(cmdpath) + 1);
			free(cmdpath);
			free(tmp);
			return (0);
		}
		free(cmdpath);
		path = strtok(NULL, ":");
	}
	free(tmp);
	return (-1);
}

/**
 * check_int - converts a string to an integer
 *	If the string is not a valid integer, it sets the pointer to 0
 *
 * @str: string to convert
 * @status: pointer to int
 */
void check_int(char *str, int *status)
{
	int i;
	int len = _strlen(str);
	*status = 0;

	for (i = len - 1; i >= 0; i--)
	{
		if (i == 0 && str[i] == '-')
			*status *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			*status += (str[i] - '0') * _power(10, (len - i - 1));
		else
		{
			*status = 0;
			return;
		}
	}
}

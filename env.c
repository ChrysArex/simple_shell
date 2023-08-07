#include "main.h"

/**
 * _printenv - prints the environment variables present
 */
void _printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}

/**
 * _getenv - returns the value of an environment variable
 * @name: environment variable to return
 * @env: array of enironment variables
 * @tmp: poiter to the new allocated memory
 *
 * Return: String containing env value; NULL if env was not found
 */
char *_getenv(char *name, char **env, char **tmp)
{
	int i;
	char *pathname;

	for (i = 0; env[i] != NULL; i++)
	{
		*tmp = malloc(sizeof(char) * (_strlen(env[i]) + 1));
		_strncpy(*tmp, env[i], _strlen(env[i]));
		(*tmp)[_strlen(env[i])] = '\0';
		pathname = strtok(*tmp, "=");

		if (_strcmp(name, pathname) == 0)
		{
			pathname = strtok(NULL, "=");
			return (pathname);
		}
		free(*tmp);
	}
	return (NULL);
}

#include "main.h"

/**
 * rm_end - make a new string whitout the char $ \n \0 \t
 * @d: array of pointers
 * @s: a string
 * Return: Nothing
 */
void rm_end(char **d, char *s)
{
	char *new_s = malloc(sizeof(char *) * (strlen(s) + 1));
	int i = 0;

	for (; *s != '$' && *s != '\n' && *s != '\0' && *s != '\t'; s++)
	{
		new_s[i] = *s;
		i++;
	}
	new_s[i] = '\0';
	*d = new_s;
}

/**
 * splitcmd - a funtion splits a string into an array of strings
 * @cmd: pointer to string to split
 *
 * Return: an array of pointers to strings
 */
char **splitcmd(char *cmd)
{
	char *str;
	char **strarr;
	int i = 0;

	strarr = malloc(sizeof(char *) * ARG_MAX);

	if (strarr == NULL)
	{
		perror("hsh");
		exit(1);
	}
	str = strtok(cmd, " ");
	rm_end(&strarr[i], str);

	while (strarr[i] != NULL)
	{
		i++;
		rm_end(&strarr[i], strtok(NULL, " "));
	}

	return (strarr);
}

/**
 * _strncpy - copies the value of one string to another
 * @dest: string to copy to
 * @src: string to copy from
 * @n: number of bytes to copy
 */
void _strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';
}

/**
 * _strcmp - checks if two strings are the same
 * @str1: string
 * @str2: string
 *
 * Return: 0 if same
 */
int _strcmp(char *str1, char *str2)
{
	int strlen1 = _strlen(str1);
	int strlen2 = _strlen(str2);
	int i;

	for (i = 0; i < strlen1 && i < strlen2; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str2[i] > str1[i])
			return (str2[i] - str1[i]);
	}
	return (0);
}

/**
 * _strlen - function that returns the length of a string
 * @str: pointer to string
 *
 * Return: an integer
 */
int _strlen(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
		;

	return (len);
}


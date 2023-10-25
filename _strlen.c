/**
 * _strlen - Return the length of a string
 * @s: string to return length of
 *
 * Return: the length of s
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
/*
int main()
{
    const char *str = "Hello, world!";
    char ch = 'o';

    char *result = ft_strchr(str, ch);

    if (result)
    {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    }
    else
    {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
*/

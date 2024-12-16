#include <stdlib.h>

int static	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char static	*ft_strncpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char static	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;

	src_len = ft_strlen(src) + 1;
	dest = (char *) malloc(src_len);
	if (dest == NULL)
		return (NULL);
	ft_strncpy(dest, src, src_len);
	return (dest);
}

char static	*ft_strchr(const char *s, int c)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		result_len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	result_len = end - start + 1;
	if (result_len <= 0)
		return (ft_strdup(""));
	result = (char *) malloc(result_len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, &s1[start], result_len);
	result[result_len] = '\0';
	return (result);
}
/*
int main(void)
{
	char *result;

	// Test 1: Trim spaces from both ends
	result = ft_strtrim("   Hello World   ", " ");
	printf("Test 1: '%s'\n", result); // Expected: 'Hello World'
	free(result);

	// Test 2: Trim specific characters from both ends
	result = ft_strtrim("!!!Hello!!!", "!");
	printf("Test 2: '%s'\n", result); // Expected: 'Hello'
	free(result);

	// Test 3: Trim characters only at the start
	result = ft_strtrim("###Hello", "#");
	printf("Test 3: '%s'\n", result); // Expected: 'Hello'
	free(result);

	// Test 4: Trim characters only at the end
	result = ft_strtrim("Hello###", "#");
	printf("Test 4: '%s'\n", result); // Expected: 'Hello'
	free(result);

	// Test 5: String only contains characters to trim
	result = ft_strtrim("xxxxx", "x");
	printf("Test 5: '%s'\n", result); // Expected: ''
	free(result);

	// Test 6: Empty string as input
	result = ft_strtrim("", " ");
	printf("Test 6: '%s'\n", result); // Expected: ''
	free(result);

	// Test 7: Trim set is empty
	result = ft_strtrim("Hello", "");
	printf("Test 7: '%s'\n", result); // Expected: 'Hello'
	free(result);

	// Test 8: Both string and set are empty
	result = ft_strtrim("", "");
	printf("Test 8: '%s'\n", result); // Expected: ''
	free(result);

	// Test 9: Trim non-existing characters
	result = ft_strtrim("Hello", "x");
	printf("Test 9: '%s'\n", result); // Expected: 'Hello'
	free(result);

	// Test 10: Null string input (s1 == NULL)
	result = ft_strtrim(NULL, " ");
	printf("Test 10: '%s'\n", result); // Expected: '(null)'
	free(result);

	// Test 11: Null trim set input (set == NULL)
	result = ft_strtrim("Hello", NULL);
	printf("Test 11: '%s'\n", result); // Expected: '(null)'
	free(result);

	// Test 12: Whitespace trim set
	result = ft_strtrim("\t\t\nHello World\n\t ", " \n\t");
	printf("Test 12: '%s'\n", result); // Expected: 'Hello World'
	free(result);

	// Test 13: Long string with multiple trim characters
	result = ft_strtrim("#####   Trim this   ####", "# ");
	printf("Test 13: '%s'\n", result); // Expected: 'Trim this'
	free(result);

	return 0;
}
*/
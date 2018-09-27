#include <stdlib.h>
#include <string.h>

char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((str = (char *)malloc(strlen(s1) + strlen(s2) + 1)) == NULL)
		return (NULL);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (tmp);
}

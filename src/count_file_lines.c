#include <stdio.h>

int	count_file_lines(FILE* file)
{
	int		count = 1;
	char	character;

	while ((character = fgetc(file)) != EOF)
	{
		if(character == '\n')
			count++;
	}

	return (count);
}

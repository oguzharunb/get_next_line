#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char *left_string;
	char		*buffer;
	char		*loc_of_newline;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	int ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	temp = ft_strjoin(left_string, buffer);
	free(left_string);
	free(buffer);
	loc_of_newline = ft_strchr(temp, '\n');
	if (!ret)
	{
		if (!loc_of_newline)
			return (NULL);
	}
	if (ret < BUFFER_SIZE)
		return (temp);
	if (!loc_of_newline)
	{
		left_string = temp;
		return (get_next_line(fd));
	}
	else
	{
		buffer = ft_substr(temp, 0, loc_of_newline - temp);
		left_string = ft_memdup(loc_of_newline + 1, ft_strlen(loc_of_newline + 1));
		free(temp);
		return (buffer);
	}
}

int main(void)
{
	int fd = open("text", O_RDONLY);
	char *result;
	result = get_next_line(fd);
	while (result)
	{
		printf("%s\n", result);
		result = get_next_line(fd);
	}

	return 0;
}

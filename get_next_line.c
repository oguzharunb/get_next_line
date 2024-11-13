#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"

size_t	ft_strlen(char *string)
{
	size_t	i;
	while (string[i])
		i++;
	return (i);
}

static void	free_strings(char *left_string_list)
{
	size_t	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (left_string_list[i])
			free(left_string_list[i]);
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*left_string[OPEN_MAX];
	char		*new_string;
	char		*new_line_loc;
	char		*tmp;
	int			ret;

	allocated = malloc(BUFFER_SIZE + 1);
	if (!allocated)
		return (NULL);
	ret = read(fd, allocated, BUFFER_SIZE);
	if (ret == -1)
	{
		free_strings(left_string[fd]);
		free(allocated);
		return (NULL);
	}
	else if (!ret)
		new_line_loc = ft_strchr(allocated, '\0');
	else
		new_line_loc = ft_strchr(allocated, '\n');
//--------------------------------
	// found new line!
	if (new_line_loc)
	{
		if (!left_string[fd])
		{
			if (ft_strlen(allocated) == new_line_loc - allocated)
				return (allocated);
			else
			{
				ft_substr(allocated, new_line_loc + 1, allocated - new_line_loc);
			}
		}
		else if ()
	}
	else
	{
		tmp = ft_strjoin(left_string[fd], allocated);
		free(left_string[fd]);
		free(allocated);
		left_string[fd] = tmp;
		return (get_next_line(fd));
	}
}
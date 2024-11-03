#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*cat_alctd_to_left(char *left_string, char *new_string)
{
	char *new_left_string;
	
	new_left_string = ft_strjoin(left_string, new_string);
	if (!new_left_string)
		return (NULL);
	free(left_string);
	free(new_string);
	return (new_left_string);
}

void	free_all_lefts(char **lefts)
{
	int	i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (lefts[i])
			free(lefts[i]);
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*left_s_list[OPEN_MAX];
	char		*allocated;
	ssize_t		ret;
	int			i;
	char		*new_line_loc;

	allocated = malloc((BUFFER_SIZE + 1) * sizeof(char));
	
	if (!allocated)
		return (NULL);
	ret = read(fd, allocated, BUFFER_SIZE);
	//if 0 end of file
	//if -1 couldnt read the file
	//if >0 read the file
	new_line_loc = ft_strchr(allocated, '\n');
	if (!new_line_loc)
	{
		left_s_list[fd] = cat_alctd_to_left(left_s_list[fd], allocated);
		if (left_s_list[fd])
		{
			free_all_lefts(left_s_list);
			return (NULL);
		}
		return (get_next_line(fd));
	}
	else
	{
		left_s_list[fd] = ft_memdup(new_line_loc + 1, ret - (new_line_loc - allocated));
		return (ft_substr(allocated, 0, new_line_loc - allocated));
	}
}

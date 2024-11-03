#include <stdlib.h>

char	*ft_strchr(const char *s, char c)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == c)
			return (tmp_s);
		tmp_s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*final_string;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	final_string = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!final_string)
		return (NULL);
	ft_memcpy(final_string, s1, s1_len);
	ft_memcpy(final_string + s1_len, s2, s2_len);
	final_string[s1_len + s2_len] = '\0';
	return (final_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char	*ft_memdup(const char *s, size_t len)
{
	register size_t	i;
	char			*allocated;

	allocated = malloc(sizeof(char) * (len));
	if (allocated == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		allocated[i] = s[i];
	allocated[i] = '\0';
	return (allocated);
}
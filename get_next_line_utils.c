#include <stdlib.h>
char	*ft_memdup(const char *s, size_t len)
{
	register size_t	i;
	char			*allocated;

	allocated = malloc(sizeof(char) * (len) + 1);
	if (allocated == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		allocated[i] = s[i];
	allocated[i] = '\0';
	return (allocated);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(const char *dest, const char *src)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!dest || !src)
	{
		if (src)
			return (ft_memdup(src, ft_strlen(src)));
		return (ft_memdup(dest, ft_strlen(dest)));
	}
	i = 0;
	j = 0;
	p = malloc(ft_strlen((char *)dest) + ft_strlen((char *)src) + 1);
	if (!p)
		return (NULL);
	while (dest[i] != '\0')
	{
		p[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		p[i + j] = src[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if ((unsigned int)ft_strlen(s) < start)
		return (ft_memdup("", 0));
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


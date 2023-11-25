#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}


char    *ft_calloc(int count)
{
		char	*str;
		int		i;

		if (count < 1)
			return (NULL);
		str = (char *)malloc(count * sizeof(char));
		if (!str)
			return (NULL);
		i = 0;
		while (i < count)
			str[i++] = 0;
		return (str);
}

char	*ft_strjoin(char const  *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dst = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free((void *)s1);
	return (dst);
}

char	*ft_strdup(char const *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	dst = (char *)malloc(i + 1);
	if (!dst)
		return (NULL);
	dst[i] = '\0';
	i--;
	while (i >= 0)
	{
		dst[i] = s1[i];
		i--;
	}
	return (dst);
}

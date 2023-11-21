#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char                    *dst;
        unsigned int    s_len;

        if (!s)
                return (NULL);
        s_len = ft_strlen(s);
        if (start >= s_len)
                return (ft_calloc(1, sizeof(char)));
        if (s_len - start <= len)
                len = s_len - start;
        dst = (char *)malloc(len * sizeof(char) + 1);
        if (!dst)
                return (NULL);
        ft_strlcpy(dst, s + start, len + 1);
        return (dst);
}
void    *ft_memset(void *b, int c, size_t len)
{
        size_t                  i;
        unsigned char   *str;

        str = (unsigned char *)b;
        i = 0;
        while (i < len)
        {
                str[i] = (unsigned char)c;
                i++;
        }
        return (b);
}
void    ft_bzero(void *s, size_t n)
{
        ft_memset(s, 0, n);
}
void    *ft_calloc(size_t count, size_t size)
{
        void    *str;

        str = (void *)malloc(count * size);
        if (!str)
                return (NULL);
        ft_bzero(str, (count * size));
        return (str);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  s_len;

        i = 0;
        s_len = ft_strlen(src);
        if (dstsize > 0)
        {
                while (src[i] && i < dstsize - 1)
                {
                        dst[i] = src[i];
                        i++;
                }
                if (i < dstsize)
                        dst[i] = '\0';
        }
        return (s_len);
}
char	*ft_strjoin(char const  *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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


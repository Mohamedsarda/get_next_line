/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:56:26 by msarda            #+#    #+#             */
/*   Updated: 2023/11/25 13:56:29 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *str, int len)
{
	char	*dst;
	int		i;

	if (!str || !len)
		return (NULL);
	i = 0;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (free(str), NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_get_buffer(int fd, char *dst)
{
	char	*buffer;
	int		bytes;

	if (!dst)
		dst = ft_strdup("");
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(dst), NULL);
	bytes = 1;
	while (bytes > 0)
	{
		if (!ft_strchr(dst, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 || (!dst[0] && bytes == 0))
			return (free(buffer), free(dst), NULL);
		buffer[bytes] = '\0';
		dst = ft_strjoin(dst, buffer);
	}
	free(buffer);
	return (dst);
}

static char	*ft_get_rest(char *str)
{
	char	*dst;
	int		len;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	len = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	i = ft_strlen(str) - len;
	dst = (char *)ft_calloc(i + 1);
	if (!dst)
		return (free(str), NULL);
	j = 0;
	while (j < i)
		dst[j++] = str[++len];
	dst[j] = '\0';
	return (dst);
}

static char	*ft_cutstr(char *str, char c)
{
	char	*dst;
	int		len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != (char )c)
		len++;
	if (str[len] == '\n')
		len++;
	dst = ft_strcpy(str, len);
	free(str);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*dst;

	if ((fd < 1 || fd > OPEN_MAX)
		&& (BUFFER_SIZE < 1 || BUFFER_SIZE > 10000000))
		return (NULL);
	line = ft_get_buffer(fd, str);
	str = ft_get_rest(line);
	dst = ft_cutstr(line, '\n');
	return (dst);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	get_next_line(fd);
// 	get_next_line(fd);
// }

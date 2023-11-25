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

static char	*ft_get_buffer(int fd, char *str)
{
	int		byte;
	char	*buffer;

	if (!str)
		str = ft_strdup("");
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_strchr(str, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0 && str)
			return (free(buffer), free(str), NULL);
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_get_rest(char *str)
{
	char	*dst;
	int		i;
	int		j;
	int		len;

	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	i = ft_strlen(str);
	j = i - len;
	dst = (char *)ft_calloc(j + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < j)
		dst[i++] = str[++len];
	dst[i] = '\0';
	return (dst);
}

static char	*ft_cutstr(char *str, int c)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != (char )c)
		len++;
	dst = (char *)ft_calloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*dst;

	if ((fd < 1 || fd > 10240) && (BUFFER_SIZE < 1 || BUFFER_SIZE > 10000000))
		return (NULL);
	line = ft_get_buffer(fd, str);
	str = ft_get_rest(line);
	dst = ft_cutstr(line, '\n');
	free(line);
	return (dst);
}

int main()
{
	int fd = open("test.txt", O_RDWR | O_CREAT);
	//
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	printf("\n[%s]\n", get_next_line(fd));
	close(fd);
}

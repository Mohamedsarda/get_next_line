#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	ft_strlen(const char *str);
char	*ft_strjoin(char const  *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_calloc(size_t count, size_t size);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
void    ft_bzero(void *s, size_t n);
void    *ft_memset(void *b, int c, size_t len);

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr(const char *s, int c);
char	*ft_strdup(char const *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(int count);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif

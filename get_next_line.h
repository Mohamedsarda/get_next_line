#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10240
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct l_list
{
	char	*str;
	struct l_list *next;
}	t_list;

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const  *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_calloc(int count);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:31 by msarda            #+#    #+#             */
/*   Updated: 2023/11/25 13:58:33 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strchr(const char *s, int c);
char	*ft_strdup(char const *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_calloc(int count);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif

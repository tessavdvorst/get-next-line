/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 16:21:12 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/06/15 18:21:10 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFERSIZE
#  define BUFFERSIZE 4
# endif

# define MAX_FD 1024

int		find_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2, char c);
int		ft_strcorrect(char *str, char c);
int		ft_strlen(char *str, char c);
void	ft_strcpy(char *dst, char *src);
int		get_next_line(int fd, char **line);

#endif

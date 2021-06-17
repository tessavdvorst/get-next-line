/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:02:25 by Tessa         #+#    #+#                 */
/*   Updated: 2021/06/15 18:17:30 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

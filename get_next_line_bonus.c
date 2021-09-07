/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:03:15 by Tessa         #+#    #+#                 */
/*   Updated: 2021/09/07 15:05:12 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			read_bytes;
	char		*line;
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		line = ft_strjoin(line, buffer[fd], '\n');
		if (find_new_line(buffer[fd]))
		{
			ft_strcorrect(buffer[fd], '\n');
			return (line);
		}
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[fd][read_bytes] = '\0';
	}
	return (NULL);
}

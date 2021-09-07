/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 10:10:38 by Tessa         #+#    #+#                 */
/*   Updated: 2021/09/07 14:49:19 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			read_bytes;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		line = ft_strjoin(line, buffer, '\n');
		if (find_new_line(buffer))
		{
			ft_strcorrect(buffer, '\n');
			return (line);
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
	}
	return (NULL);
}

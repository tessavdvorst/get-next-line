/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:03:15 by Tessa         #+#    #+#                 */
/*   Updated: 2021/11/17 12:39:24 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_and_correct(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	ft_strcorrect(buffer);
	return (temp);
}

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
		if (buffer[fd][0] != '\0')
		{
			if (find_new_line(buffer[fd]))
			{
				line = update_and_correct(line, buffer[fd]);
				return (line);
			}
			line = ft_strjoin(line, buffer[fd]);
		}
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][read_bytes] = '\0';
		if (line && read_bytes == 0)
			return (line);
	}
	return (NULL);
}

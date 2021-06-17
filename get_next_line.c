/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 10:10:38 by Tessa         #+#    #+#                 */
/*   Updated: 2021/06/15 18:21:15 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Description:
** This function returns a line which read from a
** file descriptor, without the newline.
** When called in a loop, this functions reads one
** line at a time from the file descriptor
** until the End Of File (EOF) has been reached.
**
** Returns:
**  1 : A line has been read.
**  0 : EOF has been reached.
** -1 : An error happened.
*/

int	get_next_line(int fd, char **line)
{
	int			read_bytes;
	static char	buffer[BUFFERSIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFERSIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		*line = ft_strjoin(*line, buffer, '\n');
		if (find_new_line(buffer))
		{
			ft_strcorrect(buffer, '\n');
			return (1);
		}
		read_bytes = read(fd, buffer, BUFFERSIZE);
		if (read_bytes == -1)
			return (-1);
		buffer[read_bytes] = '\0';
	}
	return (0);
}

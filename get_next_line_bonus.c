/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:03:15 by Tessa         #+#    #+#                 */
/*   Updated: 2021/06/15 18:17:19 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Description:
** This function returns a line which read from a file descriptor,
** without the newline. When called in a loop,
** this functions reads one line at a time from the file descriptor
** until the End Of File (EOF) has been reached.
** In addition, this function is able to
** handle multiple file descriptors.
**
** Returns:
**  1 : A line has been read.
**  0 : EOF has been reached.
** -1 : An error happened.
*/

int	get_next_line(int fd, char **line)
{
	int			read_bytes;
	static char	buffer[MAX_FD][BUFFERSIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFERSIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		*line = ft_strjoin(*line, buffer[fd], '\n');
		if (find_new_line(buffer[fd]))
		{
			ft_strcorrect(buffer[fd], '\n');
			return (1);
		}
		read_bytes = read(fd, buffer[fd], BUFFERSIZE);
		if (read_bytes == -1)
			return (-1);
		buffer[fd][read_bytes] = '\0';
	}
	return (0);
}

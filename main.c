/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 16:30:16 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/09/07 15:14:46 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	fd = open("bible.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);

	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}

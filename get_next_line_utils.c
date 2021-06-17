/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 10:36:31 by Tessa         #+#    #+#                 */
/*   Updated: 2021/06/15 18:20:46 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Description:
** This function takes a string, iterates through it and
** looks if there's a newline character in it.
**
** Return:
** 1: a newline character is found.
** 0: there is no newline character.
*/

int	find_new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Description:
** This function counts the amount of characters of a given string.
** When the charachter is equal to c, the amount of characters
** will be returned up until that character.
*/

int	ft_strlen(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

/* Description:
** This function copies the content of src to dst if src exists.
*/

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

/* Description:
** This function searches for c in str.
** If c is found, the remaining part after c will be moved
** to the front in str.
**
** Returns:
** 1: c is found in str.
** 0: c is not found in str.
*/

int	ft_strcorrect(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			ft_strcpy(str, str + i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

/* Description:
** This function copies str1 and str2 together up
** until c in a newly allocated string.
*/

char	*ft_strjoin(char *str1, char *str2, char c)
{
	int		i;
	int		len_str1;
	int		len_str2;
	char	*new;

	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1, c);
	len_str2 = ft_strlen(str2, c);
	new = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!new)
		return (NULL);
	ft_strcpy(new, str1);
	i = 0;
	while (str2[i] != '\0' && str2[i] != c)
	{
		new[len_str1] = str2[i];
		len_str1++;
		i++;
	}
	new[len_str1] = '\0';
	free(str1);
	return (new);
}

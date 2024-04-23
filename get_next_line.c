/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:49:30 by bkaleta           #+#    #+#             */
/*   Updated: 2024/04/23 13:11:34 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	ft_read_line(int fd, char *buffor, char *hold)
{
	int			read_char;
	char		*tmp;

	read_char = 1;
	while (read_char != '\0')
	{
		read_char = read(fd, buffor, BUFFER_SIZE);
		if (read_char == -1)
			return (0);
		else if (read_char == 0)
			break ;
		buffor[read_char] = '\0';
		if (!hold)
			hold = ft_strdup("");
		tmp = hold;
		hold = ft_strjoin(tmp, buffor);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffor, '\n'))
			break ;
	}
	return (hold);
}

static char	*ft_trim(char *line)
{
	size_t	count;
	char	*hold;

	count = 0;
	
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffor;
	static char		*hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffor = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffor)
		return (0);
	line = ft_read_line(fd, buffor, hold);
	free(buffor)
	buffor = NULL;
	if (!line)
		return (0);
	hold = ft_trim(line);
	return (line);
}

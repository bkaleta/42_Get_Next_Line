/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:49:30 by bkaleta           #+#    #+#             */
/*   Updated: 2024/04/24 14:50:36 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_wholeline(int fd, char *buffor, char *rest)
{
	int		i;
	char	*char_temp;

	i = 1;
	while (i != '\0')
	{
		i = read(fd, buffor, BUFFER_SIZE);
		if (i == -1)
			return (0);
		else if (i == 0)
			break ;
		buffor[i] = '\0';
		if (!rest)
			rest = ft_strdup("");
		char_temp = rest;
		rest = ft_strjoin(char_temp, buffor);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buffor, '\n'))
			break ;
	}
	return (rest);
}

static char	*ft_trim(char *line)
{
	size_t	count;
	char	*rest;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	rest = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line[count + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffor;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffor = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffor)
		return (0);
	line = ft_wholeline(fd, buffor, rest);
	free(buffor);
	buffor = NULL;
	if (!line)
		return (NULL);
	rest = ft_trim(line);
	return (line);
}

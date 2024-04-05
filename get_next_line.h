/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:49:33 by bkaleta           #+#    #+#             */
/*   Updated: 2024/04/05 11:06:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//get_next_line_utils.c
int		ft_strlen(char *str);
char	*ft_strdup(char *str);

//get_next_line.c
char	*get_next_line(int fd);

#endif
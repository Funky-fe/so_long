/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:51 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/14 13:55:29 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	find_nl(char *resto)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (resto[i])
	{
		if (new_line)
			resto[j++] = resto[i];
		if (resto[i] == '\n')
			new_line = 1;
		resto[i] = '\0';
		i++;
	}
	return (new_line);
}

char	*ft_strjoin(char *line, char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	while (line && line[j])
		str[i++] = line[j++];
	j = 0;
	while (buff && buff[j])
	{
		str[i] = buff[j++];
		if (str[i++] == '\n')
			break ;
	}
	str[i] = '\0';
	free (line);
	return (str);
}

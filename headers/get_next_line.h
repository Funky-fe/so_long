/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:35:50 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/25 18:56:38 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*			FUNC			*/
int		find_nl(char *resto);
char	*ft_strjoin(char *line, char *buff);
size_t	gnl_strlen(char *s);
/*			MAIN			*/
char	*get_next_line(int fd);

#endif
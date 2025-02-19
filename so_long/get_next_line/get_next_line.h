/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:27:37 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/19 15:08:51 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_buff
{
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		bytes_read;
}			t_buff;

char		*get_next_line(int fd);
char		*ft_strjoin_(char *s1, char *s2);
char		*ft_realloc(char *old_str, char *append);
int			init_buffer(t_buff *buff);
char		*read_from_buffer(t_buff *buff, char *line);
size_t		ft_strlen_(char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif

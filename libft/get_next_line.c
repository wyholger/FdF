/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:01:26 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:27 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mr_cleaner(char **a)
{
	if (*a)
	{
		free(*a);
		*a = NULL;
	}
	return (0);
}

char	*check_memder(char *member, char **line)
{
	char	*p_n_l;
	char	*tmp;

	p_n_l = NULL;
	if (member)
	{
		p_n_l = ft_strchr(member, '\n');
		if (p_n_l)
		{
			*p_n_l++ = '\0';
			tmp = *line;
			*line = ft_strjoin(member, "");
			member = ft_memmove(member, p_n_l, ft_strlen(p_n_l));
			member[ft_strlen(p_n_l)] = '\0';
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(member, "");
			ft_bzero(member, ft_strlen(member));
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (p_n_l);
}

int	bufer_nl(char *bufer, char **pointer_n_line, char **member)
{
	char	*tmp;

	*pointer_n_line = ft_strchr(bufer, '\n');
	if (*pointer_n_line)
	{
		*(*pointer_n_line) = '\0';
		*pointer_n_line = *pointer_n_line + 1;
		if (!(*pointer_n_line == '\0'))
		{
			tmp = *member;
			*member = ft_strjoin(*pointer_n_line, "");
			mr_cleaner(&tmp);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*member;
	char		bufer[BUFFER_SIZE + 1];
	int			read_len;
	char		*pointer_n_line;
	char		*tmp;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE < 1)
		return (-1);
	read_len = 1;
	pointer_n_line = check_memder(member, line);
	while (!pointer_n_line && read_len)
	{
		read_len = read(fd, bufer, BUFFER_SIZE);
		if (read_len == -1)
			return (-1);
		bufer[read_len] = '\0';
		bufer_nl(&bufer[0], &pointer_n_line, &member);
		tmp = *line;
		*line = ft_strjoin(*line, bufer);
		mr_cleaner(&tmp);
	}
	if (read_len == 0)
		return (mr_cleaner(&member));
	return (1);
}

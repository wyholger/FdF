/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:01:06 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:07 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = -1;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)ch)
			flag = i;
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	if (flag == -1)
		return (NULL);
	return ((char *)str + i - (i - flag));
}

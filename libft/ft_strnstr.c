/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:01:03 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:04 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big_str, const char *small_str, size_t len)
{
	size_t		i;
	size_t		p;
	size_t		flag;

	flag = 0;
	i = 0;
	p = 0;
	if (ft_strlen(small_str) > ft_strlen(big_str))
		return (NULL);
	if (ft_strlen(small_str) == 0)
		return ((char *)big_str);
	while (big_str[i] && i + ft_strlen(small_str) <= len)
	{
		while (big_str[i] == small_str[p])
		{
			i++;
			p++;
			if (small_str[p] == '\0')
				return ((char *)big_str + i - p);
		}
		p = 0;
		flag++;
		i = flag;
	}
	return (NULL);
}

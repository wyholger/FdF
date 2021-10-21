/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:47 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:48 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	len_src;

	n = 0;
	i = 0;
	i = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (i > size || size == 0)
		return (size + len_src);
	while (i < size - 1 && src[n])
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	while (src[n])
	{
		i++;
		n++;
	}
	return (i);
}

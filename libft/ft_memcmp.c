/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:01 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:01 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*parr1;
	unsigned char	*parr2;
	int				result;

	parr1 = (unsigned char *)arr1;
	parr2 = (unsigned char *)arr2;
	while (n--)
	{
		if (parr1[0] != parr2[0])
		{
			result = parr1[0] - parr2[0];
			return (result);
		}
		parr1++;
		parr2++;
	}
	return (0);
}

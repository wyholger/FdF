/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:08 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:08 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char		*temp;
	unsigned char		*tempdest;
	size_t				i;

	i = 0;
	temp = (unsigned char *)source;
	tempdest = (unsigned char *)dest;
	if (!dest && !source)
	{
		return (NULL);
	}
	if (dest > source)
	{
		while (n-- > 0)
			tempdest[n] = temp[n];
	}
	else
	{
		while (i < n)
		{
			tempdest[i] = temp[i];
			i++;
		}
	}
	return (dest);
}

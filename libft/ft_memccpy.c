/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:59:55 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 17:59:55 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*tempdes;
	size_t			i;
	unsigned char	stop;

	i = 0;
	temp = (unsigned char *)source;
	tempdes = (unsigned char *)destination;
	stop = (unsigned char) c;
	while (n)
	{
		*tempdes = *temp;
		i++;
		if (*temp == stop)
		{
			return (destination + i);
		}		
		tempdes++;
		temp++;
		n = n - sizeof(char);
	}
	return (NULL);
}

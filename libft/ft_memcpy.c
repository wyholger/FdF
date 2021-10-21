/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:05 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:06 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char	*temp;
	char	*tempdes;

	temp = (char *)source;
	tempdes = destination;
	if (!destination && !source)
	{
		return (NULL);
	}
	while (n)
	{
		*tempdes = *temp;
		tempdes++;
		temp++;
		n = n - sizeof(char);
	}
	return (destination);
}

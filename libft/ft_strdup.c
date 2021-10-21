/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:39 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:39 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy_str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen ((char *)str);
	copy_str = malloc(sizeof(char) * (len + 1));
	if (copy_str == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		copy_str[i] = str[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:01:14 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:15 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	c;

	c = 0;
	i = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) > len)
		sub = malloc (sizeof(char) * len + 1);
	else
		sub = malloc (sizeof(char) * ft_strlen(s) - start + 1);
	if (!sub)
		return (NULL);
	while (s[i] && c < len)
		sub[c++] = s[i++];
	sub[c] = '\0';
	return (sub);
}

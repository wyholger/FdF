/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:01:11 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:12 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*endcat(char const *str, char const *set)
{
	size_t	pi;
	size_t	o;
	int		i;

	pi = ft_strlen(str) - 1;
	o = 0;
	i = (int)pi;
	while (set[o] && i >= 0)
	{
		if (str[i] == set[o])
		{
			o = 0;
			i--;
		}
		else
			o++;
	}
	i++;
	return ((char *)str + i);
}

static char	*startcat(char const *str, char const *set)
{
	int		i;
	size_t	o;

	i = 0;
	o = 0;
	while (set[o])
	{
		if (str[i] == set[o])
		{
			o = 0;
			i++;
		}
		else
			o++;
	}
	return ((char *)str + i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strstart;
	char	*strend;
	int		len;
	char	*rezult;

	if (!s1 || !set)
		return (NULL);
	strstart = startcat(s1, set);
	strend = endcat(strstart, set);
	len = strend - strstart;
	if (strstart > strend)
	{
		rezult = malloc (sizeof(char) * 1);
		if (!rezult)
			return (NULL);
		rezult[0] = '\0';
		return (rezult);
	}
	rezult = ft_substr(s1, strstart - s1, len);
	if (!rezult)
		return (NULL);
	return (rezult);
}

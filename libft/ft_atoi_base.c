/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:58:33 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:05:10 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	isdigit(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static char	toupper(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 32);
	return (c);
}

static int	ternary_ret(char *str, int i)
{
	if (str[i] <= '9')
		return (str[i] - '0');
	return (toupper(str[i]) - 55);
}

int	ft_atoi_base(char *str, int str_base)
{
	int		negativ;
	int		resilt;
	int		i;

	negativ = 1;
	resilt = 0;
	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		negativ = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(toupper(str[i])))
			return (-1);
		resilt *= str_base;
		resilt += ternary_ret(str, i);
		i++;
	}
	return (resilt * negativ);
}

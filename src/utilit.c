/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:36:09 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/17 18:11:19 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	cleaner_char(char **for_split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (for_split[i])
			free(for_split[i]);
		i++;
	}
	if (for_split)
		free(for_split);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	max_float(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	abs_float(float a)
{
	if (a < 0)
		return (a * -1);
	else if (a > 0)
		return (a);
	return (0);
}

float	module_difference(int a, int b)
{
	if (a - b > 0)
	{
		if (a == b)
			return (0);
		if (b > a)
			return ((a - b) * -1);
		else
			return (a - b);
	}
	else
	{
		if (a == b)
			return (0);
		if (b > a)
			return ((b - a) * -1);
		else
			return (b - a);
	}
}

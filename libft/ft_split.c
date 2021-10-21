/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:00:27 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:28 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mr_cleaner(char **mass, int p)
{
	int	i;

	i = 0;
	while (i <= p)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
	return (NULL);
}

static char	**allocation(char **mass, char const *s, \
	char c)
{
	int	i;
	int	len_str;
	int	mass_couner;

	i = 0;
	len_str = 0;
	mass_couner = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
			{
				len_str++;
				i++;
			}	
			mass[mass_couner] = (char *)malloc(sizeof(char) * (len_str + 1));
			if (!mass[mass_couner])
				return (mr_cleaner(mass, mass_couner));
			mass_couner++;
		}
	}
	return (mass);
}

static int	counter_str(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (counter);
}

static char	**str_copy(char **mass, char const *s, char c)
{
	int	i;
	int	i_str;
	int	num_str;

	num_str = 0;
	i = 0;
	i_str = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				mass[num_str][i_str++] = s[i++];
			mass[num_str][i_str] = '\0';
			num_str++;
			i_str = 0;
		}
	}
	mass[num_str] = NULL;
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		counter;

	if (!s)
		return (NULL);
	counter = counter_str(s, c);
	mass = (char **)malloc((counter + 1) * sizeof(char *));
	if (!mass)
		return (NULL);
	mass = allocation(mass, s, c);
	if (!mass)
		return (NULL);
	mass = str_copy(mass, s, c);
	return (mass);
}

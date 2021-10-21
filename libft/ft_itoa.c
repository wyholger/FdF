/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:59:25 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 17:59:27 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_depth(long int long_n, int single)
{
	int		count;

	count = 0;
	if (long_n == 0)
		return (count + 1);
	while (long_n > 0)
	{
		long_n = long_n / 10;
		count++;
	}
	if (single < 0)
		count++;
	return (count);
}

int	singl(long int long_n)
{
	int	single;

	single = 1;
	if (long_n < 0)
		single = -1;
	return (single);
}

char	*resulting(char *rezult, int count, long int long_n, int single)
{
	rezult[count] = '\0';
	if (long_n == 0)
		rezult[0] = '0';
	while (long_n > 0)
	{
		rezult[--count] = (long_n % 10) + '0';
		long_n = long_n / 10;
	}
	if (single < 0)
		rezult[--count] = '-';
	return (rezult);
}

char	*ft_itoa(int n)
{
	long int	long_n;
	char		*rezult;
	int			count;
	int			single;

	long_n = (long int)n;
	single = singl(long_n);
	if (single < 0)
		long_n = long_n * -1;
	count = number_depth(long_n, single);
	rezult = malloc ((count + 1) * sizeof(char));
	if (!rezult)
		return (NULL);
	rezult = resulting(rezult, count, long_n, single);
	return (rezult);
}

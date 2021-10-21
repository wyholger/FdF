/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:59:50 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 18:06:08 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content_1, int content_2, int content_3, int content_4)
{
	t_list	*begin;

	begin = (t_list *)malloc(sizeof(t_list));
	if (!begin)
		return (NULL);
	begin->next = NULL;
	begin->right = NULL;
	begin->lower = NULL;
	begin->x = content_1;
	begin->y = content_2;
	begin->z = content_3;
	begin->color = content_4;
	begin->x_t = 0;
	begin->y_t = 0;
	begin->z_t = 0;
	return (begin);
}

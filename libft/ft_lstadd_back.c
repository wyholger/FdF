/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:59:28 by wyholger          #+#    #+#             */
/*   Updated: 2021/09/27 17:59:29 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_title;

	if (!lst || !new)
		return ;
	last_title = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last_title->next)
	{
		last_title = last_title->next;
	}
	last_title->next = new;
}

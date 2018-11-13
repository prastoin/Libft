/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:23:09 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 17:30:09 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*elem;

	tmp = lst;
	while (tmp != NULL)
	{
		if (!(elem = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		elem = f(tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

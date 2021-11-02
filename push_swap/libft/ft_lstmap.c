/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:08:25 by mda-silv          #+#    #+#             */
/*   Updated: 2021/02/22 09:35:46 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ptr;
	t_list *aux;

	if (!lst || !f)
		return (0);
	ptr = 0;
	while (lst)
	{
		if (!(aux = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&ptr, del);
			return (0);
		}
		ft_lstadd_back(&ptr, aux);
		lst = lst->next;
	}
	return (ptr);
}

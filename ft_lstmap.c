/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:37:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/27 21:42:29 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	if (f == NULL || lst == NULL)
		return (NULL);
	if (!(temp = (t_list *)malloc(sizeof(t_list) * sizeof(lst))))
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}

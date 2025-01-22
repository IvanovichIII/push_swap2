/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:51 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/20 13:14:21 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlastprev(t_list *lst)
{
	t_list	*curr;
	t_list	*prev;

	curr = lst;
	prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

void	rra(t_list **a, int wri)
{
	t_list	*last;
	t_list	*prev;

	last = ft_lstlast(*a);
	prev = ft_lstlastprev(*a);
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (wri == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int wri)
{
	t_list	*last;
	t_list	*prev;

	last = ft_lstlast(*b);
	prev = ft_lstlastprev(*b);
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (wri == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

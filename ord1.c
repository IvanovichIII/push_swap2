/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:26 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/20 13:22:53 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int wri)
{
	int		i;
	t_list	*temp;

	temp = *a;
	i = temp->content;
	temp->content = temp->next->content;
	temp->next->content = i;
	if (wri == 1)
		ft_printf("sa\n");
}

void	sb(t_list **b, int wri)
{
	int		i;
	t_list	*temp;

	temp = *b;
	i = temp->content;
	temp->content = temp->next->content;
	temp->next->content = i;
	if (wri == 1)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (*b != NULL)
	{
		*b = (*b)->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
	}
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (*a != NULL)
	{
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);
	}
	ft_printf("pb\n");
}

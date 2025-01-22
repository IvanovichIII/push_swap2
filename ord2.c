/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:08:34 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/20 13:14:07 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int wri)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	if (wri == 1)
		ft_printf("ra\n");
}

void	rb(t_list **b, int wri)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	if (wri == 1)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

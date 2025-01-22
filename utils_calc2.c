/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:52 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 09:43:53 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_top(t_list *node_b)
{
	if (node_b->index > node_b->target->index)
		return (node_b->index + 1);
	else
		return (node_b->target->index + 1);
}

int	calculate_cost_bottom(t_list *node_b)
{
	if (node_b->index > node_b->target->index)
		return (node_b->index + 1);
	else
		return (node_b->target->index + 1);
}

int	calculate_cost_mixed(t_list *node_b, t_list *a, t_list *b)
{
	int	cost;

	cost = 1;
	if (node_b->top == 0)
		cost += node_b->index;
	else
		cost += ft_lstsize(b) - node_b->index;
	if (node_b->target->top == 0)
		cost += node_b->target->index;
	else
		cost += ft_lstsize(a) - node_b->target->index;
	return (cost);
}

int	calculate_cost(t_list *node_b, t_list *a, t_list *b)
{
	if (node_b->top == 0 && node_b->target->top == 0)
		return (calculate_cost_top(node_b));
	else if (node_b->top == 1 && node_b->target->top == 1)
		return (calculate_cost_bottom(node_b));
	else
		return (calculate_cost_mixed(node_b, a, b));
}

void	calc_mov(t_list *a, t_list *b)
{
	t_list	*temp_b;

	temp_b = b;
	while (temp_b)
	{
		temp_b->cost = calculate_cost(temp_b, a, b);
		temp_b = temp_b->next;
	}
}

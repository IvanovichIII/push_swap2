/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:16:04 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/22 20:40:22 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iter_a2(t_list **a, t_list **b, int *pivots)
{
	if ((*a)->content <= pivots[0] || (*a)->content <= pivots[2])
	{
		pb(a, b);
		rb(b, 1);
	}
	else if ((*a)->content > pivots[1] || (*a)->content > pivots[3])
		ra(a, 1);
	else if ((*a)->content <= pivots[4] || (*a)->content <= pivots[6])
	{
		pb(a, b);
		rb(b, 1);
	}
	else if ((*a)->content > pivots[5] || (*a)->content > pivots[7])
		ra(a, 1);
	else if ((*a)->content > pivots[8] || (*a)->content > pivots[10])
	{
		pb(a, b);
		rb(b, 1);
	}
	else if ((*a)->content <= pivots[11])
		ra(a, 1);
	else
		pb(a, b);
}

void	iter_a(t_list **a, t_list **b, int *pivots)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	while (*a && size_a > 3)
	{
		piv(*a, pivots);
		iter_a2(a, b, pivots);
		size_a = ft_lstsize(*a);
	}
}

t_list	*find_max(t_list *lst)
{
	t_list	*temp;
	t_list	*max_node;

	if (!lst)
		return (NULL);
	temp = lst;
	max_node = lst;
	while (temp)
	{
		if (temp->content > max_node->content)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

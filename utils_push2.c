/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:24 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 09:29:30 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piv(t_list *list, int *piv1, int *piv2)
{
	int		size;
	t_list	*temp;
	int		*arr;

	temp = list;
	size = ft_lstsize(temp);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return ;
	cp_lst_arr(list, arr);
	bubble_sort(arr, size);
	*piv1 = arr[size / 3];
	*piv2 = arr[2 * size / 3];
}

t_list	*find_min(t_list *lst)
{
	t_list	*temp;
	t_list	*min_node;

	if (!lst)
		return (NULL);
	temp = lst;
	min_node = lst;
	while (temp)
	{
		if (temp->content < min_node->content)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

void	move_b(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->top == 0 && cheapest->target->top == 0)
		while (*b != cheapest && *a != cheapest->target)
			rr(a, b);
	else if (cheapest->top == 1 && cheapest->target->top == 1)
		while (*b != cheapest && *a != cheapest->target)
			rrr(a, b);
	if (cheapest->top == 0)
		while (*b != cheapest)
			rb(b, 1);
	else
		while (*b != cheapest)
			rrb(b, 1);
	if (cheapest->target->top == 0)
		while (*a != cheapest->target)
			ra(a, 1);
	else
		while (*a != cheapest->target)
			rra(a, 1);
	pa(a, b);
}

void	five_sort(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	small_sort(a);
	
}

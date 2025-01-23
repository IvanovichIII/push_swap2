/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:24 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/22 20:39:45 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	piv(t_list *list, int *piv1, int *piv2)
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
 }*/

void	piv(t_list *list, int *pivots)
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
	pivots[0] = arr[size / 13];
	pivots[1] = arr[2 * size / 13];
	pivots[2] = arr[3 * size / 13];
	pivots[3] = arr[4 * size / 13];
	pivots[4] = arr[5 * size / 13];
	pivots[5] = arr[6 * size / 13];
	pivots[6] = arr[7 * size / 13];
	pivots[7] = arr[8 * size / 13];
	pivots[8] = arr[9 * size / 13];
	pivots[9] = arr[10 * size / 13];
	pivots[10] = arr[11 * size / 13];
	pivots[11] = arr[12 * size / 13];
	free(arr);
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
	int	min;
	int	max;

	min = find_min(*a)->content;
	max = find_max(*a)->content;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content == min || (*a)->content == max)
			pb(a, b);
		else
			ra(a, 1);
	}
	small_sort(a);
	if ((*b)->content < (*b)->next->content)
		sb(b, 1);
	pa(a, b);
	ra(a, 1);
	pa(a, b);
}

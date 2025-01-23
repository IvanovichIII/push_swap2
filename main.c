/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:47 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/22 20:14:05 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **a)
{
	t_list	*temp;
	t_list	*max;
	int		i;

	temp = *a;
	i = INT_MIN;
	while (temp)
	{
		if (i < temp->content)
		{
			i = temp->content;
			max = temp;
		}
		temp = temp->next;
	}
	if (*a == max)
	{
		ra(a, 1);
	}
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->content > (*a)->next->content)
		sa(a, 1);
}

/*void	iter_a(t_list **a, t_list **b, int *piv1, int *piv2)
  {
  int	size_a;

  size_a = ft_lstsize(*a);
  while (*a && size_a > 3)
  {
  piv(*a, piv1, piv2);
  if ((*a)->content <= *piv1)
  {
  pb(a, b);
  rb(b, 1);
  }
  else if ((*a)->content > *piv2)
  ra(a, 1);
  else
  pb(a, b);
  size_a = ft_lstsize(*a);
  }
  }*/

void	big_short(t_list **a, t_list **b)
{
	calc_target(*a, *b);
	calc_index(*a);
	calc_index(*b);
	calc_mov(*a, *b);
	move_b(a, b);
}

/*void	push_swap(t_list **a, t_list **b)
  {
  int		piv1;
  int		piv2;
  t_list	*lst;

  if (find_err(a, b) == 1)
  return ;
  if (ft_lstsize(*a) <= 3)
  small_sort(a);
  else
  {
  iter_a(a, b, &piv1, &piv2);
  small_sort(a);
  while (ft_lstsize(*b) != 0)
  big_short(a, b);
  lst = find_min(*a);
  while ((*a) != lst)
  rra(a, 1);
  }
  }*/

void	push_swap(t_list **a, t_list **b)
{
	int		*piv;
	t_list	*lst;

	piv = malloc(18 * sizeof(int));
	if (find_err(a, b) == 1)
		return ;
	if (ft_lstsize(*a) <= 3)
		small_sort(a);
	if (ft_lstsize(*a) == 5)
		five_sort(a, b);
	else
	{
		iter_a(a, b, piv);
		small_sort(a);
		while (ft_lstsize(*b) != 0)
			big_short(a, b);
		lst = find_min(*a);
		while ((*a) != lst)
			rra(a, 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (calc_none_err(argv) == 1 || calc_ent_err(argc, argv) == 1)
		return (1);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	if (start_a(a, argv))
		return (1);
	push_swap(a, b);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}

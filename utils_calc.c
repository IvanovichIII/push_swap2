/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:28:09 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 09:29:00 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_target(t_list *a, t_list *b)
{
	t_list	*temp_b;

	temp_b = b;
	while (temp_b)
	{
		temp_b->target = find_closest(a, temp_b->content);
		temp_b = temp_b->next;
	}
}

void	calc_index(t_list *lst)
{
	t_list	*temp;
	int		size;
	int		i;

	temp = lst;
	size = ft_lstsize(lst);
	i = 0;
	while (temp)
	{
		temp->index = i;
		if (i / 2 < size)
			temp->top = 0;
		else
			temp->top = 1;
		i++;
		temp = temp->next;
	}
}

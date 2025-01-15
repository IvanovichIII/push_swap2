/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:26 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/14 18:04:25 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*next;
	int		temp_val;

	if (ft_lstsize(*stack) < 2){
		return (0);
	first = *stack;
	next = head->next;
	if (!head && !next)
		return (-1);
	temp_val = first->value;
	
}

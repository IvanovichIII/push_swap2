/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:37:09 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/15 09:38:33 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(stack **list)
{
	int		i;
	stack	*temp;

	temp = *list;
	i = 0;
	while (temp)
	{
		ft_printf("Node %d: %d\n", i, temp->content);
		temp = temp->next;
		i++;
	}
	ft_printf("\n");
}

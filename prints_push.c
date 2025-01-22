/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:32:03 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 09:32:07 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **list)
{
	int		i;
	t_list	*temp;

	temp = *list;
	i = 0;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
		i++;
	}
}

void	print_list_targ(t_list **list)
{
	int		i;
	t_list	*temp;

	temp = *list;
	i = 0;
	while (temp)
	{
		ft_printf("Node %d: %d->%d\n", i, temp->content, temp->target->content);
		temp = temp->next;
		i++;
	}
	ft_printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:26 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/15 13:36:53 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sa(t_list **a)
{
	int		i;
	t_list	*temp;

	temp = *a;
	i = temp->content;
	temp->content = temp->next->content;
	temp->next->content = i;
}

void	sb(t_list **b)
{
	int		i;
	t_list	*temp;

	temp = *b;
	i = temp->content;
	temp->content = temp->next->content;
	temp->next->content = i;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

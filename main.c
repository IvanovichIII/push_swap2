/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:47 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/15 13:17:22 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int start_a(t_list **a, int argc, char **argv)
{
	char	**args;
	int		i;

	//i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = &argv[1];
	}
	i = 0;
	while (args[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	return (0);
}

void print_list(t_list **list)
{
	int		i;
	t_list	*temp;

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

int main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	start_a(a, argc, argv);
	print_list(a);
	return (0);
}

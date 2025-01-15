/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:03:47 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/15 09:41:38 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int start_a(stack **a, int argc, char **argv)
{
	stack	*new;
	char	**args;
	int		i;
	int		*cont;

	if (argc == 3)
		args = ft_split(argv[2], ' ');
	else
		i = 1;
	args = argv;
	cont = malloc(sizeof(int));
	if (!cont)
		return (1);
	while (args[i])
	{
		*cont = ft_atoi(args[i]);
		ft_lstadd_back(a, ft_lstnew(cont));
		i++;
	}
	if (args = 0)
		return (1);
}

int	main(int argc, char **argv)
{
	stack	**a;
	stack	**b;

	if (argc < 2)
		return (1);
	*a = start_a(a, argc, argv);
	*b = NULL;
	print_list(a);	

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:04 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 17:11:53 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_ord_err(t_list *a)
{
	t_list	*temp;
	int		prev_value;

	if (!a)
		return (0);
	temp = a;
	prev_value = temp->content;
	while (temp && temp->next)
	{
		temp = temp->next;
		if (prev_value > temp->content)
			return (0);
		prev_value = temp->content;
	}
	return (1);
}

int	calc_dup_err(t_list *a)
{
	int	i;
	int	*arr;

	arr = malloc(ft_lstsize(a) * sizeof(int));
	if (!arr)
		return (1);
	cp_lst_arr(a, arr);
	bubble_sort(arr, ft_lstsize(a));
	i = 0;
	while (i < ft_lstsize(a) - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free (arr);
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	free (arr);
	return (0);
}

int	calc_ent_err(int argc, char **argv)
{
	if (argc == 2)
		return (validate_arg(argv[1]));
	else
		return (validate_args(argc, argv));
}

int	calc_none_err(char **argv)
{
	if (argv[1] == NULL)
		return (1);
	if (ft_strlen(argv[1]) == 0)
		return (1);
	return (0);
}

int	find_err(t_list **a, t_list **b)
{
	if (calc_ord_err(*a) == 1)
		return (1);
	if (calc_dup_err(*a) == 1)
		return (1);
	if (*b)
		return (1);
	return (0);
}

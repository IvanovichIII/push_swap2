/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:13 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 09:29:18 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_a(t_list **a, char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			if (ft_atoi2(args[j]) == -1)
			{
				ft_printf("Error\n");
				return (1);
			}
			ft_lstadd_back(a, ft_lstnew(ft_atoi(args[j])));
			j++;
		}
		i++;
	}
	return (0);
}

void	cp_lst_arr(t_list *list, int *arr)
{
	int	i;

	i = 0;
	while (list)
	{
		arr[i++] = list->content;
		list = list->next;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_list	*find_closest(t_list *a, int target)
{
	t_list	*temp;
	t_list	*closest_min;
	t_list	*max_node;
	int		found_min;

	temp = a;
	closest_min = NULL;
	max_node = NULL;
	found_min = 0;
	while (temp)
	{
		if (temp->content > target && (!closest_min
				|| temp->content < closest_min->content))
		{
			closest_min = temp;
			found_min = 1;
		}
		if (!max_node || temp->content > max_node->content)
			max_node = temp;
		temp = temp->next;
	}
	if (found_min)
		return (closest_min);
	return (max_node);
}

t_list	*find_cheapest(t_list *b)
{
	t_list	*temp_b;
	int		cost;
	t_list	*cheapest;

	temp_b = b;
	cost = INT_MAX;
	while (temp_b)
	{
		if (temp_b->cost < cost)
		{
			cheapest = temp_b;
			cost = temp_b->cost;
		}
		temp_b = temp_b->next;
	}
	return (cheapest);
}

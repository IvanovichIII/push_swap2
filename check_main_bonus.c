/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:26 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/23 10:41:33 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

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

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (*b != NULL)
	{
		*b = (*b)->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
	}
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (*a != NULL)
	{
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);
	}
}

void	ra(t_list **a)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
}

void	rb(t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

t_list	*ft_lstlastprev(t_list *lst)
{
	t_list	*curr;
	t_list	*prev;

	curr = lst;
	prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*prev;

	last = ft_lstlast(*a);
	prev = ft_lstlastprev(*a);
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*prev;

	last = ft_lstlast(*b);
	prev = ft_lstlastprev(*b);
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

int	checker(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
	{
		sa(a);
		return (0);
	}
	if (ft_strcmp(line, "sb\n") == 0)
	{
		sb(b);
		return (0);
	}
	if (ft_strcmp(line, "ss\n") == 0)
	{
		ss(a, b);
		return (0);
	}
	if (ft_strcmp(line, "pa\n") == 0)
	{
		pa(a, b);
		return (0);
	}
	if (ft_strcmp(line, "pb\n") == 0)
	{
		pb(a, b);
		return (0);
	}
	if (ft_strcmp(line, "ra\n") == 0)
	{
		ra(a);
		return (0);
	}
	if (ft_strcmp(line, "rb\n") == 0)
	{
		rb(b);
		return (0);
	}
	if (ft_strcmp(line, "rr\n") == 0)
	{
		rr(a, b);
		return (0);
	}
	if (ft_strcmp(line, "rra\n") == 0)
	{
		rra(a);
		return (0);
	}
	if (ft_strcmp(line, "rrb\n") == 0)
	{
		rrb(b);
		return (0);
	}
	if (ft_strcmp(line, "rrr\n") == 0)
	{
		rrr(a, b);
		return (0);
	}
	return (1);
}

int	is_sorted(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stack(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	free(lst);
}

void	print_res(t_list **a, t_list **b)
{
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
}

static t_list	*get_next_min(t_list **lst)
{
	t_list	*temp;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	temp = *lst;
	if (temp)
	{
		while (temp)
		{
			if ((temp->index == -1) && (!has_min
					|| temp->content < min->content))
			{
				min = temp;
				has_min = 1;
			}
			temp = temp->next;
		}
	}
	return (min);
}

void	index_stack(t_list **lst)
{
	t_list	*temp;
	int		index;

	index = 0;
	temp = get_next_min(lst);
	while (temp)
	{
		temp->index = index++;
		temp = get_next_min(lst);
	}
}

static void	start_a(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*line;

	if (argc < 2)
		return (1);
	if (calc_none_err(argv) == 1 || calc_ent_err(argc, argv) == 1)
		return (1);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	start_a(a, argc, argv);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (checker(line, a, b) == 1)
		{
			ft_printf("Error\n");
			return (-1);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	print_res(a, b);
	return (0);
}

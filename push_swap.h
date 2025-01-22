/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:07:10 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/19 19:01:10 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				top;
	int				cost;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
size_t	ft_countlen(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi2(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	print_list(t_list **list);
void	sa(t_list **a, int wri);
void	sb(t_list **b, int wri);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a, int wri);
void	rb(t_list **b, int wri);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int wri);
void	rrb(t_list **b, int wri);
void	rrr(t_list **a, t_list **b);
void	print_list(t_list **list);
void	print_list_targ(t_list **list);
void	calc_target(t_list *a, t_list *b);
void	calc_index(t_list *lst);
void	calc_mov(t_list *a, t_list *b);
int		start_a(t_list **a, char **argv);
void	cp_lst_arr(t_list *list, int *arr);
void	bubble_sort(int *arr, int size);
t_list	*find_closest(t_list *a, int target);
t_list	*find_cheapest(t_list *b);
void	piv(t_list *list, int *piv1, int *piv2);
t_list	*find_min(t_list *lst);
void	move_b(t_list **a, t_list **b);
int		calc_dup_err(t_list *a);
int		calc_ord_err(t_list *a);
int		is_valid_char(char c);
int		validate_arg(const char *arg);
int		validate_args(int argc, char **argv);
int		calc_ent_err(int argc, char **argv);
int		calc_none_err(char **argv);
int		find_err(t_list **a, t_list **b);
void	small_sort(t_list **a);
void	five_sort(t_list **a, t_list **b);
void	iter_a(t_list **a, t_list **b, int *piv1, int *piv2);
void	big_short(t_list **a, t_list **b);
void	push_swap(t_list **a, t_list **b);
#endif

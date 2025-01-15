/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:07:10 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/15 10:43:12 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "printf/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **, t_list *new);
t_list	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	print_list(t_list *list);
#endif

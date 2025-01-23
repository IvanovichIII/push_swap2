/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:59 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/23 10:53:59 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
int		ft_atoi2(const char *str);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_isdigit(int c);
char	*ft_strdup(const char *str);
size_t	ft_countlen(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_joinfreefile(char *buffer, char *buff);
char	*ft_nextline(char *buff);
char	*ft_line(char *buff);
char	*ft_read_file(int fd, char *file);
char	*get_next_line(int fd);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

int		is_valid_char(char c);
int		validate_arg(const char *arg);
int		validate_args(int argc, char **argv);
int		calc_ent_err(int argc, char **argv);
int		calc_none_err(char **argv);
int		checker(char *line, t_list **a, t_list **b);

#endif

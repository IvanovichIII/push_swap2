/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gnl_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:36:32 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/23 10:36:37 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}
int	ft_atoi2(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (-1);
	}
	return (0);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;
	char	*or_ptr;

	i = ft_strlen(str);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	or_ptr = ptr;
	if (ptr != NULL)
	{
		while (*str)
			*ptr++ = *str++;
		*ptr = '\0';
	}
	return (or_ptr);
}

size_t	ft_countlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (*src != '\0' && i < size -1)
		{
			*dest++ = *src++;
			i++;
		}
		*dest = '\0';
	}
	return (x);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ptr = malloc((ft_countlen(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ptr[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	else
	{
		ft_bzero(res, elementSize * elementCount);
		return (res);
	}
}

int	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	return (c == ' ' || c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

int	validate_arg(const char *arg)
{
	while (*arg)
	{
		if (!is_valid_char(*arg))
		{
			ft_printf("Error\n");
			return (1);
		}
		arg++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (validate_arg(argv[i]))
			return (1);
		i++;
	}
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

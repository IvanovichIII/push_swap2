/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:37:09 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/18 16:54:55 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

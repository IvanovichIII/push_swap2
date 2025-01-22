/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <igomez-s@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:32:31 by igomez-s          #+#    #+#             */
/*   Updated: 2025/01/21 16:37:24 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

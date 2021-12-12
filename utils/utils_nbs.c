/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:28:55 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/12 15:41:34 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_whitespace(char a)
{
	return ((a >= 9 && a <= 13) || (a == ' '));
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(int c)
{
	return (c == '-' || c == '+');
}

int	can_be_number(char c)
{
	return (is_digit(c) || is_sign(c) || c == ' ');
}

long	ft_atoi(char *s, t_stack **s_stack)
{
	int		i;
	int		sign;
	long	n;
	long	l;

	i = 0;
	sign = 1;
	n = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] && ((!is_sign(s[i])) && (!is_digit(s[i]))))
		exit_error(*s_stack);
	while (s[i] && is_sign(s[i]))
	{
		if (s[i++] == '-')
			sign = sign * -1;
	}
	while (s[i] && is_digit(s[i]))
	{
		n = n * 10 + (s[i++] - '0');
	}
	l = (sign * n);
	if ((l > INT_MAX) || (l < INT_MIN))
		exit_error(*s_stack);
	return (sign * (int)n);
}

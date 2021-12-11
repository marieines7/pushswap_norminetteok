/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_right_nbs_into_stack.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:28:55 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 17:59:39 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_input(t_stack **s_stack, char **tab, int *m)
{
	int	l;

	l = -1;
	while (tab[*m][++l])
	{
		if (((!can_be_number(tab[*m][l]))
			|| (is_sign(tab[*m][l + 1]) && (is_digit(tab[*m][l])))
			|| (is_sign(tab[*m][l]) && (!is_digit(tab[*m][l + 1])))))
			exit_error(*s_stack);
	}
	if (ft_strchr_lst(*s_stack, ft_atoi(tab[*m], s_stack))
		|| tab[*m][0] == '\0')
		exit_error(*s_stack);
}

int	get_right_numbers_into_stack(char **tab, int m, t_stack **s_stack)
{
	int	n;

	n = m;
	while (tab[m])
	{
		check_input(s_stack, tab, &m);
		add_to_stack(s_stack, ft_atoi(tab[m], s_stack), m);
		m++;
	}
	if (n == 1)
		return (m - 1);
	else if (n == 0)
	{
		freemalloctab(tab);
		return (m);
	}
	return (-1);
}

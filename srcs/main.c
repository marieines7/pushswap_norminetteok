/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:59:26 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 20:06:53 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	algo(t_stack **s_stack, t_stack **head_b, int nb_chiffres)
{
	if (nb_chiffres == 2)
		algo_two(s_stack);
	else if (nb_chiffres == 3)
		algo_three(s_stack);
	else if ((nb_chiffres == 4) || (nb_chiffres == 5))
		algo_five(s_stack, head_b, nb_chiffres);
	else if (nb_chiffres >= 6 && nb_chiffres <= 500)
		resolve(s_stack, head_b);
}

int	main(int ac, char **av)
{
	t_stack	*s_stack;
	t_stack	*head_b;
	int		nb_chiffres;

	nb_chiffres = 0;
	s_stack = NULL;
	head_b = NULL;
	if (ac <= 1)
		return (0);
	else if (ac == 2)
		nb_chiffres = get_right_numbers_into_stack
			(ft_split(av[1], ' '), 0, &s_stack);
	else if (ac > 2)
		nb_chiffres = get_right_numbers_into_stack(av, 1, &s_stack);
	if (!is_sorted(s_stack))
		algo(&s_stack, &head_b, nb_chiffres);
	ft_free_lst(&s_stack);
	return (0);
}

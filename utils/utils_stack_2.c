/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:04 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/13 12:57:11 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	compare(t_stack *node1, t_stack *node2)
{
	if (node1->data > node2->data)
		return (1);
	else if (node1->data < node2->data)
		return (-1);
	return (0);
}

int	is_sorted(t_stack *head)
{
	if (head == NULL || head->next == NULL)
		return (1);
	return ((head->data < (head->next)->data) && is_sorted(head->next));
}

int	compareint(int a, int b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	return (0);
}


void	printstack(t_stack *s)
{
	while (s)
	{
		printf("\n \n s[%d] =", s->right_index); // A ENLEVER
		printf("%d; ", s->data); // A ENLEVER
		s = s->next;
	}
}

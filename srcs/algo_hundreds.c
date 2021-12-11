/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:51:53 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 21:09:00 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tag_right_index(t_stack **head_a)
{
	t_stack	*firstnode;
	t_stack	*loop;
	int		right_index;

	firstnode = *head_a;
	right_index = 0;
	while (firstnode != NULL)
	{
		loop = firstnode->next;
		if (loop == NULL)
			loop = *head_a;
		while (loop != firstnode)
		{
			if (compare(firstnode, loop) == 1)
				right_index += 1;
			loop = loop->next;
			if (loop == NULL)
				loop = *head_a;
		}
		firstnode->right_index = right_index;
		right_index = 0;
		firstnode = firstnode->next;
	}
}

int	stack_size(t_stack **head)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	n_bits_nb(int n)
{
	int	bits;

	bits = 0;
	while (n)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}

void	resolve(t_stack **head_a, t_stack **head_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	size = stack_size(head_a);
	max_bits = n_bits_nb(stack_size(head_a)) + 1;
	tag_right_index(head_a);
	while (max_bits-- != 0)
	{
		j = -1;
		while (++j < size)
		{
			if (((((*head_a)->right_index) >> i) & 1) == 1)
				rotate_a(head_a);
			else
				push_a_to_b(head_a, head_b);
		}
		i++;
		while (*head_b)
			push_b_to_a(head_b, head_a);
	}
}

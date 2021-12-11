/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:23:25 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 19:52:55 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = (*head);
	*head = last;
	before_last->next = NULL;
}

void	reverse_rotate_a(t_stack **head_a)
{
	ft_putstr("rra\n");
	reverse_rotate(head_a);
}

void	reverse_rotate_b(t_stack **head_b)
{
	ft_putstr("rrb\n");
	reverse_rotate(head_b);
}

void	reverse_rotate_a_and_b(t_stack	**head_a, t_stack **head_b)
{
	ft_putstr("rrr\n");
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}

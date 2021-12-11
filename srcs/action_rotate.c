/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:01:42 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 17:10:01 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
}

void	rotate_a(t_stack **head_a)
{
	rotate(head_a);
}

void	rotate_b(t_stack **head_b)
{
	rotate(head_b);
}

void	rotate_a_and_b(t_stack	**head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

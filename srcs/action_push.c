/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:22:40 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 19:51:00 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **head_1, t_stack **head_2)
{
	t_stack	*top_1;

	if (!*head_1 || ((!*head_1) && (!*head_2)))
		return ;
	top_1 = *head_1;
	*head_1 = top_1->next;
	if (*head_2)
		top_1->next = (*head_2);
	else
		top_1->next = NULL;
	*head_2 = top_1;
}

void	push_b_to_a(t_stack **head_b, t_stack **head_a)
{
	ft_putstr("pa\n");
	push(head_b, head_a);
}

void	push_a_to_b(t_stack **head_a, t_stack **head_b)
{
	ft_putstr("pb\n");
	push(head_a, head_b);
}

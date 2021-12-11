/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:22:29 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 19:56:37 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*head || !(*head)->next)
		return ;
	first = (*head);
	second = (*head)->next;
	third = (*head)->next->next;
	*head = second;
	(*head)->next = first;
	(*head)->next->next = third;
}

void	swap_a(t_stack **head_a)
{
	ft_putstr("sa\n");
	swap(head_a);
}

void	swap_b(t_stack **head_b)
{
	ft_putstr("sb\n");
	swap(head_b);
}

void	swap_a_and_b(t_stack **head_a, t_stack **head_b)
{
	ft_putstr("ss\n");
	swap(head_a);
	swap(head_b);
}

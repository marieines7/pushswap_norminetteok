/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:20:54 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/13 13:04:50 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	algo_two(t_stack **head)
{
	if ((compare((*head), (*head)->next)) == 1)
		swap_a(head);
	else
		return ;
}

void	algo_three(t_stack **head)
{
	t_stack	*middle;
	t_stack	*bottom;
	int		top_middle;
	int		middle_bottom;
	int		top_bottom;

	middle = (*head)->next;
	bottom = (*head)->next->next;
	top_middle = compare(*head, middle);
	top_bottom = compare(*head, bottom);
	middle_bottom = compare(middle, bottom);
	if ((top_middle == 1) && (top_bottom == -1) && (middle_bottom == -1))
		swap_a(head);
	else if ((top_middle == 1) && (top_bottom == 1) && (middle_bottom == 1))
	{
		swap_a(head);
		reverse_rotate_a(head);
	}
	else
		algo_three_part2(head, top_middle, top_bottom, middle_bottom);
}

void	algo_three_part2(t_stack **head,
		int top_middle, int top_bottom, int middle_bottom)
{
	if ((top_middle == 1) && (top_bottom == 1) && (middle_bottom == -1))
		rotate_a(head);
	else if ((top_middle == -1) && (top_bottom == -1) && (middle_bottom == 1))
	{
		swap_a(head);
		rotate_a(head);
	}
	else if ((top_middle == -1) && (top_bottom == 1) && (middle_bottom == 1))
		reverse_rotate_a(head);
}

int	smallestelement_pos(t_stack *head)
{
	int		min;
	t_stack	*tmp;
	int		pos;

	pos = 0;
	tmp = head;
	min = head->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		if (tmp->data == min)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

/*
int x_times_ra_rra(t_stack **head, int pos)
{
	int size;

	size = stack_size(head);
	if (pos
}
*/

void	algo_five(t_stack **head_a, t_stack **head_b)
{
	int	pos;

	pos = smallestelement_pos(*head_a);
	while (pos != 0)
	{
		rotate_a(head_a);
		pos--;
	}
	push_a_to_b(head_a, head_b);
	pos = smallestelement_pos(*head_a);
	while (pos != 0)
	{
		rotate_a(head_a);
		pos--;
	}
	push_a_to_b(head_a, head_b);
	if (!is_sorted(*head_a))
		algo_three(head_a);
	push_b_to_a(head_b, head_a);
	push_b_to_a(head_b, head_a);
}

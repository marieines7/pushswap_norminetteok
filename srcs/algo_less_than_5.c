/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:20:54 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/12 18:19:05 by mloubet          ###   ########.fr       */
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
/*
void	algo_five(t_stack **head_a, t_stack **head_b)
{
	tag_right_index(head_a);
	push_a_to_b(head_a, head_b);
	push_a_to_b(head_a, head_b);
	if (!is_sorted(*head_a))
		algo_three(head_a);
	if ((*head_b)->data < ((*head_b)->next->data))
		swap_b(head_b);
	while (((*head_a)->right_index) != (((*head_b)->right_index) + 1))
		rotate_a(head_a);
	push_b_to_a(head_b, head_a);
	while (((*head_a)->right_index) != (((*head_b)->right_index) + 1))
		rotate_a(head_a);
	push_b_to_a(head_b, head_a);
	while (((*head_a)->right_index) != 0)
		reverse_rotate_a(head_a);
}
*/

void	algo_five(t_stack **head_a, t_stack **head_b)
{
	tag_right_index(head_a);
	push_a_to_b(head_a, head_b);
	push_a_to_b(head_a, head_b);
	if (!is_sorted(*head_a))
		algo_three(head_a);
	if ((*head_b)->data < ((*head_b)->next->data))
		swap_b(head_b);
	while (((*head_a)->right_index) != (((*head_b)->right_index) + 1))
			rotate_a(head_a);
	push_b_to_a(head_b, head_a);
	while (((*head_a)->right_index) != (((*head_b)->right_index) + 1))
		rotate_a(head_a);
	push_b_to_a(head_b, head_a);
	while (((*head_a)->right_index) != 0)
		reverse_rotate_a(head_a);
}

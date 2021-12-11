/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:14:05 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 18:00:24 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write (1, &s[i], 1);
}

void	ft_free_lst(t_stack **s_stack)
{
	t_stack	*lst;
	t_stack	*next;

	lst = *s_stack;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	free(lst);
	*s_stack = NULL;
}

void	exit_error(t_stack *s_stack)
{
	ft_free_lst(&s_stack);
	free(s_stack);
	ft_putstr("Error\n");
	exit(0);
}

void	add_to_stack(t_stack **s_stack, int nb, int m)
{
	t_stack	*newnode;
	t_stack	*tmp;

	tmp = *s_stack;
	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		ft_free_lst(s_stack);
	newnode->data = nb;
	newnode->next = NULL;
	newnode->right_index = m - 1;
	if (!(*s_stack))
	{
		*s_stack = newnode;
		return ;
	}
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = newnode;
}

int	ft_strchr_lst(t_stack *s_stack, int nb)
{
	while (s_stack)
	{
		if (s_stack->data == nb)
			return (1);
		s_stack = s_stack->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:45:20 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/10 12:49:06 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h> // a enlever !!
# include <stdio.h> // a enlever !!

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stac	*head_a;
	struct s_stack	*head_b;
	int				right_index;
}t_stack;

/* nb utils */
int		is_whitespace(char a);
int		is_digit(int c);
int		is_sign(int c);
int		can_be_number(char c);
int		ft_atoi(char *s, t_stack **s_stack);
char	**ft_split(const char *s, char c);

/* random */
void	ft_putstr(char	*s);

/* stack utils */
void	ft_free_lst(t_stack **s_stack);
//void	add_to_stack(t_stack **s_stack, int nb);
void	add_to_stack(t_stack **s_stack, int nb, int m);
void	printstack(t_stack *s);
int		ft_strchr_lst(t_stack *s_stack, int nb);
void	exit_error(t_stack *s_stack);
int		compare(t_stack *node1, t_stack *node2);
int		compareint(int a, int b);
int		is_smaller_than_next(t_stack *head); //a enlever
int		is_sorted(t_stack *head);
//parsing
int		get_right_numbers_into_stack(char **tab, int m,
			t_stack **s_stack); // la bonne

int		wlen(const char *s, char c);
int		nwords(const char *s, char c);
char	*dupword(const char *s, char c);
char	**freemalloctab(char **tab);
char	**ft_split(const char *s, char c);

//actions stacks demandees dans le sujet
void	rotate(t_stack **head);
void	rotate_a(t_stack **head_a);
void	rotate_b(t_stack **head_b);
void	rotate_a_and_b(t_stack **head_a, t_stack **head_b);

void	reverse_rotate(t_stack **head);
void	reverse_rotate_a(t_stack **head_a);
void	reverse_rotate_b(t_stack **head_b);
void	reverse_rotate_a_and_b(t_stack **head_a, t_stack **head_b);

void	swap(t_stack **head);
void	swap_a(t_stack **head_a);
void	swap_b(t_stack **head_b);
void	swap_a_and_b(t_stack **head_a, t_stack **head_b);

void	push(t_stack **head_1, t_stack **head_2);
void	push_b_to_a(t_stack **head_b, t_stack **head_a);
void	push_a_to_b(t_stack **head_a, t_stack **head_b);

//algo
void	algo_two(t_stack **head);
void	algo_three(t_stack **head);
void	algo_three_part2(t_stack **head, int top_middle,
			int top_bottom, int middle_bottom);
void	algo_five(t_stack **head_a, t_stack **head_b, int nb_chiffres);
//void	algo_five(t_stack **head_a,
//			t_stack **head_b, int nb_chiffres);
void	algo_hundreds(t_stack **head, t_stack **head_a,
			t_stack **head_b, int nb_chiffres);
//
//int		x_times_sorted(t_stack **head);
int		get_right_pos(t_stack *head);

void	tag_right_pos(t_stack **head_a);
void	tag_right_index(t_stack **head_a);

int		stack_size(t_stack **head);
int		n_bits_nb(int n);
void	resolve(t_stack **head_a, t_stack **head_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:37:35 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 15:29:34 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

/*
** error.c
*/

int		ft_check_error(int argc, char **argv);

/*
** checker.c
*/

int		ft_check_sorting(t_list *a, t_list *b);
int		ft_check_stack_ops(t_list **a, t_list **b, int ret, char *line);
int		ft_check_stack_ops3(char *line);

/*
** init.c
*/

t_list	*ft_init_stacks(int argc, char **argv, int stack);
void	ft_init_chanks(t_list **a_head);

/*
** operations.c
*/

void	ft_swap_stack(t_list **stack, char print);
void	ft_ss(t_list **a, t_list **b, char print);
void	ft_pb(t_list **a, t_list **b, char print, int chank);
void	ft_pa(t_list **a, t_list **b, char print, int chank);

/*
** operations2.c
*/

void	ft_rot_stack(t_list **stack, char print);
void	ft_rev_rot_stack(t_list **stack, char print);
void	ft_rrr(t_list **a, t_list **b, char print);
void	ft_rr(t_list **a, t_list **b, char print);

/*
** utils.c
*/

int		ft_del_list(t_list **head, int position);
void	ft_clear(t_list **a_head, t_list **b_head);
int		*ft_conv_stack_arr(t_list *a, int len);
int		ft_partition_sort(int *arr, int low, int high);
int		*ft_sort_array(int *arr, int low, int high);

/*
** utils2.c
*/

int		ft_lstlast_chank(t_list *stack);
int		ft_chank_len(t_list **stack_head, int chank);
void	ft_reverse_array(int *stack_arr, int start, int end);

/*
** algo.c
*/

void	ft_chanks_to_a(t_list **a_head, t_list **b_head);
void	ft_chanks_to_b(t_list **a_head, t_list **b_head);
void	ft_midpoint_algo_b2(t_list **a, t_list **b, int rb);
void	ft_midpoint_algo_b(t_list **a, t_list **b, int i);

/*
** algo2.c
*/

int		ft_midpoint_algo_a2(
			t_list **a, t_list **b, int midpoint, int *stack_arr);
int		ft_midpoint_algo_a3(
			t_list **a, t_list **b, int midpoint, int *stack_arr);
int		ft_midpoint_algo_a1(
			t_list **a, t_list **b, int midpoint, int *stack_arr);
void	ft_midpoint_algo_a(
			t_list **a, t_list **b, int midpoint, int *stack_arr);

#endif

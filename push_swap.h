/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:37:35 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/18 20:12:29 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

/*
** error.c
*/

int ft_check_error(int argc, char **argv);

/*
** checker.c
*/

int     ft_check_sorting(t_list *a, t_list *b);
int     ft_check_stack_ops(t_list **a, t_list **b);

/*
** init.c
*/

t_list   *ft_init_stacks(int argc, char **argv, int stack);

/*
** operations.c
*/

void    ft_swap_stack(t_list **stack, char print);
void    ft_ss(t_list **a, t_list **b, char print);
void    ft_pb(t_list **a, t_list **b, char print, int chank);
void    ft_pa(t_list **a, t_list **b, char print, int chank);

/*
** operations2.c
*/

void    ft_rot_stack(t_list **stack, char print);
void    ft_rev_rot_stack(t_list **stack, char print);
void    ft_rrr(t_list **a, t_list **b, char print);
void    ft_rr(t_list **a, t_list **b, char print);

/*
** utils.c
*/

int     ft_del_list(t_list **head, int position);
void    ft_print_stacks(t_list **a_head, t_list **b_head);
void	ft_clear(t_list **a_head, t_list **b_head);

#endif

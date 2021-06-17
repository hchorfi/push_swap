/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:48:45 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/17 21:33:56 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_swap_stack -> sa && sb
*/

void    ft_swap_stack(t_list **stack, char print)
{
    int *tmp;
    int tmp_chank;
    if (ft_lstsize(*stack) > 1)
    {
        tmp_chank = (*stack)->chank;
        tmp = (*stack)->content;
        (*stack)->content = (*stack)->next->content;
        (*stack)->chank = (*stack)->next->chank;
        (*stack)->next->content = tmp;
        (*stack)->next->chank = tmp_chank;
        if (print == 'a')
            printf("sa\n");
        else if (print == 'b')
            printf("sb\n");
    }
}

void    ft_ss(t_list **a, t_list **b, char print)
{
    ft_swap_stack(*(&a), 0);
    ft_swap_stack(*(&b), 0);
    if (print == 's')
        printf("ss\n");
}

void    ft_pb(t_list **a, t_list **b, char print, int chank)
{
    int *val;

    if (ft_lstsize(*a) > 0)
    {
        if (*b == NULL)
        {
            *b = ft_lstnew((*a)->content);
        }
        else
        {
            ft_lstadd_front(*(&b), ft_lstnew((*a)->content));            
        }
        (*b)->chank = chank;
        ft_del_list(*(&a), 1);
        if (print == 'b')
            printf("pb\n");
    }
}

void    ft_pa(t_list **a, t_list **b, char print, int chank)
{
    int *val;

    if (ft_lstsize(*b) > 0)
    {
        if (*a == NULL)
            *a = ft_lstnew((*b)->content);
        else
        {
            ft_lstadd_front(*(&a), ft_lstnew((*b)->content));
        }
        (*a)->chank = chank;
        ft_del_list(*(&b), 1);
        if (print == 'a')
            printf("pa\n");
    }
}

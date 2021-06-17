/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:53:22 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/17 21:32:42 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_rot_stack -> ra && rb
*/

void    ft_rot_stack(t_list **stack, char print)
{
    if (ft_lstsize(*stack) > 1)
    {
        ft_lstadd_back(*(&stack), ft_lstnew((*stack)->content));
        ft_lstlast(*stack)->chank = (*stack)->chank;
        ft_del_list(*(&stack), 1);
        if (print == 'a')
            printf("ra\n");
        else if (print == 'b')
            printf("rb\n");
    }
}

void    ft_rr(t_list **a, t_list **b, char print)
{
    ft_rot_stack(*(&a), 0);
    ft_rot_stack(*(&b), 0);
    if (print == 'r')
        printf("rr\n");
}

/*
** ft_rev_rot_stack -> rra && rrb
*/

void    ft_rev_rot_stack(t_list **stack, char print)
{
    t_list *stack_head;
    int size_stack;
    int i;

    i = 1;
    stack_head = *stack;
    size_stack = ft_lstsize(*stack);
    if ( size_stack > 1)
    {
        while (i <= size_stack)
        {
            if (i == size_stack)
            {
                ft_lstadd_front(*(&stack), ft_lstnew(stack_head->content));
                (*stack)->chank = ft_lstlast(*stack)->chank;
                ft_del_list(*(&stack), size_stack + 1);
                break;
            }
            i++;
            stack_head = stack_head->next;
        }
        if (print == 'a')
            printf("rra\n");
        else if (print == 'b')
            printf("rrb\n");
    }
}

void    ft_rrr(t_list **a, t_list **b, char print)
{
    ft_rev_rot_stack(*(&a), 0);
    ft_rev_rot_stack(*(&b), 0);
    if (print == 'r')
        printf("rrr\n");
}
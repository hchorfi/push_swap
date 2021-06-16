/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:02:08 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/16 21:50:09 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_del_list(t_list **head, int position)
{
    t_list *curr;
    t_list *prev;
    
    curr = *head;
    prev = *head;
    if (*head == NULL)
        return (0);
    else if (position == 1)
    {
        *head = curr->next;
        free(curr);
        curr = NULL;
    }
    else
    {
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL; 
    }
    return (0);
}

void    ft_print_stacks(t_list **a_head, t_list **b_head)
{
    printf("\033[0;34ma : %p\n\033[0m", *a_head);
    printf("\033[0;35mb : %p\n\n\033[0m", *b_head);
    t_list  *a;
    t_list  *b;
    a = *a_head;
    b = *b_head;
    int link_len;
    int aa;

    if (ft_lstsize(a) > ft_lstsize(b))
        link_len = ft_lstsize(a);
    else
        link_len = ft_lstsize(b);
    while (link_len)
    {
        if(a)
        {
            printf("\033[0;34m%12d - %d\033[0m", *(int *)a->content, a->chank);
            a = a->next;
            aa = 0;
        }
        else
            aa = 1;
        if (b)
        {
            if (aa == 0)
                printf("\033[0;35m  %12d - %d\033[0m", *(int *)b->content, b->chank);
            else
                printf("\033[0;35m  %28d - %d\033[0m", *(int *)b->content, b->chank);
            b = b->next;
        }
        printf(" \n");
        link_len--;
    }
    printf("\033[0;34m----------------\033[0m  \033[0;35m----------------\n\033[0m");
    printf("\033[0;34m(stack  a)      \033[0m  \033[0;35m(stack b )\n\033[0m");
    printf("----------------------------------\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:33:01 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/16 21:31:20 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_check_stack_ops(t_list **a, t_list **b)
{
    char *line;
    int  ret;

    //printf("a : %p\n", *a);
    //printf("b : %p\n", *b);
    while (1)
    {
        ret = get_next_line(0, &line);
        //printf("\033[0;33mopp : %s\n\033[0m", line);
        if (!strcmp(line, "sa"))
        {
            ft_swap_stack(*(&a), 0);
        }
        else if (!strcmp(line, "sb"))
        {
            ft_swap_stack(*(&b), 0);
        }
        else if (!strcmp(line, "ss"))
        {
            ft_ss(*(&a), *(&b), 0);
        }
        else if (!strcmp(line, "pb"))
        {
            ft_pb(*(&a), *(&b), 0, 0);
        }
        else if (!strcmp(line, "pa"))
        {
            ft_pa(*(&a), *(&b), 0, 0);
        }
        else if (!strcmp(line, "ra"))
        {
            ft_rot_stack(*(&a), 0);
        }
        else if (!strcmp(line, "rb"))
        {
            ft_rot_stack(*(&b), 0);
        }
        else if (!strcmp(line, "rr"))
        {
            ft_rr(*(&a), *(&b), 0);
        }
        else if (!strcmp(line, "rra"))
        {
            ft_rev_rot_stack(*(&a), 0);
        }
        else if (!strcmp(line, "rrb"))
        {
            ft_rev_rot_stack(*(&b), 0);
        }
        else if (!strcmp(line, "rrr"))
        {
            ft_rrr(*(&a), *(&b), 0);
        }
        else if (ret == 1 && ft_strlen(line) == 0)
        {
            continue ;
        }
        else if (ret == 0 && ft_strlen(line) == 0)
        {
            return (0);
        }
        else
        {
            printf("ret : %d - len : %d - line : %s\n", ret, ft_strlen(line), line);
            printf("Error\n");
            return (1);
        }
        //ft_print_stacks(*(&a), *(&b));
    }
    return (0);
}

int ft_check_sorting(t_list *a, t_list *b)
{
    while (a && a->next)
    {
        if ((*(int *)a->content) < (*(int *)a->next->content))
            a = a->next;
        else
        {
            ft_putstr_fd("\033[0;31m", 1);
            ft_putstr_fd("ko\n", 1);
            ft_putstr_fd("\033[0m", 1);
            return (1);
        }
    }
    if (ft_lstsize(b) == 0 && !b)
    {
        ft_putstr_fd("\033[0;32m", 1);
        ft_putstr_fd("ok\n", 1);
        ft_putstr_fd("\033[0m", 1);
    }
    else
    {
        ft_putstr_fd("\033[0;31m", 1);
        ft_putstr_fd("ko\n", 1);
        ft_putstr_fd("\033[0m", 1);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    
    if (argc == 1)
        return (0);
    else if (ft_check_error(argc, argv))
    {
        ft_putstr_fd("error\n", 1);
        return (1);
    }
    a = ft_init_stacks(argc, argv, 1);
    b = ft_init_stacks(argc, argv, 0);
    //printf("a : %p\n", a);
    //printf("b : %p\n", b);
    //printf("init stacks\n");
    //ft_print_stacks(&a, &b);
    if (ft_check_stack_ops(&a, &b))
        return (1);
    ft_check_sorting(a, b);
    return (0);
}

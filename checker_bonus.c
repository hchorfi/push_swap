/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:33:01 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 13:49:09 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_ops2(t_list **a, t_list **b, char *line)
{
	if (!strcmp(line, "sa"))
		ft_swap_stack(*(&a), 0);
	else if (!strcmp(line, "sb"))
		ft_swap_stack(*(&b), 0);
	else if (!strcmp(line, "ss"))
		ft_ss(*(&a), *(&b), 0);
	else if (!strcmp(line, "pb"))
		ft_pb(*(&a), *(&b), 0, 0);
	else if (!strcmp(line, "pa"))
		ft_pa(*(&a), *(&b), 0, 0);
	else if (!strcmp(line, "ra"))
		ft_rot_stack(*(&a), 0);
	else if (!strcmp(line, "rb"))
		ft_rot_stack(*(&b), 0);
	else if (!strcmp(line, "rr"))
		ft_rr(*(&a), *(&b), 0);
	else if (!strcmp(line, "rra"))
		ft_rev_rot_stack(*(&a), 0);
	else if (!strcmp(line, "rrb"))
		ft_rev_rot_stack(*(&b), 0);
	else if (!strcmp(line, "rrr"))
		ft_rrr(*(&a), *(&b), 0);
	else
		return (0);
	return (1);
}

int	ft_check_stack_ops3(char *line)
{
	ft_putstr_fd("\033[0;31m", 1);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("\033[0m", 1);
	free(line);
	return (1);
}

int	ft_check_stack_ops(t_list **a, t_list **b, int ret, char *line)
{
	while (1)
	{
		ret = get_next_line(0, &line, NULL, 0);
		if (ft_check_stack_ops2(a, b, line))
		{
			free(line);
			continue ;
		}
		else if (ret == 1 && ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		else if (ret == 0 && ft_strlen(line) == 0)
		{
			free(line);
			return (0);
		}
		else
			return (ft_check_stack_ops3(line));
		free(line);
	}
	return (0);
}

int	ft_check_sorting(t_list *a, t_list *b)
{
	while (a && a->next)
	{
		if ((*(int *)a->content) < (*(int *)a->next->content))
			a = a->next;
		else
		{
			ft_putstr_fd("\033[0;31mko\033[0m\n", 1);
			return (1);
		}
	}
	if (ft_lstsize(b) == 0 && !b)
		ft_putstr_fd("\033[0;32mok\033[0m\n", 1);
	else
	{
		ft_putstr_fd("\033[0;31mko\033[0m\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	else if (ft_check_error(argc, argv))
	{
		ft_putstr_fd("\033[0;31m", 1);
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("\033[0m", 1);
		return (1);
	}
	a = ft_init_stacks(argc, argv, 1);
	b = ft_init_stacks(argc, argv, 0);
	if (ft_check_stack_ops(&a, &b, 0, NULL))
	{
		ft_clear(&a, &b);
		return (1);
	}
	ft_check_sorting(a, b);
	ft_clear(&a, &b);
	return (0);
}

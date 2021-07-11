/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:31:30 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 13:54:32 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_list **stack)
{
	t_list	*newlist;

	newlist = *stack;
	while (newlist && newlist->next)
	{
		if (*(int *)newlist->content < *(int *)newlist->next->content)
			newlist = newlist->next;
		else
			return (0);
	}
	return (1);
}

void	ft_sort3(t_list **s)
{
	int	s1;
	int	s2;
	int	s3;

	s1 = *(int *)(*s)->content;
	s2 = *(int *)(*s)->next->content;
	s3 = *(int *)(*s)->next->next->content;
	if (s1 > s2 && s2 < s3 && s3 > s1)
		ft_swap_stack(s, 'a');
	else if (s1 > s2 && s2 > s3 && s3 < s1)
	{
		ft_swap_stack(s, 'a');
		ft_rev_rot_stack(s, 'a');
	}
	else if (s1 > s2 && s2 < s3 && s3 < s1)
		ft_rot_stack(s, 'a');
	else if (s1 < s2 && s2 > s3 && s3 > s1)
	{
		ft_swap_stack(s, 'a');
		ft_rot_stack(s, 'a');
	}
	else
		ft_rev_rot_stack(s, 'a');
}

void	chanks(t_list **a, t_list **b)
{
	ft_chanks_to_b(a, b);
	ft_chanks_to_a(a, b);
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
	if (!ft_stack_sorted(&a))
	{
		ft_init_chanks(&a);
		if (ft_lstsize(a) == 3)
			ft_sort3(&a);
		else
			chanks(&a, &b);
	}
	ft_clear(&a, &b);
	return (0);
}

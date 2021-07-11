/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:33:10 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 13:37:42 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chanks_to_a(t_list **a_head, t_list **b_head)
{
	int	len;

	while (*b_head)
	{
		len = ft_chank_len(b_head, (*b_head)->chank);
		if (len == 1)
			ft_pa(a_head, b_head, 'a', 0);
		else if (len == 2)
		{
			if (*(int *)(*b_head)->content < *(int *)(*b_head)->next->content)
				ft_swap_stack(b_head, 'b');
			ft_pa(a_head, b_head, 'a', 0);
			ft_pa(a_head, b_head, 'a', 0);
		}
		else
		{
			ft_midpoint_algo_b(a_head, b_head, 0);
			ft_chanks_to_b(a_head, b_head);
		}
	}
}

void	ft_chanks_to_b(t_list **a_head, t_list **b_head)
{
	int	*stack_arr;
	int	len;
	int	midpoint;

	len = ft_chank_len(a_head, (*a_head)->chank);
	stack_arr = ft_sort_array(ft_conv_stack_arr(*a_head, len), 0, len - 1);
	while (len > 2)
	{
		ft_midpoint_algo_a(a_head, b_head, len / 2, stack_arr);
		len = ft_chank_len(a_head, (*a_head)->chank);
		free(stack_arr);
		stack_arr = ft_sort_array(ft_conv_stack_arr(*a_head, len), 0, len - 1);
	}
	free(stack_arr);
	if (len == 2)
	{
		if (*(int *)(*a_head)->content > *(int *)(*a_head)->next->content)
			ft_swap_stack(a_head, 'a');
		(*a_head)->chank = 0;
		(*a_head)->next->chank = 0;
	}
	else if (len == 1)
		(*a_head)->chank = 0;
}

void	ft_midpoint_algo_b2(t_list **a, t_list **b, int rb)
{
	while (rb > 0)
	{
		ft_rev_rot_stack(b, 'b');
		rb--;
	}
}

void	ft_midpoint_algo_b(t_list **a, t_list **b, int i)
{
	int	midpoint;
	int	len;
	int	*chank_arr;
	int	rb;

	len = ft_chank_len(b, (*b)->chank);
	chank_arr = ft_sort_array(ft_conv_stack_arr(*b, len), 0, len - 1);
	midpoint = len / 2;
	rb = 0;
	while (i < len - midpoint)
	{
		if (*(int *)(*b)->content >= chank_arr[midpoint])
		{
			ft_pa(a, b, 'a', midpoint);
			i++;
		}
		else
		{
			ft_rot_stack(b, 'b');
			rb++;
		}
	}
	free(chank_arr);
	ft_midpoint_algo_b2(a, b, rb);
}

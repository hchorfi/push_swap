/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:35:50 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 13:39:30 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_midpoint_algo_a2(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int	i;

	i = 0;
	if (*(int *)(*a)->content < stack_arr[midpoint])
	{
		ft_pb(a, b, 'b', midpoint);
		i++;
	}
	else
		ft_rot_stack(a, 'a');
	return (i);
}

int	ft_midpoint_algo_a3(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int	i;
	int	tail;

	i = 0;
	tail = ft_lstlast_chank(*a);
	if (tail < stack_arr[midpoint])
	{
		ft_rev_rot_stack(a, 'a');
		ft_pb(a, b, 'b', midpoint);
		i++;
	}
	return (i);
}

int	ft_midpoint_algo_a1(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int	i;

	i = 0;
	while (i < midpoint && (*a)->chank == 0)
	{
		if (*(int *)(*a)->content < stack_arr[midpoint])
		{
			ft_pb(a, b, 'b', midpoint);
			i++;
		}
		else
		{
			while (i < midpoint)
			{
				if (ft_midpoint_algo_a2(a, b, midpoint, stack_arr))
					i++;
				else
					while (i < midpoint)
						i += ft_midpoint_algo_a2(a, b, midpoint, stack_arr);
			}
		}
	}
	return (i);
}

void	ft_midpoint_algo_a(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int	i;
	int	ra;

	ra = 0;
	i = ft_midpoint_algo_a1(a, b, midpoint, stack_arr);
	while (i < midpoint && (*a)->chank != 0)
	{
		if (*(int *)(*a)->content < stack_arr[midpoint])
		{
			ft_pb(a, b, 'b', midpoint);
			i++;
		}
		else
		{
			ft_rot_stack(a, 'a');
			ra++;
		}
	}
	while (ra > 0)
	{
		ft_rev_rot_stack(a, 'a');
		ra--;
	}
}

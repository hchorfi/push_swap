/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:38:34 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 14:00:46 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlast_chank(t_list *stack)
{
	int	chank;
	int	val;

	chank = stack->chank;
	while (stack && stack->chank == chank)
	{
		val = *(int *)stack->content;
		stack = stack->next;
	}
	return (val);
}

int	ft_chank_len(t_list **stack_head, int chank)
{
	t_list	*stack;
	int		len;

	stack = *stack_head;
	len = 0;
	while (stack && stack->chank == chank)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	ft_reverse_array(int *stack_arr, int start, int end)
{
	int	tmp;

	while (start < end)
	{
		tmp = stack_arr[start];
		stack_arr[start] = stack_arr[end];
		stack_arr[end] = tmp;
		start++;
		end--;
	}
}

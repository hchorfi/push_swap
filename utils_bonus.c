/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:02:08 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/10 14:00:28 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list **a_head, t_list **b_head)
{
	t_list	*tmp;

	while (*a_head)
	{
		tmp = *a_head;
		free ((*a_head)->content);
		*a_head = (*a_head)->next;
		free(tmp);
	}
	while (*b_head)
	{
		tmp = *b_head;
		free ((*b_head)->content);
		*b_head = (*b_head)->next;
		free(tmp);
	}
}

int	ft_del_list(t_list **head, int position)
{
	t_list	*curr;
	t_list	*prev;

	curr = *head;
	prev = *head;
	if (*head == NULL)
		return (0);
	else if (position == 1)
		*head = curr->next;
	else
	{
		while (position != 1)
		{
			prev = curr;
			curr = curr->next;
			position--;
		}
		prev->next = curr->next;
	}
	free(curr);
	curr = NULL;
	return (0);
}

int	*ft_conv_stack_arr(t_list *a, int len)
{
	int	*stack_arr;
	int	i;

	stack_arr = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		stack_arr[i] = *(int *)a->content;
		i++;
		a = a->next;
	}
	return (stack_arr);
}

int	ft_partition_sort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	swap;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
		}
		j++;
	}
	swap = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = swap;
	return (i + 1);
}

int	*ft_sort_array(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition_sort(arr, low, high);
		ft_sort_array(arr, low, pi - 1);
		ft_sort_array(arr, pi + 1, high);
	}
	return (arr);
}

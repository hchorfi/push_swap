/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:31:30 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/16 21:47:06 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_conv_stack_arr(t_list *a, int len)
{
	int *stack_arr;
	int i;
	
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
	int pivot;
	int i;
	int	j;
	int swap;

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

int *ft_sort_array(int *arr, int low, int high)
{
	int	pi;

	if	(low < high)
	{
		pi = ft_partition_sort(arr, low, high);
		ft_sort_array(arr, low, pi - 1);
		ft_sort_array(arr, pi + 1, high);
	}
	return (arr);
}

void	ft_midpoint_algo_a(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int i;
	int	index;
	t_list *tail;
	
	i = 0;
	index = ft_lstsize(*a) / 2;
	while (i < midpoint)
	{
		if (*(int *)(*a)->content < stack_arr[midpoint])
		{
			ft_pb(a, b, 'b', midpoint);
			i++;
			ft_print_stacks(a, b);
		}
		else
		{
			while (i < midpoint)
			{
				tail = ft_lstlast(*a);
				if (*(int *)tail->content < stack_arr[midpoint])
				{
					ft_rev_rot_stack(a, 'a');
					ft_pb(a, b, 'b', midpoint);
					i++;
					ft_print_stacks(a, b);
				}
				else
				{
					while (i < midpoint)
					{
						if (*(int *)(*a)->content < stack_arr[midpoint])
						{
							ft_pb(a, b, 'b', midpoint);
							i++;
							ft_print_stacks(a, b);
						}
						else
						{
							ft_rot_stack(a, 'a');
							ft_print_stacks(a, b);
						}
					}
				}
			}
		}
	}
}

int		ft_chank_len(t_list **stack_head, int chank)
{
	t_list *stack;
	int	len;

	stack = *stack_head;
	len	= 0;
	printf(" shunk befor size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
	while (stack && stack->chank == chank)
	{
		len++;
		printf(" shunk size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
		stack = stack->next;
		//if (stack->next)
			//printf(" shunk af size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
	}
	return (len);
}

void	ft_chanks_to_a(t_list **a_head, t_list **b_head)
{

	int *stack_arr;
	int	len;
	int	midpoint;

	len = ft_chank_len(a_head, (*a_head)->chank);
	//midpoint = 0;
	stack_arr = ft_sort_array(ft_conv_stack_arr(*a_head, len), 0, len - 1);
	while (len > 2)
	{
		//ft_print_stacks(a_head, b_head);
		//midpoint = midpoint + ((len - midpoint) / 2);
		ft_midpoint_algo_a(a_head, b_head, len / 2, stack_arr);
		len = ft_chank_len(a_head, (*a_head)->chank);
		free(stack_arr);
		stack_arr = ft_sort_array(ft_conv_stack_arr(*a_head, len), 0, len - 1);
		//printf(" size : %d - %d\n", ft_lstsize(*a_head), (*a_head)->chank);
	}
	if (len == 2)
	{
		if (*(int *)(*a_head)->content > *(int *)(*a_head)->next->content)
		{
			ft_swap_stack(a_head, 'a');
			ft_print_stacks(a_head, b_head);
		}
	}
}

void	ft_reverse_array(int *stack_arr, int start, int end)
{
	int tmp;

	while (start < end)
	{
		tmp = stack_arr[start];
		stack_arr[start] = stack_arr[end];
		stack_arr[end] = tmp;
		start++;
		end--;
	}
}

void	ft_push_b_sorted(t_list **a_head, t_list **b_head)
{
	int	*stack_arr;
	int	len;
	int	index;
	t_list *b;
	int rrb;
	int rb;

	len = ft_lstsize(*b_head);
	stack_arr = ft_sort_array(ft_conv_stack_arr(*b_head, len), 0, len - 1);
	ft_reverse_array(stack_arr, 0, len - 1);
	while(ft_lstsize(*b_head))
	{
		index = 0;
		b = *b_head;
		while (b && *(int *)b->content != *stack_arr)
		{
			index++;
			b = b->next;
		}
		if (index == 0)
		{
			ft_pa(a_head, b_head, 'a', 0);
			stack_arr++;
			len--;
			//ft_print_stacks(a_head, b_head);
		}
		else if (index < len / 2)
		{
			rb = index;
			while (index > 0)
			{
				ft_rot_stack(b_head, 'b');
				//ft_print_stacks(a_head, b_head);
				index--;
			}
			ft_pa(a_head, b_head, 'a', 0);
			stack_arr++;
			len--;
		}
		else
		{
			rrb = len - index;
			while (len - index > 0)
			{
				ft_rev_rot_stack(b_head, 'b');
				//ft_print_stacks(a_head, b_head);
				index++;
			}
			ft_pa(a_head, b_head, 'a', 0);
			stack_arr++;
			len--;
		}
	}
}

void	ft_init_chanks(t_list **a_head)
{
	t_list *a;

	a = *a_head;
	while (a)
	{
		a->chank = 0;
		a = a->next;
	}
}

int main(int argc, char **argv)
{
	t_list  *a;
	t_list  *b;

	if (argc == 1)
		return (0);
	else if (ft_check_error(argc, argv))
	{
		ft_putstr_fd("\033[0;31m", 1);
		ft_putstr_fd("error\n", 1);
		ft_putstr_fd("\033[0m", 1);
		return (1);
	}
	a = ft_init_stacks(argc, argv, 1);
	b = ft_init_stacks(argc, argv, 0);
	//printf("a : %p\n", a);
	//printf("b : %p\n", b);
	ft_init_chanks(&a);
	ft_chanks_to_a(&a, &b);
	//ft_push_b_sorted(&a, &b);
	// printf("a : %p\n", a);
	// printf("b : %p\n", b);
	// printf("init stacks\n");
	//ft_print_stacks(&a, &b);
	//printf("sa\npb\npb\npb\nsa\npa\npa\npb\n");
	return (0);
}
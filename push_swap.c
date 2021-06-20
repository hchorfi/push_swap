/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:31:30 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/19 14:44:22 by hchorfi          ###   ########.fr       */
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

int	ft_lstlast_chank(t_list *stack)
{
	int chank;
	int val;

	chank = stack->chank;
	while (stack && stack->chank == chank)
	{
		val = *(int *)stack->content;
		stack = stack->next;
	}
	return (val);
}

void	ft_midpoint_algo_a(t_list **a, t_list **b, int midpoint, int *stack_arr)
{
	int i;
	int	ra;
	int	tail;

	i = 0;
	ra = 0;
	while (i < midpoint && (*a)->chank == 0)
	{
		if (*(int *)(*a)->content < stack_arr[midpoint])
		{
			ft_pb(a, b, 'b', midpoint);
			i++;
			//ft_print_stacks(a, b);
		}
		else
		{
			while (i < midpoint)
			{
				tail = ft_lstlast_chank(*a);
				if (tail < stack_arr[midpoint])
				{
					ft_rev_rot_stack(a, 'a');
					ft_pb(a, b, 'b', midpoint);
					i++;
					//ft_print_stacks(a, b);
				}
				else
				{
					while (i < midpoint)
					{
						if (*(int *)(*a)->content < stack_arr[midpoint])
						{
							ft_pb(a, b, 'b', midpoint);
							i++;
							//ft_print_stacks(a, b);
						}
						else
						{
							ft_rot_stack(a, 'a');
							//ft_print_stacks(a, b);
						}
					}
				}
			}
		}
	}
	while (i < midpoint && (*a)->chank != 0)
	{
		if (*(int *)(*a)->content < stack_arr[midpoint])
		{
			ft_pb(a, b, 'b', midpoint);
			i++;
			//ft_print_stacks(a, b);
		}
		else
		{
			ft_rot_stack(a, 'a');
			ra++;
			//ft_print_stacks(a, b);
		}
	}
	while (ra > 0)
	{
		ft_rev_rot_stack(a, 'a');
		//ft_print_stacks(a, b);
		ra--;
	}
}

int		ft_chank_len(t_list **stack_head, int chank)
{
	t_list *stack;
	int	len;

	stack = *stack_head;
	len	= 0;
	//printf(" shunk befor size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
	while (stack && stack->chank == chank)
	{
		len++;
		//printf(" shunk size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
		stack = stack->next;
		//if (stack->next)
			//printf(" shunk af size : %d - %d\n", ft_lstsize(stack), (stack)->chank);
	}
	return (len);
}

void	ft_chanks_to_b(t_list **a_head, t_list **b_head)
{

	int *stack_arr;
	int	len;
	int	midpoint;

	len = ft_chank_len(a_head, (*a_head)->chank);
	//midpoint = 0;
	stack_arr = ft_sort_array(ft_conv_stack_arr(*a_head, len), 0, len - 1);
	while (len > 2)
	{
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
			//ft_print_stacks(a_head, b_head);
		}
		(*a_head)->chank = 0;
		(*a_head)->next->chank = 0;
	}
	else if (len == 1)
		(*a_head)->chank = 0;
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
			////ft_print_stacks(a_head, b_head);
		}
		else if (index < len / 2)
		{
			rb = index;
			while (index > 0)
			{
				ft_rot_stack(b_head, 'b');
				////ft_print_stacks(a_head, b_head);
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
				////ft_print_stacks(a_head, b_head);
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

void	ft_midpoint_algo_b(t_list **a, t_list **b)
{
	int midpoint;
	int	i;
	int	len;
	int	*chank_arr;
	int rb;
	
	len = ft_chank_len(b, (*b)->chank);
	chank_arr = ft_sort_array(ft_conv_stack_arr(*b, len), 0, len - 1);
	midpoint = len / 2;
	i = 0;
	rb = 0;
	while (i < len - midpoint)
	{
		if (*(int *)(*b)->content >= chank_arr[midpoint])
		{
			ft_pa(a, b, 'a', midpoint);
			i++;
			//ft_print_stacks(a, b);
		}
		else
		{
			ft_rot_stack(b, 'b');
			rb++;
			//ft_print_stacks(a, b);
		}
		//i++;
	}
	while (rb > 0)
	{
		ft_rev_rot_stack(b, 'b');
		//ft_print_stacks(a, b);
		rb--;
	}
	
}

void	ft_chanks_to_a(t_list **a_head, t_list **b_head)
{
	int len;

	while(*b_head)
	{
		len = ft_chank_len(b_head, (*b_head)->chank);
		if (len == 1)
		{
			ft_pa(a_head, b_head, 'a', 0);
			//ft_print_stacks(a_head, b_head);
		}
		else if (len == 2)
		{
			if (*(int *)(*b_head)->content < *(int *)(*b_head)->next->content)
			{
				ft_swap_stack(b_head, 'b');
				//ft_print_stacks(a_head, b_head);
			}
			ft_pa(a_head, b_head, 'a', 0);
			//ft_print_stacks(a_head, b_head);
			ft_pa(a_head, b_head, 'a', 0);
			//ft_print_stacks(a_head, b_head);
		}
		else
		{
			ft_midpoint_algo_b(a_head, b_head);
			ft_chanks_to_b(a_head, b_head);
		}
	}
}

int	ft_stack_sorted(t_list **stack)
{
	t_list *newlist;

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
	int s1;
	int s2;
	int s3;

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

int main(int argc, char **argv)
{
	t_list  *a;
	t_list  *b;

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
		{
			ft_chanks_to_b(&a, &b);
			ft_chanks_to_a(&a, &b);
		}
	}
	//ft_push_b_sorted(&a, &b);
	// printf("a : %p\n", a);
	// printf("b : %p\n", b);
	// printf("init stacks\n");
	//ft_print_stacks(&a, &b);
	//printf("sa\npb\npb\npb\nsa\npa\npa\npb\n");
	//system("leaks push_swap");
	return (0);
}
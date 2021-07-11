/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:05:51 by hchorfi           #+#    #+#             */
/*   Updated: 2021/07/09 17:47:57 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init_stacks(int argc, char **argv, int stack)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		*val;

	i = 1;
	b = NULL;
	a = NULL;
	if (stack == 0)
	{
		return (b);
	}
	else
	{
		while (argv[i])
		{
			val = malloc(sizeof(int));
			*val = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew(val));
			i++;
		}
	}
	return (a);
}

void	ft_init_chanks(t_list **a_head)
{
	t_list	*a;

	a = *a_head;
	while (a)
	{
		a->chank = 0;
		a = a->next;
	}
}

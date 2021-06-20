/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:02:08 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/18 20:25:39 by hchorfi          ###   ########.fr       */
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
	{
		*head = curr->next;
		free(curr);
		curr = NULL;
	}
	else
	{
		while (position != 1)
		{
			prev = curr;
			curr = curr->next;
			position--;
		}
		prev->next = curr->next;
		free(curr);
		curr = NULL;
	}
	return (0);
}

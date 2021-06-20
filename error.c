/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:58:30 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/18 20:45:50 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const	char *s1, const	char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_check_error2(int argc, char **argv)
{
	int		j;
	char	*s;

	while (argc >= 1)
	{
		j = argc;
		s = ft_itoa(ft_atoi(argv[argc]));
		if (ft_strcmp(s, argv[argc]))
		{
			free(s);
			return (1);
		}
		free(s);
		while (j >= 1)
		{
			if (!ft_strcmp(argv[argc], argv[j - 1]))
				return (1);
			else
				j--;
		}
		argc--;
	}
	return (0);
}

int	ft_check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			else
				j++;
		}
		i++;
	}
	argc--;
	return (ft_check_error2(argc, argv));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchorfi <hchorfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:12:18 by hchorfi           #+#    #+#             */
/*   Updated: 2021/06/18 20:43:08 by hchorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_check_tmp(char **line, char *tmp)
{
	char	*chr;
	char	*swp;

	chr = NULL;
	if (tmp)
	{
		chr = ft_strchr(tmp, '\n');
		if (chr)
		{
			*chr = '\0';
			swp = ft_strdup(++chr);
			*line = ft_strdup(tmp);
			ft_strcpy(tmp, swp);
			free(swp);
		}
		else
		{
			*line = ft_strdup(tmp);
			ft_bzero(tmp, ft_strlen(tmp));
		}
	}
	else
		*line = ft_strdup("");
	return (chr);
}

int	ft_last_check(char **tmp, char **buffer)
{
	free(*tmp);
	*tmp = NULL;
	free(*buffer);
	return (0);
}

int	ft_free(char **x, int i)
{
	free(*x);
	return (i);
}

int	get_next_line(int fd, char **line, char *buffer, int bc)
{
	static char	*tmp;
	char		*chr;
	char		*xt;

	if (fd == -1 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > M
		|| !(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	chr = ft_check_tmp(line, tmp);
	while (!chr)
	{
		bc = read(fd, buffer, BUFFER_SIZE);
		if (bc == 0)
			return (ft_last_check(&tmp, &buffer));
		buffer[bc] = '\0';
		chr = strchr(buffer, '\n');
		if (chr)
		{
			*chr = '\0';
			xt = tmp;
			tmp = ft_strdup(++chr);
			free(xt);
		}
		*line = ft_strjoin2(*line, buffer);
	}
	return (ft_free(&buffer, 1));
}

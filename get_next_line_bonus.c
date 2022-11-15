/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:17:43 by jerhee            #+#    #+#             */
/*   Updated: 2022/11/15 21:02:18 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*ft_read_str(char *s_str, int fd)
{
	int		byte;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!ft_is_strchr(s_str, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		s_str = ft_strjoin(s_str, buffer);
	}
	free(buffer);
	return (s_str);
}

char	*ft_show_line(char *s_str)
{
	int		i;
	char	*res;

	i = 0;
	if (!s_str[i])
		return (NULL);
	while (s_str[i] && s_str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (s_str[i])
	{
		res[i] = s_str[i];
		i++;
		if (s_str[i - 1] == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_remain_line(char *s_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s_str[i] && s_str[i] != '\n')
		i++;
	if (!s_str[i])
	{
		free(s_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (NULL);
	j = 0;
	while (s_str[i + j + 1])
	{
		str[j] = s_str[i + j + 1];
		j++;
	}
	str[j] = '\0';
	free(s_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*res;
	t_list			*s_list;
	static t_list	*static_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_list = ft_check_fd(&static_list, fd);
	s_list->str = ft_read_str(s_list->str, fd);
	if (!s_list->str || !s_list->str[0])
	{
		ft_free_node(&static_list, fd);
		return (NULL);
	}
	res = ft_show_line(s_list->str);
	s_list->str = ft_remain_line(s_list->str);
	return (res);
}

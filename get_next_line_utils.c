/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:16:40 by jerhee            #+#    #+#             */
/*   Updated: 2022/11/15 20:56:40 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		res[s1_len + i] = s2[i];
	res[s1_len + s2_len] = '\0';
	if (s1)
		free(s1);
	return (res);
}

int	ft_is_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_check_fd(t_list **static_list, int fd)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *static_list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
	{
		new = malloc(sizeof(t_list));
		new->fd = fd;
		new->str = NULL;
		new->next = *static_list;
		*static_list = new;
	}
	return (*static_list);
}

void	ft_free_node(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*pre;

	tmp = *list;
	pre = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		pre = tmp;
		tmp = tmp->next;
	}
	if (!pre)
		*list = tmp->next;
	else
		pre->next = tmp->next;
	free(tmp->str);
	free(tmp);
}

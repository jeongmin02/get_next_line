/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:29:46 by jerhee            #+#    #+#             */
/*   Updated: 2022/10/29 20:49:14 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// char	*fill_res(char *temp)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = ft_strchr(temp, '\n');
// 	if (i == 0)
// 		i = ft_strlen(temp);
// 	res = (char *)malloc(sizeof(char) * (i + 2));
// 	j = 0;
// 	while (j <= i)
// 	{
// 		res[j] = temp[j];
// 		j++;
// 	}
// 	res[j] = '\0';
// 	free(temp);
// 	return (res);
// }

// char	*fill_save(char *temp)
// {
// 	char	*save;
// 	int		i;
// 	int		j;

// 	i = ft_strchr(temp, '\n');
// 	if (i == 0)
// 		i = ft_strlen(temp);
// 	save = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i));
// 	j = 0;
// 	while (temp[i + j + 1])
// 	{
// 		save[j] = temp[i + j + 1];
// 		j++;
// 	}
// 	save[j] = '\0';
// 	if (j == 0)
// 		save = NULL;
// 	free(temp);
// 	return (save);
// }

char	*get_next_line(int fd)
{
	char			*str;
	t_list			*s_list;
	static t_list	*static_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_list = find_fd(&static_list, fd);
	s_list->str = ft_read_str(fd, s_list->str);
	
	// line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// temp = NULL;
	// if (save)
	// 	temp = save;
	// byte = 1;
	// while (byte)
	// {
	// 	byte = read(fd, line, BUFFER_SIZE);
	// 	if (byte == -1)
	// 	{
	// 		free(line);
	// 		return (NULL);
	// 	}
	// 	line[byte] = '\0';
	// 	temp = ft_strjoin(temp, line);
	// 	if (ft_strchr(line, '\n'))
	// 		break ;
	// }
	// free(line);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
	// if (!ft_strlen(temp))
	// {
	// 	free(temp);
	// 	return (NULL);
	// }
	// save = fill_save(temp);
	// return (fill_res(temp));
}

// int main(void)
// {
// 	int fd;

// 	fd = open("a.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// while (1)
// 	// {}
// }
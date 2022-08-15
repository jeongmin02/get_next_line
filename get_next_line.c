/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:26:08 by jerhee            #+#    #+#             */
/*   Updated: 2022/08/16 08:48:18 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*res;
	char		*temp;
	int			i;
	int 		j;
	int			byte;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = read(fd, line, BUFFER_SIZE);
	temp = NULL;
	while (byte)
	{
		temp = ft_strjoin(temp, line);
		if (ft_strchr(line, '\n'))
			break;
		byte = read(fd, line, BUFFER_SIZE);
	}
	i = ft_strchr(temp, '\n');
	// printf("%d\n", i);
	j = 0;
	res = (char *)malloc(sizeof(char) * (i + 1));
	while(j < i)
	{
		res[j] = temp[j];
		j++;
	}
	res[j] = '\0';
	// printf("res : %s\n", res);
	// printf("temp_len : %d\n", (int)ft_strlen(temp));
	save = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i));
	j = 0;
	while(temp[i + j + 1])
	{
		save[j] = temp[i + j + 1];
		j++;
	}
	save[i] = '\0';
	// printf("save : %s\n", save);
	return (res);
}

int main(void)
{
	int fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
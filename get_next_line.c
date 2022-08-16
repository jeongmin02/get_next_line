/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:26:08 by jerhee            #+#    #+#             */
/*   Updated: 2022/08/16 20:45:45 by jerhee           ###   ########.fr       */
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
	// printf("byte : %d\n", byte);
	// printf("line : %s\n", line);
	temp = NULL;
	if (save)
		temp = save;
	// if (!byte)
	// 	return (NULL);
	while (byte)
	{
		// printf("b_temp : %s\n", temp);
		temp = ft_strjoin(temp, line);
		// printf("temp : %s\n", temp);
		if (ft_strchr(line, '\n'))
			break;
		byte = read(fd, line, BUFFER_SIZE);
		line[byte] = '\0';
		// free(line);
		// printf("line : %s\n", line);
	}
	// i = 0;
	i = ft_strchr(temp, '\n');
	if (i == 0)
		i = ft_strlen(temp);
	// printf("temp : %s\n", temp);
	// printf("i : %d\n", i);
	j = 0;
	res = (char *)malloc(sizeof(char) * (i + 2));
	while(j <= i)
	{
		res[j] = temp[j];
		j++;
	}
	res[j] = '\0';
	// printf("res0 : %s\n", res);
	// printf("temp_len : %d\n", (int)ft_strlen(temp));
	save = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i));
	j = 0;
	// printf("res1 : %s\n", res);
	while(temp[i + j + 1])
	{
		save[j] = temp[i + j + 1];
		// printf("res2 : %s\n", res);
		j++;
	}
	save[j] = '\0';
	if (j == 0)
		save = NULL;
	// printf("save : %s\n", save);
	// printf("res3 : %s\n", res);
	return (res);
}

int main(void)
{
	int fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
}
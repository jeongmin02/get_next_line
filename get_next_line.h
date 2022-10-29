/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:31:05 by jerhee            #+#    #+#             */
/*   Updated: 2022/10/29 20:41:31 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*link;
}	t_list;

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_str(char *str);
char	*ft_get_remain_str(char *str);
size_t	*ft_strlen(char *s);
int		ft_isnewline(char *s, int c);
char 	*ft_strjoin(char *s1, char *s2);

#endif
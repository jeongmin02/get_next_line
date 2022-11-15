/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:19:36 by jerhee            #+#    #+#             */
/*   Updated: 2022/11/15 20:42:48 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_check_fd(t_list **static_list, int fd);
char	*ft_read_str(char *s_str, int fd);
void	ft_free_node(t_list **list, int fd);
char	*ft_show_line(char *s_str);
char	*ft_remain_line(char *s_str);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_is_strchr(char *s, int c);

#endif
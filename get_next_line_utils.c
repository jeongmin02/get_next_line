/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:26:05 by jerhee            #+#    #+#             */
/*   Updated: 2022/08/16 10:02:24 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*res;


	if (!s1 && s2)
	{
		res = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
		ft_strlcpy(res, (char *)s2, ft_strlen(s2) + 1);
		return (res);
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, s1_len + 1);
	ft_strlcat(res, (char *)s2, s1_len + s2_len + 1);
	//free(s1);
	return (res);
}

char	*ft_strdup(char *s1)
{
	int		s1_len;
	int		i;
	char	*res;

	s1_len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			//return ((char *)s + i);
			return(i);
		if (((unsigned char *)s)[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

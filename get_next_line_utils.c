/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/11 08:52:33 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		add_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	add_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)malloc(add_len * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	aux;

	aux = c;
	while (*s != '\0' && ((unsigned int)*s) != aux)
		s++;
	if (aux != ((unsigned int)*s))
		return (NULL);
	return ((char *)s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
	{
		return (j);
	}
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	size_t	len_char;

	len_char = ft_strlen(s);
	s_copy = malloc((len_char + 1) * sizeof(char));
	if (s == NULL || s_copy == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(s_copy, s, (len_char + 1));
	return (s_copy);
}

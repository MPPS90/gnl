/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/04/03 22:04:56 by mpena-so         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;
	size_t			i;

	i = 0;
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len == 0)
		return (0);
	if (start > (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i++] = s[start++];
	}
	sub_s[i] = '\0';
	return (sub_s);
}

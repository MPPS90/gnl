/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/01 18:53:41 by mpena-so         ###   ########.fr       */
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

void	ft_bzero(void *dst, size_t size)
{
	unsigned char	*aux;
	size_t			i;

	i = 0;
	aux = (unsigned char *) dst;
	while (i < size)
	{
		aux[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	memory = malloc(nmemb * size);
	if (memory == NULL)
	{
		return (NULL);
	}
	ft_bzero(memory, (nmemb * size));
	return (memory);
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
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}

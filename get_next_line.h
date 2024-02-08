/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:35 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/04 22:38:33 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

#include <unistd.h> //lirería read
#include <stddef.h> //para el size_t
#include <fcntl.h> //librería open
#include <stdlib.h> //librería calloc
#include <stdio.h> //librería printf
#include <string.h> // librería strlen

char    *get_next_line(int fd);
//void	ft_bzero(void *dst, size_t size); PENDIENTE SI LA USO O NO POR AHORA NO LA ESTOY USANDO
//void	*ft_calloc(size_t nmemb, size_t size); PENDIENTE SI LA USO O NO POR AHORA NO LA ESTOY USANDO
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);



#endif

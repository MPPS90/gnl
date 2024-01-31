/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:35 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/31 17:36:32 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 2
# endif

#include <unistd.h> //lirería read
#include <stddef.h> //para el size_t
#include <fcntl.h> //librería open
#include <stdlib.h> //librería calloc
#include <stdio.h> //librería printf
#include <string.h> // librería strlen

char    *get_next_line(int fd);
void	ft_bzero(void *dst, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);


#endif

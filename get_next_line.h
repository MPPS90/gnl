/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:35 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/21 18:40:17 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

#include <unistd.h> //lirería read
#include <stddef.h> //para el size_t
#include <fcntl.h> //librería open
#include <stdlib.h> //librería calloc
#include <stdio.h> //librería printf
#include <string.h> // librería strlen

char    *get_next_line(int fd);
int     ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char    *read_till_character(int fd, char *read_line);
char    *separate(char *read_line);



#endif

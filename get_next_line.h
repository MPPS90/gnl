/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:05:35 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/25 21:17:23 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

#include <unistd.h> //lirería read
#include <stddef.h> 
#include <fcntl.h> //librería open
#include <stdlib.h> //librería calloc
#include <stdio.h> //librería printf

char    *get_next_line(int fd);

#endif

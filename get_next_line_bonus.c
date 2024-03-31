/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/03/31 13:36:16 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_read_file(char *read_line, char *buffer)
{
	char	*aux;

	aux = read_line;
	read_line = ft_strjoin(read_line, buffer);
	free(aux);
	return (read_line);
}

static char	*read_file(int fd, char *read_line)
{
	char	*buffer;
	ssize_t	num_bytes;

	if (read_line == NULL)
	{
		read_line = (char *)ft_calloc(1, sizeof(char));
		if (read_line == NULL)
			return (NULL);
	}
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(read_line, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes < 0)
			return (free(buffer), free(read_line), NULL);
		if (num_bytes == 0)
			return (free(buffer), read_line);
		buffer[num_bytes] = '\0';
		read_line = free_read_file(read_line, buffer);
	}
	return (free(buffer), buffer = NULL, read_line);
}

static char	*separate(char *read_line)
{
	char	*keep_line;
	int		start;
	int		i;
	size_t	length;

	i = 0;
	if (!read_line[0])
		return (NULL);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (read_line[i] && read_line[i] == '\n')
		i++;
	start = i;
	length = strlen(read_line) - i;
	keep_line = ft_substr(read_line, start, length);
	return (keep_line);
}

static char	*get_final_line(char *read_line)
{
	char	*final_line;
	int		i;

	i = 0;
	while (read_line[i] != '\n' && read_line[i] != '\0')
		i++;
	if (read_line[i] == '\n')
		i++;
	final_line = ft_substr(read_line, 0, (i));
	return (final_line);
}

char	*get_next_line(int fd)
{
	static char	*read_line[1024];
	char		*final_line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(read_line[fd]), NULL);
	read_line[fd] = read_file(fd, read_line[fd]);
	if (!read_line[fd])
		return (NULL);
	if (!read_line[fd][0])
	{
		free(read_line[fd]);
		read_line[fd] = NULL;
		return (NULL);
	}
	final_line = get_final_line(read_line[fd]);
	aux = read_line[fd];
	read_line[fd] = separate(read_line[fd]);
	free(aux);
	aux = NULL;
	return (final_line);
}

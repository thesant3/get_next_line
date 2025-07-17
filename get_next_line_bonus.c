/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:18:45 by sgomez-m          #+#    #+#             */
/*   Updated: 2025/07/17 04:20:18 by sgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_gn_extract_line(char **s)
{
	char	*remainder;
	char	*line;
	int		len;

	if (!s || !*s)
		return (NULL);
	len = 0;
	while ((*s)[len] && (*s)[len] != '\n')
		len++;
	len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	remainder = ft_strdup(*s + len);
	while (len--)
		line[len] = (*s)[len];
	free(*s);
	*s = remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stashes[1024];
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stashes[fd], '\n') && bytes_read >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || ((bytes_read == 0) && stashes[fd]))
		{
			free(buffer);
			free(stashes[fd]);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stashes[fd] = ft_gn_strjoin(stashes[fd], buffer);
	}
	free(buffer);
	return (ft_gn_extract_line(&stashes[fd]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-m <sgomez-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:49:34 by sgomez-m          #+#    #+#             */
/*   Updated: 2025/07/08 01:01:46 by sgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**ft_gn_extract_line function extract the line until '\n' character from **s
 **after this it is released and allocated with the rest of the array.
 **
 **The **s atribute is the array that contains all bytes allocated by read().
 **
 **The function returns the line to prints o null in case of fail.
 */

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
	while (len--)
		line[len] = (*s)[len];
	remainder = ft_strdup(*s + len);
	free(*s);
	*s = remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	//char buffer[BUFFER_SIZE + 1];
	char	*buffer;
	//char	*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	//buffer[BUFFER_SIZE + 1] = '\0';
	if (!buffer)
		return (NULL);
	stash = NULL;
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_gn_strjoin(stash, buffer);
	}
	free(buffer);
	return(ft_gn_extract_line(&stash));

}

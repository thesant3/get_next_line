/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-m <sgomez-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:50:31 by sgomez-m          #+#    #+#             */
/*   Updated: 2025/07/15 21:37:08 by sgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_gn_extract_line(char **s);
char	*ft_gn_strjoin(char *s1, char *s2);
#endif

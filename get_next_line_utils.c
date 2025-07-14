/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-m <sgomez-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:44:08 by sgomez-m          #+#    #+#             */
/*   Updated: 2025/07/15 01:16:28 by sgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**ft_strlen() returns the length of a string
**recive as parameter an array of char
**returns Null is fails allocates memory
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
 **ft_strchr() returns a pointer to the first occurence of the character
 **c in the string str.
 **Returns NULL if the character is not found.
 */
char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*
*ft_strdup returns a duplicate string using malloc
*recive as parameter an array of char
*returns Null is fails allocates memory
*/
char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/**ft_gn_strjoin() combine two strings in new one
 **
 **
 **
 */
char	*ft_gn_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len1;
	int		len2;
	int		i;
	
	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	ptr[len1 + len2] = '\0';
	i = -1;
	while (++i < len1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < len2)
		ptr[len1 + i] = s2[i];
	free(s1);
	s1 = NULL;
	return (ptr);
}

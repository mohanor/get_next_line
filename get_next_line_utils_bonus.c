/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:44:50 by matef             #+#    #+#             */
/*   Updated: 2021/12/20 14:44:53 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == (unsigned char)c)
		return (s + i);
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	char	*newstr;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	newstr = (char *)malloc((ft_strlen(str)
				+ ft_strlen(buff) + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	i = -1;
	j = 0;
	while (str[++i])
		newstr[i] = str[i];
	while (buff[j])
		newstr[i++] = buff[j++];
	newstr[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free (str);
	return (newstr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

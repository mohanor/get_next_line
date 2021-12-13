/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:49:21 by matef             #+#    #+#             */
/*   Updated: 2021/12/11 23:49:24 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include<stdio.h> 
#include <fcntl.h>
#include <string.h>

static char	*ft_addtostr(char *str, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index;
	size_t	last_index;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	len = strlen(s1) + strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	ft_addtostr(str, s1);
	last_index = strlen(s1);
	index = 0;
	while (s2[index])
	{
		str[last_index + index] = s2[index];
		index++;
	}
	str[last_index + index] = '\0';
	return (str);
}

static char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == '\0' && c == '\0')
		return ((char *)&s[index]);
	return (0);
}

static char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
    {
        i++;
    }
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
    i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
    str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

static int has_newline(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] == '\n' || str[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}

char    *get_next_line(int fd)
{
    char     c[BUFFER_SIZE + 1];
    static char     *ptr = NULL;
    char            *str = "";
    int             sz;

    if (fd < 0 || BUFFER_SIZE < 1) return 0;
    if (ptr)
        str = ft_strjoin(str, ptr + 1);

    sz = read(fd, c, BUFFER_SIZE);
    if (sz <= 0) return 0;
    str = ft_strjoin(str, c);
    c[BUFFER_SIZE] = '\0';
    while (!has_newline(c) && sz)
    {
        sz = read(fd, c, BUFFER_SIZE);
        str = ft_strjoin(str, c);
		
        c[BUFFER_SIZE] = '\0';
    }
    ptr = ft_strchr(str, '\n');
    return ft_strdup(str);
}
/*
int main()
{
    int fd;

    fd = open("foo.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    return 0;
}*/

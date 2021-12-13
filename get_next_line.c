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

static char	*ft_strdup(char *s1);

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

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	index;
	size_t	last_index;
	char	*str;

	if (s1 == NULL)
		s1 = ft_strdup("");
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
	free(s1);
	return (str);
}

static char	*ft_strchr(char *s, int c)
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

static char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
    {
        i++;
    }
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
    i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		s[i] = '\n';
		s[i + 1] = '\0';
	}
	else
		s[i] = '\0';
	return (s);
}

static int has_newline(char *str)
{
    int i = 0;

	if(str == NULL)
		return (0);
    while (str[i])
    {
        if(str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *get_next_line(int fd)
{
    char			*c;
    static char     *ptr;
    char            *str;
    int             sz;

    if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	c = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!c)
		return 0;
	str = NULL;
	if (ptr)
	{
		str = ft_strjoin(str, ptr + 1);
	}
	sz = 1;
    while (!has_newline(str) && sz)
    {
        sz = read(fd, c, BUFFER_SIZE);
		if (sz < 0)
		{
			free(c);
			return (NULL);			
		}
		if (sz == 0)
			break ;
		c[BUFFER_SIZE] = '\0';
        str = ft_strjoin(str, c);
    }
    ptr = ft_strchr(str, '\n');
	free(c);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcoste <olcoste@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:20:22 by olcoste           #+#    #+#             */
/*   Updated: 2022/12/21 15:23:28 by olcoste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char *ret, char *buf)
{
	int	i;

	i = 0;
	if (buf[0] == '\0')
	{
		free (ret);
		return (NULL);
	}
	while (buf[i] && buf[i] != '\n')
	{
		ret[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_stock(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (ft_strlen(str) - i == 0)
		return (free(str), NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!ret)
		return (NULL);
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free (str);
	return (ret);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!(ret))
		return (NULL);
	while (s[i])
	{
		ret[i] = (char)s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*read_line(int fd, char *buf)
{
	int		byte;
	char	*line;

	byte = 1;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, line, BUFFER_SIZE);
		if (byte == -1)
		{
			free(line);
			return (NULL);
		}
		line[byte] = '\0';
		if (buf == NULL)
			buf = ft_strdup(line);
		else
			buf = ft_strjoin(buf, line);
		if (ft_strchr(buf, '\n') != -1)
			break ;
	}
	free (line);
	return (buf);
}

char	*get_next_line(int fd)
{
	char			*ret;
	static char		*buf;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	buf = read_line(fd, buf);
	if (buf == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strchr_end(buf, '\n') + 2));
	if (!ret)
		return (NULL);
	ret = ft_return(ret, buf);
	buf = ft_stock(buf);
	return (ret);
}

// #include <unistd.h>

// int		main(void)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	int fd = open("text.txt", O_RDWR);

// 	while (i < 7)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return 0;
// }

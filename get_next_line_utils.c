/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcoste <olcoste@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:04:01 by olcoste           #+#    #+#             */
/*   Updated: 2022/12/21 12:43:27 by olcoste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_end(char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL || c == 0)
		return (0);
	else if (s[0] == c)
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL || c == 0)
		return (0);
	else if (s[0] == c)
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*ret;

	i = 0;
	x = 0;
	ret = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(ret))
		return (NULL);
	while (s1[x])
		ret[i++] = s1[x++];
	x = 0;
	while (s2[x])
		ret[i++] = s2[x++];
	ret[i] = '\0';
	free (s1);
	return (ret);
}

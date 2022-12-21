/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcoste <olcoste@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:02:04 by olcoste           #+#    #+#             */
/*   Updated: 2022/12/21 15:20:35 by olcoste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
int		ft_strchr_end(char *s, int c);
char	*ft_stock(char *str);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buf);
char	*ft_return(char *ret, char *buf);
char	*ft_strjoin(char *s1, char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:21:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/10/14 11:26:43 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

char	*gnl_ft_strchr(const char *str, int c);
char	*ft_get_lstr(int fd, char *lstr);
char	*ft_get_line(char *lstr);
char	*ft_reset_lstr(char *lstr);
char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:47:32 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/30 13:47:32 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//get_next_line.c
char	*get_next_line(int fd);
char	*get_lines(char *str, int i);
char	*get_end_file(char *str, int i);
char	*get_all_file(int fd, char *str);

//get_next_line_utils.c
char	*ft_strjoin_bis(char *s1, char *s2);
int		in_str_gnl(char *str, char find);

#endif

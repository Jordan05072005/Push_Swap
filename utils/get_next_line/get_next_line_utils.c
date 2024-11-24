/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:47:29 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/30 13:47:29 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;	

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	dest = (char *)malloc((ft_strlen((const char *)s1)
				+ ft_strlen((const char *)s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (free(s1), NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (free(s1), dest);
}

int	in_str_gnl(char *str, char find)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == find)
			return (i);
		i++;
	}
	if (str[i] == find)
		return (i);
	return (-1);
}

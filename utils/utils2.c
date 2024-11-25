/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:51:16 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/14 17:51:16 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sort(int *pile, int max_pile, int i)
{
	int	j;

	while (i < max_pile)
	{
		j = i;
		while (j < max_pile)
		{
			if (pile[i] > pile[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_near_sort(int *pile, int max_pile, int first)
{
	int	i;
	int	min_temp;
	int	min;

	min = index_min(pile, first, max_pile);
	i = min + 1;
	if (i >= max_pile)
		i = first;
	min_temp = min;
	while (i != min)
	{
		if (pile[i] < pile[min_temp])
			return (0);
		min_temp = i;
		i++;
		if (i >= max_pile)
			i = first;
	}
	return (1);
}

t_pile	*ft_pilenew(size_t max_pile)
{
	t_pile	*newpile;

	newpile = malloc(sizeof(t_pile));
	if (newpile == NULL)
		return (NULL);
	newpile->max_pile = max_pile;
	newpile->pilea = ft_calloc(newpile->max_pile, sizeof(int));
	newpile->pileb = ft_calloc(newpile->max_pile, sizeof(int));
	newpile->sa = 0;
	newpile->sb = max_pile;
	newpile->next = NULL;
	return (newpile);
}

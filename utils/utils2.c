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

int	first_elem(int *pile, int max_pile)
{
	int	i;

	i = 0;
	while (i < max_pile)
	{
		if (pile[i] != 0)
			return (i);
		i++;
	}
	return (i);
}

int	strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sort(int *pile, int max_pile)
{
	int	i;
	int	j;

	i = first_elem(pile, max_pile);
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

int	is_near_sort(int *pile, int max_pile)
{
	int	i;
	int	min_temp;
	int	min;

	min = index_min(pile, first_elem(pile, max_pile), max_pile);
	i = min + 1;
	if (i >= max_pile)
		i = first_elem(pile, max_pile);
	min_temp = min;
	while (i != min)
	{
		if (pile[i] < pile[min_temp])
			return (0);
		min_temp = i;
		i++;
		if (i >= max_pile)
			i = first_elem(pile, max_pile);
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
	newpile->next = NULL;
	return (newpile);
}

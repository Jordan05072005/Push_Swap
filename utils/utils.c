/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:35:08 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/09 14:35:08 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len_pile(t_pile **p, char select)
{
	if (select == 'a')
		return ((*p)->max_pile - (*p)->sa);
	return ((*p)->max_pile - (*p)->sb);
}

int	index_min(int *pile, int first, int max_pile)
{
	int	min;

	min = first;
	while (first < max_pile)
	{
		if (pile[first] < pile[min])
			min = first;
		first++;
	}
	return (min);
}

int	index_max(int *pile, int first, int max_pile)
{
	int	max;

	max = first;
	while (first < max_pile)
	{
		if (pile[first] > pile[max])
			max = first;
		first++;
	}
	return (max);
}

// Search and find for the largest number among the numbers less than a "nbr"
int	index_max_inf(int *pile, int first_p, int nbr, int max_pile)
{
	int	compt;
	int	max;
	int	verr;

	verr = 1;
	max = index_max(pile, first_p, max_pile);
	while (first_p < max_pile)
	{
		if (pile[first_p] < nbr && pile[first_p] > pile[max])
			max = first_p;
		if (pile[first_p] < nbr && pile[max] > nbr)
			max = first_p;
		first_p++;
	}
	return (max);
}

// Search and find for the smallest number 
// among the numbers greater than a "nbr"
int	index_min_sup(int *pile, int first_p, int nbr, int max_pile)
{
	int	compt;
	int	min;
	int	verr;

	verr = 1;
	min = index_min(pile, first_p, max_pile);
	while (first_p < max_pile)
	{
		if (pile[first_p] > nbr && pile[first_p] < pile[min])
			min = first_p;
		if (pile[first_p] > nbr && pile[min] < nbr)
			min = first_p;
		first_p++;
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:27:01 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/09 21:27:01 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(char **str, int word, int nbr)
{
	if (ft_strncmp(INTX, str[word], ft_strlen(str[word])) < 0
		&& str[word][0] != '-' && ft_strlen(str[word]) >= 10)
		return (0);
	if (ft_strncmp(INTM, str[word], ft_strlen(str[word])) < 0
		&& str[word][0] == '-' && ft_strlen(str[word]) >= 11)
		return (0);
	return (1);
}

int	is_number(char **str)
{
	int		words;
	int		letters;
	long	nbr;

	words = 0;
	while (str[words] != 0)
	{
		letters = 0;
		nbr = 0;
		while (str[words][letters])
		{
			if (str[words][letters] == '-' || str[words][letters] == '+')
				letters++;
			if (!ft_isdigit(str[words][letters]))
				return (0);
			letters++;
		}
		nbr = ft_atoi(str[words]);
		if (!is_valid(str, words, nbr))
			return (0);
		words++;
	}
	return (1);
}

int	is_unique(char **str, int *pile)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		pile[i] = ft_atoi(str[i]);
		j = 0;
		while (j < i)
		{
			if (pile[i] == pile[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_pile	*parsing(char **pile, size_t max_pile, int split)
{
	t_pile	*pile_int;
	int		i;
	int		temp;

	i = -1;
	if (!pile[0])
		return (0);
	if (split)
		max_pile = strstrlen(pile);
	pile_int = ft_pilenew(max_pile);
	if (pile_int->pilea == NULL || pile_int->pileb == NULL)
	{
		free_lst(&pile_int);
		return (0);
	}
	if (!is_number(pile) || !is_unique(pile, pile_int->pilea))
	{
		if (split)
			free_lststr(pile);
		free_lst(&pile_int);
		return (0);
	}
	if (split)
		free_lststr(pile);
	return (pile_int);
}

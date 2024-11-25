/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:07:49 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/09 23:07:49 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		pile = parsing(ft_split(argv[1], ' '), argc - 1, 1);
	else
		pile = parsing(++argv, argc - 1, 0);
	if (pile == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!is_sort(pile->pilea, pile->max_pile, pile->sa))
	{
		if (pile->max_pile <= 3)
			sort_little(&pile, pile->max_pile);
		else
			sort(&pile);
	}
	free_lst(&pile);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:43:48 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/10 21:43:48 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	sum_max(int nbr1, int nbr2, int sum, int *small_d)
{
	if (small_d[2] > sum)
	{
		small_d[0] = nbr1;
		small_d[1] = nbr2;
		small_d[2] = sum;
	}
	return ;
}

//Search for the smallest number of instruction to put on top 
// of the stack (pile) "index_a" and "index_b"

int	*up_nbr(int *firsts, int max_p, int index_a, int index_b)
{
	int	diff_b[2];
	int	diff_a[2];
	int	*small_d;

	small_d = malloc(sizeof(int) * 3);
	diff_a[0] = index_a - firsts[0];
	diff_a[1] = ((max_p - index_a));
	diff_b[0] = index_b - firsts[1];
	diff_b[1] = ((max_p - index_b));
	small_d[0] = diff_a[0];
	small_d[1] = diff_b[0];
	small_d[2] = ft_max(diff_a[0], diff_b[0]);
	sum_max(diff_a[0], -diff_b[1], diff_a[0] + diff_b[1], small_d);
	sum_max(-diff_a[1], -diff_b[1], ft_max(diff_a[1], diff_b[1]), small_d);
	sum_max(-diff_a[1], diff_b[0], diff_a[1] + diff_b[0], small_d);
	return (small_d);
}

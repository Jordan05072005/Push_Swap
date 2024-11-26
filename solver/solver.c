/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:45:43 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/10 13:45:43 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// instr_seq : [0] -> nbr instruction for pile a 
//[1] -> nbr instruction  for pile b
//[2] -> instruction total

int	*smallest_push(t_pile **p, int *a, int *b, int first)
{
	int	i_nbrb;
	int	*instr_seq;
	int	*temp;
	int	firsts[2];
	int	max_p;

	max_p = (*p)->max_pile;
	firsts[0] = first;
	firsts[1] = (*p)->sb;
	i_nbrb = index_max_inf(b, (*p)->sb, a[first], max_p);
	instr_seq = up_nbr(firsts, max_p, first, i_nbrb);
	while (++first < max_p)
	{
		i_nbrb = index_max_inf(b, (*p)->sb, a[first], max_p);
		temp = up_nbr(firsts, max_p, first, i_nbrb);
		if (temp[2] < instr_seq[2])
		{
			free(instr_seq);
			instr_seq = temp;
		}
		else
			free(temp);
	}
	return (instr_seq);
}

void	imple_instr(t_pile **p, int insta, int instb)
{
	if (insta > 0 && instb > 0)
		return (rotate(p, 'r', 1), imple_instr(p, insta - 1, instb - 1));
	else if (insta < 0 && instb < 0)
		return (reverse_rotate(p, 'r', 1),
			imple_instr(p, insta + 1, instb + 1));
	else if (insta > 0)
		return (rotate(p, 'a', 1), imple_instr(p, insta - 1, instb));
	else if (insta < 0)
		return (reverse_rotate(p, 'a', 1), imple_instr(p, insta + 1, instb));
	else if (instb > 0)
		return (rotate(p, 'b', 1), imple_instr(p, insta, instb - 1));
	else if (instb < 0)
		return (reverse_rotate(p, 'b', 1), imple_instr(p, insta, instb + 1));
}

void	sort_little(t_pile **p, int max_p)
{
	int	temp;

	if (max_p == 1)
		return ;
	else if (max_p == 2 && !is_sort((*p)->pilea, (*p)->max_pile, (*p)->sa))
		swap(p, 'a', 1);
	if (!is_sort((*p)->pilea, (*p)->max_pile, (*p)->sa))
	{
		if (max_p == 3 && !is_near_sort((*p)->pilea, (*p)->max_pile, (*p)->sa))
			swap(p, 'a', 1);
		temp = index_min((*p)->pilea, (*p)->sa, (*p)->max_pile);
		while (!is_sort((*p)->pilea, (*p)->max_pile, (*p)->sa))
		{
			if (temp < (*p)->max_pile / 2)
				rotate(p, 'a', 1);
			else
				reverse_rotate(p, 'a', 1);
		}
	}
}

void	sort2(t_pile **p)
{
	int	*index;
	int	firsts[2];
	int	temp;

	while (len_pile(p, 'b') != 0)
	{
		firsts[0] = (*p)->sa;
		firsts[1] = (*p)->sb;
		temp = index_min_sup((*p)->pilea, firsts[0],
				(*p)->pileb[firsts[1]], (*p)->max_pile);
		index = up_nbr(firsts, (*p)->max_pile, temp, firsts[1]);
		imple_instr(p, index[0], index[1]);
		free(index);
		push(p, 'a', 1);
	}
	sort_little(p, (*p)->max_pile);
}

void	sort(t_pile **p)
{
	int	*index;
	int	min;

	push(p, 'b', 1);
	push(p, 'b', 1);
	while (len_pile(p, 'a') > 3)
	{
		index = smallest_push(p, (*p)->pilea, (*p)->pileb, (*p)->sa);
		imple_instr(p, index[0], index[1]);
		push(p, 'b', 1);
		free(index);
	}
	min = index_max((*p)->pileb, (*p)->sb, (*p)->max_pile);
	while (index_max((*p)->pileb, (*p)->sb, (*p)->max_pile) != (*p)->sb)
	{
		if (min < (*p)->max_pile / 2)
			rotate(p, 'b', 1);
		else
			reverse_rotate(p, 'b', 1);
	}
	if (!is_near_sort((*p)->pilea, (*p)->max_pile, (*p)->sa))
		swap(p, 'a', 1);
	sort2(p);
}

/*
void	print(int *pile, int max, int select)
{
	int	i;

	i = 0;
	while (i < max)
	{
		printf("%c : %d\n",select,  pile[i]);
		i++;
	}
	printf("\n");
}


#include <stdio.h>

int	is(int *pile, int max, int nbr)
{
	int i = 0;

	while (i < max)
	{
		if (pile[i] == nbr)
			return (1);
		i++;
	}
	return 0;
}

int main(void)
{
	int	max_pile = 5;
	int i = 0;
	int nbr;
	t_pile *p;
	p = ft_pilenew(max_pile);
	while (i < max_pile)
	{
		nbr = (rand() % (1000 - (-1000) + 1)) + -1000;
		if (!is(p->pilea, max_pile, nbr))
		{
			p->pilea[i] = nbr;
			i++;
		}
	}
	sort(&p);
	//print(p->pilea, p->max_pile, 'a');
	if (is_sort(p->pilea, p->max_pile, p->sa))
		printf("gg");
}
*/
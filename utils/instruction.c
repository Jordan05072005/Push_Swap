/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:14:25 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/09 14:14:25 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pile **p, char select, int print)
{
	int		temp;
	int		first;

	first = first_elem((*p)->pilea, (*p)->max_pile);
	if ((select == 'a' || select == 's')
		&& (*p)->pilea[first] && (*p)->pilea[first + 1])
	{
		temp = (*p)->pilea[first];
		(*p)->pilea[first] = (*p)->pilea[first + 1];
		(*p)->pilea[first + 1] = temp;
	}
	first = first_elem((*p)->pileb, (*p)->max_pile);
	if ((select == 'b' || select == 's')
		&& (*p)->pileb[first] && (*p)->pileb[first + 1])
	{
		temp = (*p)->pileb[first];
		(*p)->pileb[first] = (*p)->pileb[first + 1];
		(*p)->pileb[first + 1] = temp;
	}
	if (print)
		ft_printf("s%c\n", select);
}

void	push(t_pile **p, char select, int print)
{
	if (select == 'a' && (*p)->pileb)
	{
		(*p)->pilea[first_elem((*p)->pilea, (*p)->max_pile) - 1]
			= (*p)->pileb[first_elem((*p)->pileb, (*p)->max_pile)];
		(*p)->pileb[first_elem((*p)->pileb, (*p)->max_pile)] = 0;
	}
	if (select == 'b' && (*p)->pilea)
	{
		(*p)->pileb[first_elem((*p)->pileb, (*p)->max_pile) - 1]
			= (*p)->pilea[first_elem((*p)->pilea, (*p)->max_pile)];
		(*p)->pilea[first_elem((*p)->pilea, (*p)->max_pile)] = 0;
	}
	if (print)
		ft_printf("p%c\n", select);
}

void	rotate(t_pile **p, char select, int print)
{
	int		temp;
	int		first;
	size_t	size;

	if (select == 'a' || select == 'r')
	{
		first = first_elem((*p)->pilea, (*p)->max_pile);
		size = sizeof(int) * ((*p)->max_pile - 1 - first);
		temp = (*p)->pilea[first];
		ft_memmove((*p)->pilea + first, (*p)->pilea + first + 1, size);
		(*p)->pilea[(*p)->max_pile - 1] = temp;
	}
	if (select == 'r' || select == 'b')
	{
		first = first_elem((*p)->pileb, (*p)->max_pile);
		size = sizeof(int) * ((*p)->max_pile - 1 - first);
		temp = (*p)->pileb[first];
		ft_memmove((*p)->pileb + first, (*p)->pileb + first + 1, size);
		(*p)->pileb[(*p)->max_pile - 1] = temp;
	}
	if (print)
		ft_printf("r%c\n", select);
}

void	reverse_rotate(t_pile **p, char select, int print)
{
	int		temp;
	int		first;
	size_t	size;

	if (select == 'a' || select == 'r')
	{
		first = first_elem((*p)->pilea, (*p)->max_pile);
		size = sizeof(int) * ((*p)->max_pile - 1 - first);
		temp = (*p)->pilea[(*p)->max_pile - 1];
		ft_memmove((*p)->pilea + first + 1, (*p)->pilea + first, size);
		(*p)->pilea[first] = temp;
	}
	if (select == 'b' || select == 'r')
	{
		first = first_elem((*p)->pileb, (*p)->max_pile);
		size = sizeof(int) * ((*p)->max_pile - 1 - first);
		temp = (*p)->pileb[(*p)->max_pile - 1];
		ft_memmove((*p)->pileb + first + 1, (*p)->pileb + first, size);
		(*p)->pileb[first] = temp;
	}
	if (print)
		ft_printf("rr%c\n", select);
}

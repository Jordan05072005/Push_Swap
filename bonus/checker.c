/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:51:20 by jguaglio          #+#    #+#             */
/*   Updated: 2024/11/24 22:51:20 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	apply_inst(t_pile **p, char *str)
{
	if (!ft_strncmp(str, "pa", 2))
		push(p, 'a', 0);
	else if (!ft_strncmp(str, "pb", 2))
		push(p, 'b', 0);
	else if (!ft_strncmp(str, "sa", 2))
		swap(p, 'a', 0);
	else if (!ft_strncmp(str, "sb", 2))
		swap(p, 'b', 0);
	else if (!ft_strncmp(str, "ss", 2))
		swap(p, 's', 0);
	else if (!ft_strncmp(str, "rra", 3))
		reverse_rotate(p, 'a', 0);
	else if (!ft_strncmp(str, "rrb", 3))
		reverse_rotate(p, 'b', 0);
	else if (!ft_strncmp(str, "rrr", 3))
		reverse_rotate(p, 'r', 0);
	else if (!ft_strncmp(str, "ra", 2))
		rotate(p, 'a', 0);
	else if (!ft_strncmp(str, "rb", 2))
		rotate(p, 'b', 0);
	else if (!ft_strncmp(str, "rr", 2))
		rotate(p, 'r', 0);
	else
		return (1);
	return (0);
}

int	read_instr(t_pile **p)
{
	char	*str;
	int		err;

	str = NULL;
	str = get_next_line(1);
	while (str != NULL)
	{
		if (str[0] == '\n')
			break ;
		err = apply_inst(p, str);
		free(str);
		if (err)
			return (err);
		str = get_next_line(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*pile;
	int		err;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (argc == 2)
		pile = parsing(ft_split(argv[1], ' '), argc - 1, 1);
	else
		pile = parsing(++argv, argc - 1, 0);
	if (pile == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	err = read_instr(&pile);
	if (err)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sort(pile->pilea, pile->max_pile))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&pile);
}
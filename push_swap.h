/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:06:11 by jguaglio          #+#    #+#             */
/*   Updated: 2024/11/24 17:06:11 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "utils/ft_printf/ft_printf.h"
# include "utils/libft/libft.h"
# include "utils/get_next_line/get_next_line.h"
# define INTX "2147483647"
# define INTM "-2147483648"

typedef struct s_pile
{
	int				*pilea;
	int				*pileb;
	int				max_pile;
	struct s_pile	*next;
}					t_pile;

//checker.c
int	read_instr(t_pile **p);
int	apply_inst(t_pile **p, char *str);

//up_value.c
int		ft_max(int a, int b);
void	sum_max(int nbr1, int nbr2, int sum, int *small_d);
int		*up_nbr(int *first, int max_p, int index_a, int index_b);

//solver.c
int		*smallest_push(int *a, int *b, int first, int max_p);
void	imple_instr(t_pile **p, int insta, int instb);
void	sort2(t_pile **p);
void	sort(t_pile **a);
void	sort_little(t_pile **p, int max_p);

//parseur.c
t_pile	*parsing(char **pile, size_t max_pile, int split);
int		is_unique(char **str, int *pile);
int		is_number(char **str);
int		is_valid(char **str, int word, int nbr);

// utils.c
int		len_pile(int *pile, int max_pile);
int		index_min(int *pile, int first, int max_pile);
int		index_max(int *pile, int first, int max_pile);
int		index_max_inf(int *pile, int first, int index, int max_pile);
int		index_min_sup(int *pile, int first_p, int nbr, int max_pile);

//utils2.c
int		first_elem(int *pile, int max_pile);
int		is_near_sort(int *pile, int max_pile);
int		is_sort(int *pile, int max_pile);
int		strstrlen(char **str);
t_pile	*ft_pilenew(size_t max_pile);

//instruction.c
void	swap(t_pile **p, char select, int print);
void	push(t_pile **p, char select, int print);
void	rotate(t_pile **p, char select, int print);
void	reverse_rotate(t_pile **p, char select, int print);

//free.c
void	free_lststr(char **str);
void	free_lst(t_pile **pile);

#endif
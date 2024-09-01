/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_nbr_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:04:03 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:06 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_best_nbr_result(t_stack *stk_a, t_stack *stk_b, int nb_a, int nb_b)
{
	int	ind_a;
	int	ind_b;
	int	best_nbr_res;

	ind_a = ft_find_index(stk_a, nb_a);
	ind_b = ft_find_index(stk_b, nb_b);
	if (ind_a == 0 && ind_b == 0)
		return (1);
	best_nbr_res = ft_count_ra_rb(ind_a, ind_b);
	if (best_nbr_res > ft_count_rra_rrb(stk_a, stk_b, ind_a, ind_b))
		best_nbr_res = ft_count_rra_rrb(stk_a, stk_b, ind_a, ind_b);
	if (best_nbr_res > ft_count_ra_rrb(stk_b, ind_a, ind_b))
		best_nbr_res = ft_count_ra_rrb(stk_b, ind_a, ind_b);
	if (best_nbr_res > ft_count_rb_rra(stk_a, ind_a, ind_b))
		best_nbr_res = ft_count_rb_rra(stk_a, ind_a, ind_b);
	return (best_nbr_res);
}

int	ft_count_ra_rb(int ind_a, int ind_b)
{
	if (ind_b == 0)
		return (ind_a + 1);
	else if (ind_a == 0)
		return (ind_b + 1);
	else if (ind_a > ind_b)
		return (ind_a + 1);
	else
		return (ind_b + 1);
}

int	ft_count_rra_rrb(t_stack *st_a, t_stack *st_b, int ind_a, int ind_b)
{
	int	size_st_a;
	int	size_st_b;

	size_st_a = ft_stk_size(st_a);
	size_st_b = ft_stk_size(st_b);
	if (ind_b == 0)
		return (size_st_a - ind_a + 1);
	else if (ind_a == 0)
		return (size_st_b - ind_b + 1);
	else if ((size_st_a - ind_a) > (size_st_b - ind_b))
		return (size_st_a - ind_a + 1);
	else
		return (size_st_b - ind_b + 1);
}

int	ft_count_ra_rrb(t_stack *stk_b, int ind_a, int ind_b)
{
	int	count_ra;
	int	count_rrb;

	count_ra = ind_a;
	if (ind_b == 0)
		count_rrb = 0;
	else
		count_rrb = ft_stk_size(stk_b) - ind_b;
	return (count_ra + count_rrb + 1);
}

int	ft_count_rb_rra(t_stack *stk_a, int ind_a, int ind_b)
{
	int	count_rb;
	int	count_rra;

	count_rb = ind_b;
	if (ind_a == 0)
		count_rra = 0;
	else
		count_rra = ft_stk_size(stk_a) - ind_a;
	return (count_rb + count_rra + 1);
}

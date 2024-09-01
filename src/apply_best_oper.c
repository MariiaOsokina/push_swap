/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_oper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:54 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:02 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_apply_best_operation(t_stack **stk_a, t_stack **stk_b)
{
	int	best_total_res;
	int	best_nbr;
	int	ind_a;
	int	ind_b;

	best_nbr = (*stk_a)->nbr;
	best_total_res = ft_best_total_result(*stk_a, *stk_b, &best_nbr);
	ind_a = ft_find_index(*stk_a, best_nbr);
	ind_b = ft_find_index(*stk_b, ft_find_top_b(*stk_b, best_nbr));
	if (best_total_res == ft_count_ra_rb(ind_a, ind_b))
		ft_apply_ra_rb(stk_a, stk_b, ind_a, ind_b);
	else if (best_total_res == ft_count_rra_rrb(*stk_a, *stk_b, ind_a, ind_b))
		ft_apply_rra_rrb(stk_a, stk_b, ind_a, ind_b);
	else if (best_total_res == ft_count_ra_rrb(*stk_b, ind_a, ind_b))
		ft_apply_ra_rrb(stk_a, stk_b, ind_a, ind_b);
	else if (best_total_res == ft_count_rb_rra(*stk_a, ind_a, ind_b))
		ft_apply_rb_rra(stk_a, stk_b, ind_a, ind_b);
}

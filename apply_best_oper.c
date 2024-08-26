/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_best_oper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:56:54 by mosokina          #+#    #+#             */
/*   Updated: 2024/07/21 19:48:50 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_apply_best_operation(t_stack **stack_a, t_stack **stack_b)
{
	int	best_total_res;
	int	best_nbr;
	int	ind_a;
	int	ind_b;

	best_nbr = (*stack_a)->nbr;
	best_total_res = ft_best_total_result(*stack_a, *stack_b, &best_nbr);
	ind_a = ft_find_index(*stack_a, best_nbr);
	ind_b = ft_find_index(*stack_b, ft_find_top_b(*stack_b, best_nbr));
	if (best_total_res == ft_count_ra_rb(ind_a, ind_b))
		ft_apply_ra_rb(stack_a, stack_b, ind_a, ind_b);
	else if (best_total_res == ft_count_rra_rrb(*stack_a, *stack_b, ind_a, ind_b))
		ft_apply_rra_rrb(stack_a, stack_b, ind_a, ind_b);
	else if (best_total_res == ft_count_ra_rrb(*stack_b, ind_a, ind_b))
		ft_apply_ra_rrb(stack_a, stack_b, ind_a, ind_b);
	else if (best_total_res == ft_count_rb_rra(*stack_a, ind_a, ind_b))
		ft_apply_rb_rra(stack_a, stack_b, ind_a, ind_b);	
}

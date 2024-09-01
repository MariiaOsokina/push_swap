/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:07:15 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 13:07:15 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_from_b_to_a(t_stack **stk_a, t_stack **stk_b)
{
	int	best_res;
	int	top_a;
	int	ind_a;
	int	ind_b;

	while (*stk_b)
	{
		top_a = ft_find_top_a(*stk_a, (*stk_b)->nbr);
		best_res = ft_best_nbr_result(*stk_a, *stk_b, top_a, (*stk_b)->nbr);
		ind_a = ft_find_index(*stk_a, top_a);
		ind_b = ft_find_index(*stk_b, (*stk_b)->nbr);
		if (best_res == ft_count_ra_rb(ind_a, ind_b))
			ft_apply_ra_rb_a(stk_a, stk_b, ind_a, ind_b);
		else if (best_res == ft_count_rra_rrb(*stk_a, *stk_b, ind_a, ind_b))
			ft_apply_rra_rrb_a(stk_a, stk_b, ind_a, ind_b);
		else if (best_res == ft_count_ra_rrb(*stk_b, ind_a, ind_b))
			ft_apply_ra_rrb_a(stk_a, stk_b, ind_a, ind_b);
		else if (best_res == ft_count_rb_rra(*stk_a, ind_a, ind_b))
			ft_apply_rb_rra_a(stk_a, stk_b, ind_a, ind_b);
	}
}

int	ft_find_top_a(t_stack *stack_a, int nbr_b)
{
	int	min_a;

	min_a = ft_min_stack(stack_a);
	if ((nbr_b > ft_max_stack(stack_a)) || nbr_b < min_a)
		return (min_a);
	else if ((nbr_b < stack_a->nbr) && (nbr_b > (ft_laststack(stack_a))->nbr))
		return (stack_a->nbr);
	while (stack_a)
	{
		if (nbr_b < (stack_a->next)->nbr)
			if (nbr_b > stack_a->nbr)
				return ((stack_a->next)->nbr);
		stack_a = stack_a->next;
	}
	return (0);
}

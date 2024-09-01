/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:52:27 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:45 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_from_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stk_size(*stack_a) > 3)
		ft_pb(stack_a, stack_b, 0);
	if (ft_stk_size(*stack_a) > 3)
		ft_pb(stack_a, stack_b, 0);
	while (ft_stk_size(*stack_a) > 3)
		ft_apply_best_operation(stack_a, stack_b);
}

int	ft_best_total_result(t_stack *stack_a, t_stack *stack_b, int *best_nbr)
{
	int		best_total_res;
	int		best_nbr_res;
	int		nbr_a;
	t_stack	*tmp_stack;
	int		top_b;

	tmp_stack = stack_a;
	top_b = ft_find_top_b(stack_b, *best_nbr);
	best_total_res = ft_best_nbr_result(stack_a, stack_b, *best_nbr, top_b);
	while (tmp_stack)
	{
		nbr_a = tmp_stack->nbr;
		top_b = ft_find_top_b(stack_b, nbr_a);
		best_nbr_res = ft_best_nbr_result(stack_a, stack_b, nbr_a, top_b);
		if (best_nbr_res < best_total_res)
		{
			best_total_res = best_nbr_res;
			*best_nbr = nbr_a;
		}
		tmp_stack = tmp_stack->next;
	}
	return (best_total_res);
}

int	ft_find_top_b(t_stack *stack_b, int nbr_a)
{
	int	max_b;

	max_b = ft_max_stack(stack_b);
	if ((nbr_a > max_b) || nbr_a < ft_min_stack(stack_b))
		return (max_b);
	else if ((nbr_a > stack_b->nbr) && (nbr_a < (ft_laststack(stack_b))->nbr))
		return (stack_b->nbr);
	while (stack_b)
	{
		if (nbr_a > (stack_b->next)->nbr)
			if (nbr_a < stack_b->nbr)
				return (stack_b->next->nbr);
		stack_b = stack_b->next;
	}
	return (0);
}

int	ft_min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

int	ft_abs(int i)
{
	if (i < 0)
		i = i * (-1);
	return (i);
}

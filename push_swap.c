/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:31:53 by mosokina          #+#    #+#             */
/*   Updated: 2024/06/17 13:31:55 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)		
		return (0);
	ft_parse(argc, argv, &stack_a, &stack_b);
	if (ft_check_dup(stack_a) == 1)
		ft_error(&stack_a, &stack_b);
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stk_size(stack_a) == 2)
			ft_sa(&stack_a, 0);
		else if (ft_stk_size (stack_a) == 3)
			ft_sort_three(&stack_a);
		else
			ft_big_sort(&stack_a, &stack_b);
	}
	ft_clean_stack(&stack_a);
	ft_clean_stack(&stack_b);
	return (0);
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_from_a_to_b(stack_a, stack_b);
	if (ft_stk_size(*stack_a) == 3 && !ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	ft_from_b_to_a(stack_a, stack_b);
	ft_min_a_to_top(stack_a);
	// printf("stack a:\n");
	// ft_print_stack(*stack_a);
	// printf("stack b:\n");
	// ft_print_stack(*stack_b);
}

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->nbr == ft_min_stack(*stack_a))
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if ((*stack_a)->nbr == ft_max_stack(*stack_a))
	{
		ft_ra(stack_a, 0);
		if (!ft_is_sorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if ((ft_laststack(*stack_a))->nbr == ft_min_stack(*stack_a))
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}

void	ft_min_a_to_top(t_stack **stack_a)
{
	int ind_min_a;

	ind_min_a = ft_find_index(*stack_a, ft_min_stack(*stack_a));
	if (ind_min_a < ft_stk_size(*stack_a) - ind_min_a)
	{
		while ((*stack_a)->nbr != ft_min_stack(*stack_a))
			ft_ra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->nbr != ft_min_stack(*stack_a))
			ft_rra(stack_a, 0);
	}
}
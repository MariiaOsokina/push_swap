/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:09:27 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:45 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stk_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i ++;
	}
	return (i);
}

int	ft_max_stack(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_min_stack(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_find_index(t_stack *stack, int nbr)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->nbr == nbr)
			return (count);
		stack = stack->next;
		count ++;
	}
	return (-1);
}

int	ft_is_sorted(t_stack	*stack)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
		if (tmp->nbr > stack->nbr)
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:57:17 by mosokina          #+#    #+#             */
/*   Updated: 2024/07/19 13:57:19 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int nbr)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->nbr = nbr;
	new_elem->next = NULL;
	return (new_elem);
}

t_stack	*ft_laststack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_prevstack(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	ft_clean_stack(t_stack	**stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}

// void	ft_print_stack(t_stack *stack)
// {
// 	while (stack != NULL)
// 	{
// 		printf("%d\n", stack->nbr);
// 		stack = stack->next;
// 	}
// }
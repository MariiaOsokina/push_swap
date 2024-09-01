/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:43:20 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 16:53:45 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*FUCTION SWAP*/
static void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/*sa (swap a): 
- Swap the first 2 elements at the top of stack a.
- Do nothing if there is only one or no elements.*/

void	ft_sa(t_stack **a, int j)
{
	if (!(*a) || !((*a)->next))
		return ;
	ft_swap(a);
	if (j == 0)
		write(1, "sa\n", 3);
}

/*sb (swap b): 
- Swap the first 2 elements at the top of stack b.
- Do nothing if there is only one or no elements.*/

void	ft_sb(t_stack **b, int j)
{
	if (!(*b) || !((*b)->next))
		return ;
	ft_swap(b);
	if (j == 0)
		write(1, "sb\n", 3);
}

/*ss : 
- sa and sb at the same time.
- Do nothing if there is only one or no elements.*/

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	if (!(*a) || !((*a)->next) || !(*b) || !((*b)->next))
		return ;
	ft_swap(a);
	ft_swap(b);
	if (j == 0)
		write(1, "ss\n", 3);
}

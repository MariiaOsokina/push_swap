#include "push_swap.h"

/*REVERSE ROTATE FUNCTION*/
static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack	*prev_stack;

	// /*Do nothing if there is only one or no elements.*/
	// if (!(*stack) || !(*stack)->next)
	// 	return ;
	prev_stack = ft_prevstack(*stack);
	tmp = *stack;
	*stack = prev_stack->next;
	(*stack)->next = tmp;
	prev_stack->next = NULL;
}

/*rra (reverse rotate a): 
- Shift down all elements of stack a by 1.
- The last element becomes the first one.*/

void	ft_rra(t_stack **a, int j)
{
	if (!(*a) || !(*a)->next)
		return ;
	ft_reverse_rotate(a);
	if (j == 0)
		write(1, "rra\n", 4);
}

/*rrb (reverse rotate b): 
- Shift down all elements of stack b by 1.
- The last element becomes the first one.*/
void	ft_rrb(t_stack **b, int j)
{
	if (!(*b) || !(*b)->next)
		return ;
	ft_reverse_rotate(b);
	if (j == 0)
		write(1, "rrb\n", 4);
}

/*rrr : 
- rra and rrb at the same time.*/
void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (j == 0)
		write(1, "rrr\n", 4);
}
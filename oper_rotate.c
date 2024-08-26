#include "push_swap.h"

/*FUCTION ROTATE*/
static void	ft_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *last_stack;

	// /*Do nothing if there is only one or no elements.*/
	// if (!(*stack) || !(*stack)->next)
	// 	return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last_stack = ft_laststack(*stack);
	tmp->next = NULL;
	last_stack->next = tmp;
}

/*ra (rotate a): 
- Shift up all elements of stack a by 1. 
- The first element becomes the last one.*/
void	ft_ra(t_stack **a, int j)
{
	if (!(*a) || !(*a)->next)
		return ;
	ft_rotate(a);
	if (j == 0)
		write(1, "ra\n", 3);
}


/*
rb (rotate b): 
- Shift up all elements of stack b by 1.
- The first element becomes the last one.*/

void	ft_rb(t_stack **b, int j)
{
	if (!(*b) || !(*b)->next)
		return ;
	ft_rotate(b);
	if (j == 0)
		write(1, "rb\n", 3);
}

/* rr : 
- ra and rb at the same time.*/
void	ft_rr(t_stack **a, t_stack **b, int j)
{
	if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	if (j == 0)
		write(1, "rr\n", 3);
}
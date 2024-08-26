#include "push_swap.h"

/*pa (push a): 
- Take the first element at the top of b and put it at the top of a.
- Do nothing if b is empty.*/

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!(*b))
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

/*pb (push b): 
- Take the first element at the top of a and put it at the top of b.
- Do nothing if a is empty. */

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

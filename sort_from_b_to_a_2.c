#include "push_swap.h"

void	ft_apply_ra_rb_a(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b)
{
	int	count_rr;
	int	count_ra_rb;
	int	i;

	count_rr = ft_min(ind_a, ind_b);
	count_ra_rb = ft_abs(ind_a - ind_b);
	i = 0;
	while (i++ < count_rr)
		ft_rr(stk_a, stk_b, 0);
	i = 0;
	while (i++ < count_ra_rb)
	{
		if (ind_a > ind_b)
			ft_ra(stk_a, 0);
		else
			ft_rb(stk_b, 0);
	}
	ft_pa(stk_a, stk_b, 0);
}

// void	ft_apply_rra_rrb_a(t_stack **s_a, t_stack **s_b, int ind_a, int ind_b)
// {
// 	int	c_rrr;
// 	int	c_rra_rrb;

// 	c_rrr = 0;
// 	if (ind_a == 0)
// 	{
// 		c_rra_rrb = ft_stk_size(*s_b) - ind_b;
// 		while (c_rra_rrb--)
// 			ft_rrb(s_b, 0);
// 	}
// 	else if (ind_b == 0)
// 	{
// 		c_rra_rrb = ft_stk_size(*s_a) - ind_a;
// 		while (c_rra_rrb--)
// 			ft_rra(s_a, 0);
// 	}
// 	else
// 	{
// 		c_rrr = ft_min((ft_stk_size(*s_a) - ind_a), (ft_stk_size(*s_b) - ind_b));
// 		c_rra_rrb = ft_abs((ft_stk_size(*s_a) - ind_a) - (ft_stk_size(*s_b) - ind_b));
// 		while (c_rrr--)
// 			ft_rrr(s_a, s_b, 0);
// 		while (c_rra_rrb-- && ((ft_stk_size(*s_a) - ind_a) > (ft_stk_size(*s_b) - ind_b)))
// 			ft_rra(s_a, 0);
// 		while (c_rra_rrb-- && ((ft_stk_size(*s_a) - ind_a) < (ft_stk_size(*s_b) - ind_b)))
// 			ft_rrb (s_b, 0);
// 	}
// 	ft_pa(s_a, s_b, 0);
// }

void	ft_apply_rra_rrb_a(t_stack **s_a, t_stack **s_b, int ind_a, int ind_b)
{
	int c_rrr;

	c_rrr = 0;
	if (ind_a != 0 && ind_b != 0)
		c_rrr = ft_min((ft_stk_size(*s_a) - ind_a), (ft_stk_size(*s_b) - ind_b));
	ft_choose_rra_rrb(s_a, s_b, ind_a, ind_b);
	while (c_rrr--)
		ft_rrr(s_a, s_b, 0);
	ft_pa(s_a, s_b, 0);
}

void	ft_apply_ra_rrb_a(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b)
{
	int	count_ra;
	int	count_rrb;
	int	i;

	count_ra = ind_a;
	if (ind_b == 0)
		count_rrb = 0;
	else
		count_rrb = ft_stk_size(*stk_b) - ind_b;
	i = 0;
	while (i < count_ra)
	{
		ft_ra(stk_a, 0);
		i ++;
	}
	i = 0;
	while (i < count_rrb)
	{
		ft_rrb(stk_b, 0);
		i ++;
	}
	ft_pa(stk_a, stk_b, 0);
}

void	ft_apply_rb_rra_a(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b)
{
	int	count_rb;
	int	count_rra;
	int	i;

	count_rb = ind_b;
	if (ind_a == 0)
		count_rra = 0;
	else
		count_rra = ft_stk_size(*stk_a) - ind_a;
	i = 0;
	while (i < count_rb)
	{
		ft_rb(stk_b, 0);
		i++;
	}
	i = 0;
	while (i < count_rra)
	{
		ft_rra(stk_a, 0);
		i ++;
	}
	ft_pa(stk_a, stk_b, 0);
}

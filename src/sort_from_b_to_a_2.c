/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_b_to_a_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:12:47 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 13:12:47 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_apply_ra_rb_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b)
{
	int	count_rr;
	int	count_ra_rb;
	int	i;

	count_rr = ft_min(ix_a, ix_b);
	count_ra_rb = ft_abs(ix_a - ix_b);
	i = 0;
	while (i++ < count_rr)
		ft_rr(stk_a, stk_b, 0);
	i = 0;
	while (i++ < count_ra_rb)
	{
		if (ix_a > ix_b)
			ft_ra(stk_a, 0);
		else
			ft_rb(stk_b, 0);
	}
	ft_pa(stk_a, stk_b, 0);
}

void	ft_apply_rra_rrb_a(t_stack **s_a, t_stack **s_b, int ix_a, int ix_b)
{
	int	c_rrr;

	c_rrr = 0;
	if (ix_a != 0 && ix_b != 0)
		c_rrr = ft_min((ft_stk_size(*s_a) - ix_a), (ft_stk_size(*s_b) - ix_b));
	ft_choose_rra_rrb(s_a, s_b, ix_a, ix_b);
	while (c_rrr--)
		ft_rrr(s_a, s_b, 0);
	ft_pa(s_a, s_b, 0);
}

void	ft_apply_ra_rrb_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b)
{
	int	count_ra;
	int	count_rrb;
	int	i;

	count_ra = ix_a;
	if (ix_b == 0)
		count_rrb = 0;
	else
		count_rrb = ft_stk_size(*stk_b) - ix_b;
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

void	ft_apply_rb_rra_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b)
{
	int	count_rb;
	int	count_rra;
	int	i;

	count_rb = ix_b;
	if (ix_a == 0)
		count_rra = 0;
	else
		count_rra = ft_stk_size(*stk_a) - ix_a;
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

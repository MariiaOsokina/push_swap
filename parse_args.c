/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:49:14 by mosokina          #+#    #+#             */
/*   Updated: 2024/07/19 13:49:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_parse(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;

	i = 1;

	if (argc == 2)
		ft_parse_quoted(argv, stack_a, stack_b);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i], stack_a, stack_b);
			ft_add_back(stack_a, ft_stack_new(j));
			i++;
		}
	}
	return ;
}

t_stack	*ft_parse_quoted(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**tmp_arr;
	int		i;
	int		j;

	i = 0;
	tmp_arr = ft_split(argv[1], 32);
	while (tmp_arr[i])
	{
		j = ft_atoi2(tmp_arr[i], stack_a, stack_b);
		ft_add_back(stack_a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp_arr);
	free(tmp_arr);
}

int	ft_atoi2(char *str, t_stack **stack_a, t_stack **stack_b)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(stack_a, stack_b);
		nbr = (nbr * 10) + (*str - '0');
		str ++;
	}
	if ((nbr * sign) > 2147483647 || (nbr * sign) < -2147483648)
		ft_error(stack_a, stack_b);
	return (nbr * sign);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	else if (!*stack)
		*stack = stack_new;
	else
		(ft_laststack(*stack))->next = stack_new;
}
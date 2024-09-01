/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:00:59 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 13:00:59 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			else
				tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
/*use this function in case of error:
- free stack 
- print "error"
- exit from the program*/

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_clean_stack(stack_a);
	ft_clean_stack(stack_b);
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

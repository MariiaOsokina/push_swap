/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:20 by mosokina          #+#    #+#             */
/*   Updated: 2024/08/26 15:07:52 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "libft/libft.h"

/*for exit(), free(), malloc()*/
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

/*parse args functions*/
void	ft_parse(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);
int		ft_atoi2(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
int		ft_check_dup(t_stack *a);
void	ft_error(t_stack **stack_a, t_stack **stack_b);

void	ft_parse_quoted(char **argv, t_stack **stack_a, t_stack **stack_b);
void	ft_freestr(char **lst);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*stack utilities functions*/
int		ft_stk_size(t_stack *stack);
int		ft_max_stack(t_stack *stack);
int		ft_min_stack(t_stack *stack);
int		ft_find_index(t_stack *stack, int nbr);
int		ft_is_sorted(t_stack	*stack);
t_stack	*ft_stack_new(int nbr);
t_stack	*ft_laststack(t_stack *stack);
t_stack	*ft_prevstack(t_stack *stack);
void	ft_clean_stack(t_stack	**stack);

/*operations functions*/
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

/*sorting algorithm*/
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b);

/*sort from stack a to stack b*/
void	ft_from_a_to_b(t_stack **stack_a, t_stack **stack_b);
int		ft_best_total_result(t_stack *stack_a, t_stack *stack_b, int *best_nbr);
int		ft_find_top_b(t_stack *stack_a, int nbr_b);
int		ft_min(int i, int j);
int		ft_abs(int i);

/*apply best operation (from a to b)*/
void	ft_apply_best_operation(t_stack **stk_a, t_stack **stk_b);
void	ft_apply_ra_rb(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b);
void	ft_apply_rra_rrb(t_stack **s_a, t_stack **s_b, int ix_a, int ix_b);
void	ft_choose_rra_rrb(t_stack **s_a, t_stack **s_b, int ind_a, int ind_b);
void	ft_apply_ra_rrb(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b);
void	ft_apply_rb_rra(t_stack **stk_a, t_stack **stk_b, int ind_a, int ind_b);

/* best nbr result (find best amount of opetations for nbr in stack a)*/
int		ft_best_nbr_result(t_stack *stk_a, t_stack *stk_b, int nb_a, int nb_b);
int		ft_count_ra_rb(int ind_a, int ind_b);
int		ft_count_rra_rrb(t_stack *stk_a, t_stack *sck_b, int ind_a, int ind_b);
int		ft_count_ra_rrb(t_stack *stk_b, int ind_a, int ind_b);
int		ft_count_rb_rra(t_stack *stk_a, int ind_a, int ind_b);

void	ft_sort_three(t_stack **stack_a);

/*sort from stack b to stack a*/
void	ft_from_b_to_a(t_stack **stk_a, t_stack **stk_b);
int		ft_find_top_a(t_stack *stack_a, int nbr_b);

void	ft_apply_ra_rb_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b);
void	ft_apply_rra_rrb_a(t_stack **s_a, t_stack **s_b, int ix_a, int ix_b);
void	ft_apply_ra_rrb_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b);
void	ft_apply_rb_rra_a(t_stack **stk_a, t_stack **stk_b, int ix_a, int ix_b);
void	ft_min_a_to_top(t_stack **stack_a);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:04:59 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/21 16:12:08 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// manage stacks
t_list	*ft_creat_stack(int content);
void	ft_add_back(t_list **stack, t_list *new);
void	ft_clear_stack(t_list **stack);
int		ft_stack_size(t_list *stack);
int		ft_get_premin(t_list *stack);
int		ft_get_min(t_list *stack);
void	ft_pass_to_positive(t_list **stack);
int		ft_get_next_min(t_list **stack, long prev_min);
void	ft_find_and_change(t_list *stack, t_list *new_stack, int cf, int nc);

// basic moves
t_list	*ft_del_first(t_list **stack);
t_list	*ft_del_last(t_list **stack);
void	ft_add_first(t_list **stack, t_list *node);
void	ft_add_last(t_list **stack, t_list *node);
void	ft_swap(t_list **stack);

// operations
void	sa(t_list **a);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);
void	sb(t_list **b);
void	pb(t_list **a, t_list **b);
void	rb(t_list **b);
void	rrb(t_list **b);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

// check values
int		ft_mini_atoi(char *content, long *result);
int		ft_check_doubles(t_list *stack, int number);
int		ft_check_if_sorted(t_list *a);
char	**ft_split(char *s, char c);

// sort stacks
void	ft_sort(t_list **a, t_list **b);
void	ft_sort_3(t_list **a);
void	ft_sort_5(t_list **a, t_list **b);
void	ft_sort_radix(t_list **a, t_list **b, int max_len);

#endif
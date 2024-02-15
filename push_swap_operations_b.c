/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:51:27 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/10 14:09:24 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	ft_add_first(b, ft_del_first(a));
	write(1, "pb\n", 3);
}

void	rb(t_list **b)
{
	ft_add_last(b, ft_del_first(b));
	write(1, "rb\n", 3);
}

void	rrb(t_list **b)
{
	ft_add_first(b, ft_del_last(b));
	write(1, "rrb\n", 4);
}

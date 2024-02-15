/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:47:07 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/10 14:08:52 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	ft_add_first(a, ft_del_first(b));
	write(1, "pa\n", 3);
}

void	ra(t_list **a)
{
	ft_add_last(a, ft_del_first(a));
	write(1, "ra\n", 3);
}

void	rra(t_list **a)
{
	ft_add_first(a, ft_del_last(a));
	write(1, "rra\n", 4);
}

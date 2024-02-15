/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_both.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:54:03 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/10 14:08:23 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ft_add_last(a, ft_del_first(a));
	ft_add_last(b, ft_del_first(b));
	write(1, "rr\n", 3);
}

void	rrr(t_list **a, t_list **b)
{
	ft_add_first(a, ft_del_last(a));
	ft_add_first(b, ft_del_last(b));
	write(1, "rrr\n", 4);
}

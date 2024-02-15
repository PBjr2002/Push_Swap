/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:23:41 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/12 14:50:20 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_del_first(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	return (tmp);
}

t_list	*ft_del_last(t_list **stack)
{
	t_list	*tmp;
	t_list	*before_last;
	t_list	*last;

	tmp = (*stack);
	while ((*stack)->next)
	{
		before_last = (*stack);
		(*stack) = (*stack)->next;
	}
	last = (*stack);
	before_last->next = NULL;
	(*stack) = tmp;
	return (last);
}

void	ft_add_first(t_list **stack, t_list *node)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = node;
	(*stack)->next = tmp;
}

void	ft_add_last(t_list **stack, t_list *node)
{
	t_list	*tmp;

	tmp = (*stack);
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->next = node;
	node->next = NULL;
	(*stack) = tmp;
}

void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

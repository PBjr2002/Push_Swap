/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:03:28 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/21 16:12:35 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_list *stack)
{
	int		n;
	t_list	*tmp;

	n = 0;
	if (!stack)
		return (0);
	tmp = stack;
	while (stack)
	{
		stack = stack->next;
		n++;
	}
	stack = tmp;
	return (n);
}

int	ft_get_premin(t_list *stack)
{
	t_list	*tmp;
	int		min;
	int		premin;

	if (!stack)
		return (0);
	min = ft_get_min(stack);
	premin = 2147483647;
	tmp = stack;
	while (stack)
	{
		if (stack->content > min && stack->content < premin)
			premin = stack->content;
		stack = stack->next;
	}
	stack = tmp;
	return (premin);
}

int	ft_get_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	if (!stack)
		return (0);
	min = 2147483647;
	tmp = stack;
	while (stack)
	{
		if (stack->content <= min)
			min = stack->content;
		stack = stack->next;
	}
	stack = tmp;
	return (min);
}

void	ft_pass_to_positive(t_list **stack)
{
	t_list	*new;
	long	min;
	int		len;
	int		i;

	new = NULL;
	len = ft_stack_size(*stack);
	i = 0;
	while (i < len)
	{
		ft_add_back(&new, ft_creat_stack(0));
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (i == 0)
			min = ft_get_min((*stack));
		else
			min = ft_get_next_min(stack, min);
		ft_find_and_change((*stack), new, min, i);
		i++;
	}
	ft_clear_stack(stack);
	(*stack) = new;
}

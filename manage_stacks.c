/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:09:03 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/21 16:11:57 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_creat_stack(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!(*stack))
	{
		(*stack) = new;
		return ;
	}
	tmp = (*stack);
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->next = new;
	(*stack) = tmp;
}

void	ft_clear_stack(t_list **stack)
{
	t_list	*next_node;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		next_node = (*stack)->next;
		free(*stack);
		(*stack) = next_node;
	}
	(*stack) = NULL;
}

void	ft_find_and_change(t_list *stack, t_list *new_stack, int cf, int nc)
{
	t_list	*tmp;
	int		i;
	int		n;

	i = 0;
	tmp = stack;
	while (stack)
	{
		if (stack->content == cf)
			break ;
		stack = stack->next;
		i++;
	}
	stack = tmp;
	n = 0;
	tmp = new_stack;
	while (new_stack)
	{
		if (n == i)
			new_stack->content = nc;
		new_stack = new_stack->next;
		n++;
	}
	new_stack = tmp;
}

int	ft_get_next_min(t_list **stack, long prev_min)
{
	t_list	*tmp;
	int		new_min;

	tmp = (*stack);
	new_min = 2147483647;
	while ((*stack))
	{
		if ((*stack)->content > prev_min && (*stack)->content <= new_min)
			new_min = (*stack)->content;
		(*stack) = (*stack)->next;
	}
	(*stack) = tmp;
	return (new_min);
}

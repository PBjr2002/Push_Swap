/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:17:09 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/02 15:59:30 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **a, t_list **b)
{
	int	size;
	int	max_len;

	size = ft_stack_size(*a);
	max_len = 0;
	if (ft_check_if_sorted(*a) == 0)
		return ;
	if (size == 2)
	{
		sa(a);
		return ;
	}
	if (ft_stack_size(*a) <= 5)
		ft_sort_5(a, b);
	else
	{
		while (size != 0)
		{
			size = size / 2;
			max_len++;
		}
		ft_pass_to_positive(a);
		ft_sort_radix(a, b, max_len);
	}
}

void	ft_sort_3(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ra(a);
	else if ((*a)->next->content > (*a)->next->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	ft_sort_5(t_list **a, t_list **b)
{
	int	min;
	int	premin;

	min = ft_get_min(*a);
	premin = ft_get_premin(*a);
	if (ft_stack_size(*a) == 4)
	{
		while ((*a)->content != min)
			ra(a);
		pb(a, b);
	}
	while (ft_stack_size(*a) > 3)
	{
		while ((*a)->content != min && (*a)->content != premin)
			ra(a);
		pb(a, b);
	}
	if (ft_stack_size(*b) == 2)
	{
		if ((*b)->content < (*b)->next->content)
			sb(b);
	}
	ft_sort_3(a);
	while (ft_stack_size(*b) > 0)
		pa(a, b);
}

void	ft_sort_radix(t_list **a, t_list **b, int max_len)
{
	int	i;
	int	len;
	int	shift;

	shift = 0;
	while (shift <= max_len && ft_check_if_sorted(*a) == -1)
	{
		i = 0;
		len = ft_stack_size(*a);
		while (i < len && ft_check_if_sorted(*a) == -1)
		{
			if (!((*a)->content >> shift & 1))
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (ft_stack_size(*b) > 0)
			pa(a, b);
		shift++;
	}
}

int	ft_check_if_sorted(t_list *a)
{
	t_list	*tmp;
	int		previous;

	if (!a)
		return (-1);
	previous = -2147483648;
	tmp = a;
	while (a)
	{
		if (previous > a->content)
		{
			a = tmp;
			return (-1);
		}
		previous = a->content;
		a = a->next;
	}
	a = tmp;
	return (0);
}

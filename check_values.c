/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:55:07 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/02 14:57:59 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_values(char *content)
{
	int		n;

	n = 0;
	if ((content[n] == '-' || content[n] == '+')
		&& (content[n + 1] >= '0' && content[n + 1] <= '9'))
		n++;
	while (content[n] >= '0' && content[n] <= '9')
		n++;
	if (content[n] != '\0')
		return (-1);
	return (0);
}

static int	ft_is_int(long *content, int signal)
{
	if ((*content) * signal == -2147483648)
		return (0);
	else if ((*content) > 2147483647 || (*content) < -2147483648)
		return (-1);
	return (0);
}

int	ft_mini_atoi(char *content, long *result)
{
	int		n;
	int		signal;

	n = 0;
	signal = 1;
	if (ft_check_values(content) == -1)
		return (-1);
	if (content[n] == '-' || content[n] == '+')
	{
		if (content[n] == '-')
			signal = -1;
		n++;
	}
	while (content[n])
	{
		(*result) = ((*result) * 10) + content[n] - 48;
		if (ft_is_int(result, signal) == -1)
			return (-1);
		n++;
	}
	if (ft_is_int(result, signal) == -1)
		return (-1);
	(*result) = (*result) * signal;
	return (0);
}

int	ft_check_doubles(t_list *stack, int number)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content == number)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

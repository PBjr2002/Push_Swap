/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:58:55 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/02 15:51:51 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_new_av(char **new_av, int mode)
{
	int	n;

	if (mode == -1)
		write(2, "Error\n", 6);
	n = 0;
	while (new_av[n])
	{
		free(new_av[n]);
		n++;
	}
	free(new_av);
}

static int	ft_av_size(char **av)
{
	int		n;
	int		i;
	int		count;

	n = 1;
	count = 0;
	while (av[n])
	{
		i = 0;
		while (av[n][i])
		{
			count++;
			i++;
		}
		if (av[n][i] == '\0')
			count++;
		n++;
	}
	return (count);
}

static char	**ft_split_av(char **av)
{
	char	**new_av;
	char	*str;
	int		n;
	int		i;
	int		index;

	str = (char *)malloc(sizeof(char) * (ft_av_size(av) + 1));
	if (!str)
		return (NULL);
	n = 1;
	index = 0;
	while (av[n])
	{
		i = 0;
		while (av[n][i])
			str[index++] = av[n][i++];
		if (av[n][i] == '\0')
			str[index++] = ' ';
		n++;
	}
	str[index] = '\0';
	new_av = ft_split(str, ' ');
	free(str);
	return (new_av);
}

static t_list	*ft_checker(char **av)
{
	t_list	*new;
	long	content;
	int		n;

	n = 0;
	new = NULL;
	while (av[n])
	{
		content = 0;
		if (ft_mini_atoi(av[n], &content) == -1
			|| ft_check_doubles(new, content) == -1)
		{
			free_new_av(av, -1);
			ft_clear_stack(&new);
			return (NULL);
		}
		ft_add_back(&new, ft_creat_stack(content));
		if (!new)
			return (NULL);
		n++;
	}
	free_new_av(av, 0);
	return (new);
}

int	main(int ac, char **av)
{
	char	**new_av;
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	new_av = ft_split_av(av);
	if (!new_av)
	{
		free_new_av(new_av, -1);
		return (0);
	}
	b = NULL;
	a = ft_checker(new_av);
	if (!a)
		return (0);
	ft_sort(&a, &b);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}

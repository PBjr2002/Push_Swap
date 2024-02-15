/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:15:47 by pauberna          #+#    #+#             */
/*   Updated: 2023/12/19 15:48:44 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

static char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		n;

	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	n = 0;
	while (s[n] != '\0' && (n < len))
	{
		str[n] = s[n + start];
		n++;
	}
	str[n] = '\0';
	return (str);
}

static int	ft_countstr(char *str, char sep)
{
	int	count;
	int	n;

	count = 0;
	n = 0;
	while (str[n])
	{
		while (str[n] == sep)
			n++;
		if (str[n])
			count++;
		while (str[n] && str[n] != sep)
			n++;
	}
	return (count);
}

static int	ft_almem(char **tab, char *s, char sep)
{
	char	**tab1;
	char	*tmp;

	tmp = s;
	tab1 = tab;
	while (*tmp)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (*tmp == sep || tmp > s)
		{
			*tab1 = ft_substr(s, 0, tmp - s);
			if (*tab1 == NULL)
				return (0);
			s = tmp;
			tab1++;
		}
	}
	*tab1 = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		size;
	int		n;

	size = ft_countstr(s, c);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	n = 0;
	while (n <= size)
	{
		array[n] = NULL;
		n++;
	}
	if (ft_almem(array, s, c) == 0)
	{
		while (n > 0)
		{
			free(array[n - 1]);
			n--;
		}
		free(array);
		return (NULL);
	}
	return (array);
}

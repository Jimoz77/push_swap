/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:36:00 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:42:16 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

bool	check_carac(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

bool	check_doublon(char **argv)
{
	int	i;
	int	j;
	int	val_i;
	int	val_j;

	i = 1;
	while (argv[i])
	{
		val_i = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			val_j = ft_atol(argv[j]);
			if (val_i == val_j)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	is_nega;
	long	res;

	i = 0;
	res = 0;
	is_nega = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_nega = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_nega);
}

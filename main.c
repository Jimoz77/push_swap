/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:46:53 by jimpa             #+#    #+#             */
/*   Updated: 2025/02/02 17:59:26 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**split;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		split = ft_split(argv[1], ' ');
	init_stack_a(&list_a, split);
	if (!stack_sorted(list_a))
	{
		if (ft_lstsize(list_a) == 2)
			sa(&list_a, 1);
		else if (ft_lstsize(list_a) == 3)
			sort_three(&list_a);
		else
			sort_stacks(&list_a, &list_b);
	}
	free_list(list_a);
	free_list(list_b);
	free_split(split);
	return (0);
}

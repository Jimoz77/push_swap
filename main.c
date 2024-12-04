/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:46:53 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/04 18:53:59 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&list_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pa(&list_a, &list_b);
	rrr(&list_b, &list_a);
	t_list *temp_a = list_a;
	t_list *temp_b = list_b;
	while (temp_a != NULL || temp_b != NULL)
	{
		if (temp_a != NULL)
		{
			printf("list_a: %d ", temp_a->content);
			temp_a = temp_a->next;
		}
		if (temp_b != NULL)
		{
			printf("list_b: %d", temp_b->content);
			temp_b = temp_b->next;
		}
		printf("\n");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:46:53 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/10 13:57:07 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1],' ');
	init_stack_a(&list_a, argv);
	if (!stack_sorted(list_a)) 				
	{
		if (ft_lstsize(list_a) == 2)
			sa(&list_a);
		else if (ft_lstsize(list_a) == 3)
			sort_three(&list_a);
		else
			sort_stacks(&list_a, &list_b);		//represente tout le mecanisme de turk algo
	}
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
	printf("sorted = %d\n", stack_sorted(list_a));
	return (0); 
}

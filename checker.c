/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:00:53 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/16 15:46:54 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_folder/gnl/get_next_line.h"
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	do_instru(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
}


int	main(int argc, char **argv)
{
	char	*line;
	t_list	*list_a;
	t_list	*list_b;

	argc--;
	line = "a";
	list_a = NULL;
	list_b = NULL;
	argv = ft_split(argv[1], ' ');
	init_stack_a(&list_a, argv);
	free(argv);
	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		do_instru(line, &list_a, &list_b);
		free(line);
	}
	if (stack_sorted(list_a) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
return (0);
}
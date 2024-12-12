/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:33:21 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:41:43 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_list *lst)
{
	int	i;
	int	median;

	i = 0;
	median = ft_lstsize(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}

void	init_nodes_a(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

void	min_on_top(t_list **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_three(t_list **lst)
{
	t_list	*big_node;

	big_node = find_max(*lst);
	if (big_node == *lst)
		ra(lst);
	else if ((*lst)->next == big_node)
		rra(lst);
	if ((*lst)->content > (*lst)->next->content)
		sa(lst);
}

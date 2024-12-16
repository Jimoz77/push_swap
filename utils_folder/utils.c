/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:56:54 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/16 12:18:38 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_max(t_list *lst)
{
	t_list	*max_node;
	int		max_val;

	max_val = INT_MIN;
	max_node = NULL;
	while (lst)
	{
		if (lst->content > max_val)
		{
			max_val = lst->content;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_list	*find_min(t_list *lst)
{
	t_list	*min_node;
	int		min_val;

	min_val = INT_MAX;
	min_node = NULL;
	while (lst)
	{
		if (lst->content < min_val)
		{
			min_val = lst->content;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

void	prep_for_push(t_list **lst, t_list *top_node, char lst_name)
{
	while (*lst != top_node)
	{
		if (lst_name == 'a')
		{
			if (top_node->above_median)
				ra(lst, 1);
			else
				rra(lst, 1);
		}
		else if (lst_name == 'b')
		{
			if (top_node->above_median)
				rb(lst, 1);
			else
				rrb(lst, 1);
		}
	}
}

t_list	*get_cheapest(t_list *a)
{
	while (a)
	{
		if (a->cheapest == true)
		{
			return (a);
		}
		a = a->next;
	}
	return (NULL);
}

void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, 1);
}

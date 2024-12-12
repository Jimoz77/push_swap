/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:32:03 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:41:17 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	set_cheapest(t_list *lst)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!lst)
		return ;
	cheapest_value = LONG_MAX;
	while (lst)
	{
		if (lst->push_cost < cheapest_value)
		{
			cheapest_value = lst->push_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest = true;
}

void	cost_analysis_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*temp_b;
	t_list	*t_node;
	long	best_t;

	while (a)
	{
		best_t = LONG_MIN;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->content < a->content && temp_b->content > best_t)
			{
				best_t = temp_b->content;
				t_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_t == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = t_node;
		a = a->next;
	}
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*temp_a;
	t_list	*t_node;
	long	best_t;

	while (b)
	{
		best_t = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->content > b->content && temp_a->content < best_t)
			{
				best_t = temp_a->content;
				t_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_t == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = t_node;
		b = b->next;
	}
}

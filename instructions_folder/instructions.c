/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:03:29 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:43:06 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

// FONCTION DE MOUVEMENT DE LISTE //

//SA swap a // SB swap b
void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

//PB push b //PA push a
void	push(t_list **lst_b, t_list **lst_a)
{
	t_list	*first_a;

	if (*lst_a == NULL)
		return ;
	first_a = *lst_a;
	*lst_a = (*lst_a)->next;
	first_a->next = *lst_b;
	*lst_b = first_a;
}

//RA rotate a //RB rotate b
void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = first;
	*lst = first->next;
	first->next = NULL;
}

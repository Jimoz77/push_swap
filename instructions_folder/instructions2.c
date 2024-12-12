/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:40:38 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:26:30 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//RRA reverse rotate a //RRB reverse rotate b
void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	second_last = NULL;
	last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}
// FONCTION INTERMEDIARE POUR WRITE A CHAQUE APPEL //

void	sa(t_list **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	sb(t_list **lst)
{
	swap(lst);
	ft_printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_printf("ss\n");
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_printf("pa\n");
}

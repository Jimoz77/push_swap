/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:05 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:27:58 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	ft_printf("pb\n");
}

void	ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_list **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_printf("rr\n");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}

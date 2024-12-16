/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:05 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/16 12:10:17 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **lst_a, t_list **lst_b, int print)
{
	push(lst_b, lst_a);
	if (print == 1)
		ft_printf("pb\n");
}

void	ra(t_list **lst, int print)
{
	rotate(lst);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_list **lst, int print)
{
	rotate(lst);
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b, int print)
{
	rotate(lst_a);
	rotate(lst_b);
	if (print == 1)
		ft_printf("rr\n");
}

void	rra(t_list **lst, int print)
{
	reverse_rotate(lst);
	if (print == 1)
		ft_printf("rra\n");
}

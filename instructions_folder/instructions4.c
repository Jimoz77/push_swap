/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:44:55 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/16 12:11:18 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_list **lst, int print)
{
	reverse_rotate(lst);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b, int print)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	if (print == 1)
		ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:55 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/07 18:03:56 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int car)
{
	if (car >= '0' && car <= '9')
		return (1);
	else
		return (0);
}
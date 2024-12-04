/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:49:45 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 12:01:28 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *adress, size_t n)
{
	unsigned char	*chaine;

	chaine = (unsigned char *)adress;
	while (n--)
	{
		*chaine++ = '\0';
	}
}

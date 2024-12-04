/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:25:12 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 12:52:15 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *address, int c, size_t n)
{
	unsigned char	*chaine;

	chaine = (unsigned char *)address;
	while (n--)
	{
		*chaine++ = (unsigned char)c;
	}
	return (address);
}

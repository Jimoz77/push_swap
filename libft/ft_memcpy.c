/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:12:55 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 17:49:50 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*result;
	const unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	result = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (n--)
	{
		*result++ = *source++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:19:52 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/07 18:06:42 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*tmp;
	char		*dest;

	tmp = (char *)src;
	dest = (char *)dst;
	if (tmp < dest && dest < tmp + n)
	{
		while (n--)
			dest[n] = tmp[n];
	}
	else
	{
		ft_memcpy(dest, tmp, n);
	}
	return (dst);
}

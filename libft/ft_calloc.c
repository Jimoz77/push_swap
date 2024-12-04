/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:01:23 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 12:51:29 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*s;
	void			*slot;
	size_t			totalen;

	if (num != 0 && size > SIZE_MAX / num)
	{
		return (NULL);
	}
	slot = malloc(size * num);
	if (!slot)
	{
		return (NULL);
	}
	s = (unsigned char *)slot;
	totalen = num * size;
	while (totalen)
	{
		*s++ = '\0';
		totalen--;
	}
	return (slot);
}

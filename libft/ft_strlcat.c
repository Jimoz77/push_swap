/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:30:17 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 12:51:04 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;
	size_t	j;

	srclen = 0;
	destlen = 0;
	j = 0;
	while (src[srclen])
		srclen++;
	while (dest[destlen])
		destlen++;
	i = destlen;
	if (size <= destlen)
		return (size + srclen);
	while (i < size - 1 && src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}

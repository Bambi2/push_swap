/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:08:01 by mmalphit          #+#    #+#             */
/*   Updated: 2021/10/20 19:08:02 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_length;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	dst_length = ft_strlen(dst);
	if (dst_length >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - dst_length - 1 && src[i])
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (ft_strlen(src) + dst_length);
}

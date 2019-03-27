/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:35:16 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:28:45 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	int		j;
	size_t	srclen;

	i = ft_strlen(dst);
	dstlen = ft_strlen(dst);
	j = 0;
	srclen = ft_strlen(src);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	if (dstsize > dstlen + 1)
	{
		while (i < dstsize - 1)
		{
			*(dst + i++) = *(src + j++);
		}
		*(dst + i) = '\0';
	}
	return (dstlen + srclen);
}

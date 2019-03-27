/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:52:03 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:29:12 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d_temp;
	char *s_temp;

	d_temp = (char *)dst;
	s_temp = (char *)src;
	if (s_temp < d_temp)
	{
		while ((int)--len >= 0)
		{
			d_temp[len] = s_temp[len];
		}
	}
	else
	{
		while ((int)len--)
		{
			*d_temp = *s_temp;
			d_temp++;
			s_temp++;
		}
	}
	return (dst);
}

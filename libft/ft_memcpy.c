/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:24:15 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 13:17:49 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *s_temp;
	char *d_temp;

	s_temp = (char *)src;
	d_temp = (char *)dst;
	while (n--)
	{
		*d_temp = *s_temp;
		d_temp++;
		s_temp++;
	}
	return (dst);
}

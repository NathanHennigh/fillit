/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:23:48 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 13:51:50 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*str_d;
	char	*str_s;

	str_d = dst;
	str_s = (char *)src;
	while (len--)
	{
		if (*str_s)
		{
			*str_d = *str_s;
			str_s++;
		}
		else
			*str_d = '\0';
		str_d++;
	}
	return (dst);
}

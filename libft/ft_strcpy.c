/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:06:43 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/13 21:23:08 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *str_d;
	char *str_s;

	str_d = dst;
	str_s = (char *)src;
	while (*str_s)
	{
		*str_d = *str_s;
		str_d++;
		str_s++;
	}
	*str_d = '\0';
	return (dst);
}

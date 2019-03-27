/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:51:16 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/12 14:09:31 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *str1;
	char *str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	while (n--)
	{
		if ((unsigned char)*str1 != (unsigned char)*str2)
			return (((unsigned char)*str1) - ((unsigned char)*str2));
		str1++;
		str2++;
	}
	return (0);
}

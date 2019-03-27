/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:14:23 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 13:52:16 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = s1;
	str2 = (char *)s2;
	i = ft_strlen(str1);
	while (*str2 && n--)
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
	str1[i] = '\0';
	return (s1);
}

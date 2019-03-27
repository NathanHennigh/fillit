/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:38:51 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:27:38 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	int		len;

	str1 = s1;
	str2 = (char *)s2;
	len = ft_strlen(s1);
	while (*str2)
	{
		str1[len] = *str2;
		len++;
		str2++;
	}
	str1[len] = '\0';
	return (s1);
}

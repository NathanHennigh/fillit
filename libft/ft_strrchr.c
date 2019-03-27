/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:24:34 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 13:16:06 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (str[i] == (char)c)
			return (&str[i]);
	}
	return (NULL);
}

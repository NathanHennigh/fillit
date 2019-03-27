/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:06:24 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 20:33:26 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = -1;
	while (*(s1 + ++i))
	{
		*(str + i) = *(s1 + i);
	}
	*(str + i) = '\0';
	return (str);
}

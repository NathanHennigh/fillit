/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:40:57 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/15 18:15:32 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + ++i))
		*(str + i) = (*f)((unsigned int)i, *(s + i));
	*(str + i) = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:31:56 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:15:54 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	while (*(s + ++i))
		*(str + i) = (*f)(*(s + i));
	return (str);
}

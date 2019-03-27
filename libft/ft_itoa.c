/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:27:06 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/15 13:01:19 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	n_cpy;

	len = get_len(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
	{
		str[--len] = n_cpy % 10 + '0';
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}

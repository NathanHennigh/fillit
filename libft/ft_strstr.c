/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:57:41 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:29:39 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int k;
	int	good;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	good = 0;
	while (*(haystack + ++i) && !good)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			k = i;
			good = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					good = 0;
			if (good)
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}

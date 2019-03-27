/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:18:47 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 14:41:00 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		good;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	good = 0;
	while (*(haystack + ++i) && i < len)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			k = i;
			good = 1;
			while (*(needle + j) && *(haystack + k) && k < len && j < len)
				if (*(needle + j++) != *(haystack + k++))
					good = 0;
			if (good && !*(needle + j))
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}

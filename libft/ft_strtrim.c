/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:35:08 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 19:49:06 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && ft_iswspace(s[start]))
		start++;
	end = ft_strlen(&s[start]) - 1;
	while (s[start] && ft_iswspace(s[start + end]))
		end--;
	if (!(str = ft_strnew(end + 1)))
		return (NULL);
	ft_strncpy(str, (s + start), (end + 1));
	return (str);
}

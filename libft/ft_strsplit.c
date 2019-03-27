/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:32:30 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/15 20:23:30 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(const char *str, char delim)
{
	int			num;
	const char	*word;
	int			i;

	num = 0;
	word = str;
	i = 0;
	while (word[i])
	{
		if (word[i] != delim)
		{
			num++;
			while (word[i] && word[i] != delim)
				i++;
		}
		else
			i++;
	}
	return (num);
}

static int	word_len(const char *str, char delim)
{
	int			len;
	const char	*word;

	len = 0;
	word = str;
	while (*str && *str != delim)
	{
		len++;
		str++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		i;
	int		j;
	int		k;

	if (!s || !(list = malloc((num_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	k = -1;
	while (*(s + ++k) && i < num_words(s, c))
	{
		if (s[k] != c)
		{
			j = 0;
			if (!(list[i] = malloc((word_len(&s[k], c) + 1) * sizeof(char))))
				return (NULL);
			while (s[k] && s[k] != c)
				list[i][j++] = s[k++];
			list[i++][j] = '\0';
		}
	}
	list[i] = 0;
	return (list);
}

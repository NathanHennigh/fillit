/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:27:03 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/14 16:27:01 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\f'
			|| *(str + i) == '\r' || *(str + i) == '\v' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		number = (number * 10) + (*(str + i++) - '0');
	return (number * sign);
}

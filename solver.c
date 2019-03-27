/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:22 by nhennigh          #+#    #+#             */
/*   Updated: 2019/03/01 13:34:23 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libft/libft.h"
#include "./includes/fillit.h"
#include <stdio.h>

inline int	check_piece(const t_etris *tetris, uint16_t *map)
{
	return (!(*(uint64_t *)(map + tetris->y) & (tetris->value >> tetris->x)));
}

inline void	toggle_piece(const t_etris *tetris, uint16_t *map)
{
	*(uint64_t *)(map + tetris->y) ^= tetris->value >> tetris->x;
}

int			solve_map(t_etris *tetris, const int size, uint16_t *map)
{
	int pos;

	if (tetris->id == 0)
		return (1);
	pos = (tetris->last ? (tetris->last->x + tetris->last->y * size) : 0);
	tetris->y = pos / size;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = (tetris->y == pos / size ? pos % size : 0);
		while (tetris->x <= size - tetris->width)
		{
			if (check_piece(tetris, map))
			{
				toggle_piece(tetris, map);
				if (solve_map(tetris + 1, size, map))
					return (1);
				toggle_piece(tetris, map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

int			solve(t_etris *tetris, const int count, uint16_t *map)
{
	int		size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size == 17 ? 0 : size);
}

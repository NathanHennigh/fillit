/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:38 by nhennigh          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:04 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/libft.h"
#include "./includes/fillit.h"

void	min_max(const char *str, char *m)
{
	unsigned char i;

	i = 0;
	m[0] = 3;
	m[1] = 0;
	m[2] = 3;
	m[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i % 5 > m[1])
				m[1] = i % 5;
			if (i / 5 < m[2])
				m[2] = i / 5;
			if (i / 5 > m[3])
				m[3] = i / 5;
		}
		i++;
	}
}

t_etris	get_piece(const char *str, const char id)
{
	t_etris	tetris;
	char	m[4];
	int		x;
	int		y;

	min_max(str, m);
	tetris.width = m[1] - m[0] + 1;
	tetris.height = m[3] - m[2] + 1;
	tetris.id = id;
	tetris.value = 0;
	tetris.last = NULL;
	y = 0;
	while (y < tetris.height)
	{
		x = 0;
		while (x < tetris.width)
		{
			if (str[(m[0] + x) + (m[2] + y) * 5] == '#')
				tetris.value |= (1L << (16 * (y + 1) - 1 - x));
			x++;
		}
		y++;
	}
	return (tetris);
}

int		check_connection(const char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		check_counts(const char *str, const int count)
{
	int i;
	int blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!check_connection(str))
		return (5);
	return (0);
}

int		read_tetri(const int fd, t_etris *tetris)
{
	t_t			read_t;

	read_t.cur = 'A';
	read_t.i = 0;
	while ((read_t.count = read(fd, read_t.buf, 21)) >= 20)
	{
		if (check_counts(read_t.buf, read_t.count) != 0)
			return (0);
		tetris[read_t.i] = get_piece(read_t.buf, read_t.cur);
		read_t.j = read_t.i - 1;
		read_t.test = ft_strndup(read_t.buf, 21);
		ft_bzero(read_t.buf, 22);
		while (read_t.j >= 0)
		{
			if (tetris[read_t.j].value == tetris[read_t.i].value)
				tetris[read_t.i].last = tetris + read_t.j;
			read_t.j--;
		}
		read_t.cur++;
		read_t.i++;
	}
	if (check_die(read_t.test) != 0)
		return (0);
	return (read_t.cur - 'A');
}

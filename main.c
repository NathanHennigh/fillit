/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:35:06 by nhennigh          #+#    #+#             */
/*   Updated: 2019/03/01 13:35:07 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libft/libft.h"
#include "./includes/fillit.h"

char	*empty_map(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * (size));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

void	print(t_etris *t, int count, int size)
{
	char	*str;
	int		x;
	int		y;

	str = empty_map(size);
	while (count > 0)
	{
		y = 0;
		while (y < t->height)
		{
			x = 0;
			while (x < t->width)
			{
				if ((t->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(t->y + y) * (size + 1) + x + t->x] = t->id;
				x++;
			}
			y++;
		}
		t++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

int		check_die(const char *str)
{
	if (!(str))
		return (1);
	else if (str[19] == '\n' && str[20] == '\n')
		return (2);
	return (0);
}

int		die(char *str)
{
	ft_putendl(str);
	return (1);
}

int		main(int argc, char **argv)
{
	t_etris		tetris[MAX_TETRI + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	if (argc != 2)
		return (die("usage: ./fillit [input_file]"));
	ft_bzero(tetris, sizeof(t_etris) * (MAX_TETRI + 1));
	if ((count = read_tetri(open(argv[1], O_RDONLY), tetris)) == 0)
		return (die("error"));
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = solve(tetris, count, map)) == 0)
		return (die("error"));
	print(tetris, count, size);
	return (0);
}

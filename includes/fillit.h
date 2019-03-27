/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:28:35 by nhennigh          #+#    #+#             */
/*   Updated: 2019/03/01 13:34:12 by nhennigh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRI 26
# include <string.h>
# include <stdint.h>

typedef struct s_etris		t_etris;

struct				s_etris
{
	uint64_t			value;
	t_etris				*last;
	unsigned char		id;
	unsigned char		x;
	unsigned char		y;
	unsigned char		width;
	unsigned char		height;
};

typedef struct s_tetris		t_t;

struct				s_tetris
{
	t_t				*tetri;
	char			*test;
	char			cur;
	int				i;
	int				j;
	int				count;
	char			buf[22];
};

int					die(char *str);
int					check_die(const char *str);
int					read_tetri(const int fd, t_etris *tetris);
int					solve(t_etris *tetris, const int count, uint16_t *map);
int					check_piece(const t_etris *tetris, uint16_t *map);
void				toggle_piece(const t_etris *tetris, uint16_t *map);
#endif

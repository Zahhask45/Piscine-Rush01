/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:28:48 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:30 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "functions.h"

int	g_cl;
int	g_cc;
int	g_n;
int	g_placed;
int	g_cb;

int	fill_pt2(int puzz[4][4])
{
	g_placed = 0;
	if (g_cb)
		g_n = puzz[g_cl][g_cc];
	else
		g_n = 0;
	while (++g_n < 5)
	{
		if (can_place(puzz, g_cl, g_cc, g_n))
		{
			puzz[g_cl][g_cc] = g_n;
			g_placed = 1;
			break ;
		}
	}
	return (0);
}

int	fi_pt3(void)
{
	if (g_cc == 0 && g_cl == 0)
		return (0);
	if (g_cc == 0)
	{
		g_cc = 3;
		g_cl--;
	}
	else
		g_cc--;
	g_cb = 1;
	return (0);
}

void	rest(void)
{
	if (g_cc == 0)
	{
		g_cc = 3;
		g_cl--;
	}
	else
		g_cc--;
	g_cb = 1;
}

int	fill_puzz(int puzz[4][4], int board[4][4])
{
	while (++g_cl < 5)
	{
		g_cc = 0;
		g_cb = 0;
		while (g_cc < 4)
		{
			fill_pt2(puzz);
			if (!g_placed)
				fi_pt3();
			else if (g_cc == 3 && g_cl == 3)
			{
				if (is_solved(puzz, board))
					return (1);
				else
					rest();
			}
			else
			{
				g_cb = 0;
				g_cc++;
			}
		}
		g_cb = 0;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*info;
	int		board[4][4];
	int		puzz[4][4];

	g_cl = -1;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	info = argv[1];
	if (!ft_valid(info))
		return (1);
	fill_board(board, info);
	if (!board_val(board))
		return (1);
	if (fill_puzz(puzz, board))
		return (0);
	else
	{
		write(1, "Error:bb\n", 8);
		return (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:55:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:32 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "functions.h"

void	fill_board(int board[4][4], char *info)
{
	unsigned int	i;
	unsigned int	info_size;

	i = 0;
	info_size = ft_strlen(info);
	while (i < (info_size / 2) + 1)
	{
		board[i / 4][i % 4] = info[i * 2] - '0';
		i++;
	}
}

void	print_puzz(int puzz[4][4])
{
	int	st;
	int	nd;
	int	p;

	st = 0;
	while (st < 4)
	{
		nd = 0;
		while (nd < 4)
		{
			p = puzz[st][nd] + '0';
			write(1, &p, 1);
			if (nd < 3)
				write(1, " ", 1);
			nd++;
		}
		write(1, "\n", 1);
		st++;
	}
}

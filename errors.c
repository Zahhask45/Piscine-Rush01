/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:53:34 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:25 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

int	ft_pt2(unsigned int p_size, char *info)
{
	unsigned int	i;

	i = 0;
	while (i < p_size)
	{
		if (i % 2 == 0)
		{
			if (info[i] < '1' || info[i] > '4')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		else if (info[i] != ' ')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_valid(char *info)
{
	unsigned int	i;
	unsigned int	p_size;

	i = 0;
	p_size = ft_strlen(info);
	if (p_size != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_pt2(p_size, info))
		return (0);
	return (1);
}

int	board_val(int board[4][4])
{
	int	st;
	int	nd;

	st = 0;
	while (st < 4)
	{
		nd = 0;
		while (nd < 4)
		{
			if (board[st][nd] + board[st + 1][nd] < 3 ||
					board[st][nd] + board[st + 1][nd] > 5)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			nd++;
		}
		st += 2;
	}
	return (1);
}

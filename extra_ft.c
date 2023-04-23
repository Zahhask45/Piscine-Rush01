/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:27:16 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:27 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "functions.h"

int	is_solved(int puzz[4][4], int board[4][4])
{
	int	is_top_valid;
	int	is_bot_valid;
	int	is_left_valid;
	int	is_right_valid;

	is_top_valid = val_top_bot(puzz, board[0]);
	is_bot_valid = val_bot_top(puzz, board[1]);
	is_left_valid = val_left_right(puzz, board[2]);
	is_right_valid = val_right_left(puzz, board[3]);
	if (is_top_valid && is_bot_valid && is_left_valid && is_right_valid)
	{
		print_puzz(puzz);
		return (1);
	}
	return (0);
}

int	can_place(int puzz[4][4], int cl, int cc, int n)
{
	int	st;
	int	nd;

	st = -1;
	while (++st < cl)
		if (puzz[st][cc] == n)
			return (0);
	nd = -1;
	while (++nd < cc)
		if (puzz[cl][nd] == n)
			return (0);
	return (1);
}

void	reuse(int cb, int cc)
{
	cb = 0;
	cc++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:56:35 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:34 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_top_bot(int matriz[4][4], int colXup[4])
{
	int	coluna;
	int	linha;
	int	visao;
	int	cursor;

	coluna = 0;
	while (coluna < 4)
	{
		visao = colXup[coluna];
		cursor = 0;
		linha = 0;
		while (linha < 4)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			linha++;
		}
		coluna++;
		if (visao != 0)
			return (0);
	}
	return (1);
}

int	val_bot_top(int matriz[4][4], int colXdown[])
{
	int	coluna;
	int	linha;
	int	visao;
	int	cursor;

	coluna = 3;
	while (coluna >= 0)
	{
		visao = colXdown[coluna];
		cursor = 0;
		linha = 3;
		while (linha >= 0)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			linha--;
		}
		coluna--;
		if (visao != 0)
			return (0);
	}
	return (1);
}

int	val_left_right(int matriz[4][4], int rowXleft[4])
{
	int	coluna;
	int	linha;
	int	visao;
	int	cursor;

	linha = 0;
	while (linha < 4)
	{
		visao = rowXleft[linha];
		cursor = 0;
		coluna = 0;
		while (coluna < 4)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			coluna++;
		}
		linha++;
		if (visao != 0)
			return (0);
	}
	return (1);
}

int	val_right_left(int matriz[4][4], int rowXright[4])
{
	int	coluna;
	int	linha;
	int	visao;
	int	cursor;

	linha = 3;
	while (linha >= 0)
	{
		visao = rowXright[linha];
		cursor = 0;
		coluna = 3;
		while (coluna >= 0)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			coluna--;
		}
		linha--;
		if (visao != 0)
			return (0);
	}
	return (1);
}

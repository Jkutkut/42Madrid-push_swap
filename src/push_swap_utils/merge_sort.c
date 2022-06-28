/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:43:13 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/28 12:52:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

#define DATA 0
#define LEFT 1
#define RIGHT 2

#define I 0
#define L 1
#define R 2
#define L_LEN 3
#define R_LEN 4

void	merge(int *arr[], int l, int m, int r)
{
	int	index[5];

	index[L_LEN] = m - l + 1;
	index[R_LEN] = r - m;
	index[L] = -1;
	while (++index[L] < index[L_LEN])
		arr[LEFT][index[L]] = arr[DATA][l + index[L]];
	index[R] = -1;
	while (++index[R] < index[R_LEN])
		arr[RIGHT][index[R]] = arr[DATA][m + 1 + index[R]];
	index[I] = 0;
	index[L] = 0;
	index[R] = l;
	while (index[I] < index[L_LEN] && index[L] < index[R_LEN])
	{
		if (arr[LEFT][index[I]] <= arr[RIGHT][index[L]])
			arr[DATA][index[R]] = arr[LEFT][index[I]++];
		else
			arr[DATA][index[R]] = arr[RIGHT][index[L]++];
		index[R]++;
	}
	while (index[I] < index[L_LEN])
		arr[DATA][index[R]++] = arr[LEFT][index[I]++];
	while (index[L] < index[R_LEN])
		arr[DATA][index[R]++] = arr[RIGHT][index[L]++];
}

void	merge_sort_recursive(int *arr[], int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort_recursive(arr, l, m);
		merge_sort_recursive(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void	merge_sort(int *array, int size)
{
	int	*data[3];

	data[0] = array;
	data[1] = (int *) malloc(sizeof(int) * (size - size / 2));
	data[2] = (int *) malloc(sizeof(int) * (size / 2));
	// TODO MALLOC CAN FAIL
	merge_sort_recursive(data, 0, size - 1);
	free(data[1]);
	free(data[2]);
}

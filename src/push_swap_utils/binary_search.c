/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:41:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/17 11:12:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	binary_search(int arr[], int l, int r, int value)
{
	int	m;

	if (r >= l) {
		m = l + (r - l) / 2;
		if (arr[m] == value)
			return m;
		if (arr[m] > value)
			return binary_search(arr, l, m - 1, value);
		return binary_search(arr, m + 1, r, value);
	}
	return -1;
}
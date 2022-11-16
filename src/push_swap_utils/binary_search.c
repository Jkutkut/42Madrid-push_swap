/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:41:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/16 16:48:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Search the value on the sorted array arr in the interval [l, r].
 * Due to the nature of the algorithm, the complexity is O(log(n)).
 * 
 * @param arr Array to use.
 * @param l Minimum index to seach.
 * @param r Maximum index to seach.
 * @param value Value to search for.
 * @return int Position in the array or -1 if not found.
 */
int	binary_search(int arr[], int l, int r, int value)
{
	int	m;

	if (r >= l)
	{
		m = l + (r - l) / 2;
		if (arr[m] == value)
			return (m);
		if (arr[m] > value)
			return (binary_search(arr, l, m - 1, value));
		return (binary_search(arr, m + 1, r, value));
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/09 20:05:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_INT_LEN 11
#define MAX_INT "2147483647"
#define MAX_N_INT "-2147483648"

int	is_nbr2large(const char *nbr, int len)
{
	int		i;
	int		negative;
	char	*max;

	if (!nbr || len < MAX_INT_LEN)
		return (0);
	negative = *nbr == '-';
	if (len > MAX_INT_LEN + negative)
		return (1);
	i = 0;
	max = MAX_INT;
	if (*nbr == '-')
		max = MAX_N_INT;
	while (nbr[i])
	{
		if (nbr[i] < max[i])
			return (0);
		if (nbr[i] > max[i])
			return (1);
		i++;
	}
	return (0);
}

void	parse_input(char *arg, t_dstack *pswap)
{
	int		i;
	int		len;
	int		start;

	i = 0;
	len = ft_strlen(arg);
	while (i < len)
	{
		while (ft_hasany(" \t", arg[i]))
			i++;
		start = i;
		if (ft_hasany("+-", arg[i]))
			i++;
		while (ft_isdigit(arg[i]))
			i++;
		if (!ft_hasany(" \t", arg[i]) && arg[i] != '\0')
			free_end(pswap, 1, ERROR_INV_ARG);
		arg[i] = '\0';
		if (is_nbr2large(arg + start, i - start + 1))
			free_end(pswap, 1, ERROR_NBR2LARGE);
		ft_lstadd_back(&pswap->a, ft_lstnew(ft_atoi(arg + start)));
		if (i < len)
			arg[i] = ' ';
	}
}

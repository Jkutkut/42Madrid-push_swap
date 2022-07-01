/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/07/01 09:51:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#define MAX_INT_LEN 11
#define MAX_INT "2147483647"
#define MAX_N_INT "-2147483648"

// TODO recorrer el max num as string o min

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
	{
		max = MAX_N_INT;
		i++;
	}
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
	char	*result;

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
		if (!ft_hasany(" \t\0", arg[i]))
			free_end(pswap, 1, ERROR_INV_ARG);
		arg[i] = '\0';
		// if (is_nbr2large(arg + start, i - start))
		// 	free_end(pswap, 1, ERROR_NBR2LARGE);
		ft_lstadd_back(&pswap->a, ft_lstnew(ft_atoi(arg + start)));
		// TODO refactor
		result = ft_itoa(ft_lstlast(pswap->a)->content);
		start = ft_strncmp(result, arg + start, 11);
		free(result);
		if (start)
			free_end(pswap, 1, ERROR_NBR2LARGE);
		// TODO refactor
		if (i < len)
			arg[i] = ' ';
	}
}

// ""
// "   fsd afasd f asd"
// "   321312\0312312"
// "21 21 32"
// 12 123 21
// "   fsd afasd f asd"

// 1231231231231231231231312312
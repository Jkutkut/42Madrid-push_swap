/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/21 14:49:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#define MAX_INT_LEN 11
#define MAX_INT "+2147483647"
#define MAX_N_INT "-2147483648"

/**
 * @brief Checks if the given string can fit in a 32-bit integer.
 * 
 * @param nbr Number to check.
 * @param len Length of the number (number of characters).
 * @return int 1 if the number can fit in an int, 0 otherwise.
 */
static int	ft_is_nbr2large(const char *nbr, int len)
{
	int		i;
	int		signed_nbr;
	char	*max;

	if (!nbr || len < MAX_INT_LEN)
		return (0);
	signed_nbr = *nbr == '-' || *nbr == '+';
	if (len > MAX_INT_LEN + signed_nbr)
		return (1);
	i = 0;
	max = MAX_INT;
	if (*nbr == '-')
		max = MAX_N_INT;
	else if (*nbr != '+')
		max++;
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

/**
 * @brief Attempts to add the arg string to the stack.
 * It checks if the given string is a valid number.
 * If it is, it adds it to the stack. Else, the program ends.
 * 
 * @param arg String to add to the stack.
 * @param pswap Pushswap structure.
 */
void	ft_parse_input(char *arg, t_pswap *pswap)
{
	int		i;
	int		len;
	int		start;

	i = 0;
	len = ft_strlen(arg);
	while (i < len)
	{
		while (ft_hasany(SPACES, arg[i]))
			i++;
		start = i;
		if (ft_hasany("+-", arg[i]))
			i++;
		while (ft_isdigit(arg[i]))
			i++;
		if (!ft_hasany(SPACES, arg[i]) && arg[i] != '\0')
			ft_free_end(pswap, 1, ERROR_INV_ARG);
		if (start == i)
			continue ;
		arg[i] = '\0';
		// ft_printf("Start %d, i: %d: --%s--\n", start, i, arg + start); // TODO
		if (ft_is_nbr2large(arg + start, i - start + 1))
			ft_free_end(pswap, 1, ERROR_NBR2LARGE);
		ft_stack_addb(&pswap->a, ft_stack_new(ft_atoi(arg + start)));
		if (i < len)
			arg[i] = ' ';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 09:41:14 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	parse_input(char *arg, t_dstack *pswap)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	len = ft_strlen(arg);
	while (i < len)
	{
		while (ft_hasany(" \t", arg[i]))
			i++;
		start = i;
		while (ft_isdigit(arg[i]))
			i++;
		if (arg[i] != ' ' && arg[i] != '\0')
			free_end(pswap, 1, "Error: invalid argument\n");
		arg[i] = '\0';
		printf("Atoi: '%s' -> %d\n", arg + start, ft_atoi(arg + start));
		ft_lstadd_back(&pswap->a, ft_lstnew(ft_atoi(arg + start)));
		if (i < len)
			arg[i] = ' ';
	}
}

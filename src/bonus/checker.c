/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:10:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/25 18:49:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	moves_remaining(char **s)
{
	*s = get_next_line(0);
	if (s == NULL)
		return (0);
	return (1);
}



int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	char		*line;

	pswap = init_pushswap(argc, argv);
	while (moves_remaining(&line))
	{
		if (ft_strcmp(line, "sa") == 0)
			sa(pswap);
		else if (ft_strcmp(line, "sb") == 0)
			sb(pswap);
		else if (ft_strcmp(line, "ss") == 0)
			ss(pswap);
		else if (ft_strcmp(line, "pa") == 0)
			pa(pswap);
		else if (ft_strcmp(line, "pb") == 0)
			pb(pswap);
		else if (ft_strcmp(line, "ra") == 0)
			ra(pswap);
		else if (ft_strcmp(line, "rb") == 0)
			rb(pswap);
		else if (ft_strcmp(line, "rr") == 0)
			rr(pswap);
		else if (ft_strcmp(line, "rra") == 0)
			rra(pswap);
		else if (ft_strcmp(line, "rrb") == 0)
			rrb(pswap);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(pswap);
		else
		{
			free(line);
			free_end(pswap, 1, "Error\n");
		}
		free(line);
	}
	if (is_sorted(pswap))
		free_end(pswap, 1, "Error\n");
	free_end(pswap, 0, "OK\n");
}
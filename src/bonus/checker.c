/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:10:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/25 21:32:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	moves_remaining(char **s)
{
	*s = get_next_line(0);
	if (*s == NULL)
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
		if (ft_strncmp(line, "sa", 2) == 0)
			sa(pswap);
		else if (ft_strncmp(line, "sb", 2) == 0)
			sb(pswap);
		else if (ft_strncmp(line, "ss", 2) == 0)
			ss(pswap);
		else if (ft_strncmp(line, "pa", 2) == 0)
			pa(pswap);
		else if (ft_strncmp(line, "pb", 2) == 0)
			pb(pswap);
		else if (ft_strncmp(line, "ra", 2) == 0)
			ra(pswap);
		else if (ft_strncmp(line, "rb", 2) == 0)
			rb(pswap);
		else if (ft_strncmp(line, "rr", 2) == 0)
			rr(pswap);
		else if (ft_strncmp(line, "rra", 3) == 0)
			rra(pswap);
		else if (ft_strncmp(line, "rrb", 3) == 0)
			rrb(pswap);
		else if (ft_strncmp(line, "rrr", 3) == 0)
			rrr(pswap);
		else
		{
			free(line);
			free_end(pswap, 1, "Command not found\n");
		}
		free(line);
	}
	if (!is_sorted(pswap))
		free_end(pswap, 1, "Stack still not sorted :S\n");
	free_end(pswap, 0, "OK\n");
}
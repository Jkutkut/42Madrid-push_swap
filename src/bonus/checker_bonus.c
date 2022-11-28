/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:03:27 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 21:53:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#define STDIN 0

int	moves_remaining(char **s)
{
	*s = get_next_line(STDIN);
	return *s != NULL;
}

void	operate(t_pswap *pswap)
{
	char		*line;
	char		*result;

	while (moves_remaining(&line))
	{
		if (ft_strncmp(line, "sa", 2) == 0)
			result = ft_sa(pswap);
		else if (ft_strncmp(line, "sb", 2) == 0)
			result = ft_sb(pswap);
		else if (ft_strncmp(line, "ss", 2) == 0)
			result = ft_ss(pswap);
		else if (ft_strncmp(line, "pa", 2) == 0)
			result = ft_pa(pswap);
		else if (ft_strncmp(line, "pb", 2) == 0)
			result = ft_pb(pswap);
		else if (ft_strncmp(line, "ra", 2) == 0)
			result = ft_ra(pswap);
		else if (ft_strncmp(line, "rb", 2) == 0)
			result = ft_rb(pswap);
		else if (ft_strncmp(line, "rr\n", 3) == 0)
			result = ft_rr(pswap);
		else if (ft_strncmp(line, "rra", 3) == 0)
			result = ft_rra(pswap);
		else if (ft_strncmp(line, "rrb", 3) == 0)
			result = ft_rrb(pswap);
		else if (ft_strncmp(line, "rrr", 3) == 0)
			result = ft_rrr(pswap);
		else
		{
			free(line);
			ft_free_end(pswap, 1, "Command not found\n");
		}
		free(line);
		if (!result)
			ft_free_end(pswap, 1, "Not able to execute the asked steps.\n");
	}
	if (!ft_is_sorted(pswap))
		ft_free_end(pswap, 1, "Stack still not sorted :S\n");
	ft_free_end(pswap, 0, "OK\n");
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;

	ft_init_pushswap(&pswap, argc, argv);
	operate(&pswap);
	return (0);
}

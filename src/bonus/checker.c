/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:10:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/26 00:52:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	moves_remaining(char **s)
{
	*s = get_next_line(0);
	printf("'%s'\n", *s);
	if (*s == NULL)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	char		*line;
	char		*result;

	pswap = init_pushswap(argc, argv);
	print(pswap);
	while (moves_remaining(&line))
	{
		if (ft_strncmp(line, "sa", 2) == 0)
			result = sa(pswap);
		else if (ft_strncmp(line, "sb", 2) == 0)
			result = sb(pswap);
		else if (ft_strncmp(line, "ss", 2) == 0)
			result = ss(pswap);
		else if (ft_strncmp(line, "pa", 2) == 0)
			result = pa(pswap);
		else if (ft_strncmp(line, "pb", 2) == 0)
			result = pb(pswap);
		else if (ft_strncmp(line, "ra", 2) == 0)
			result = ra(pswap);
		else if (ft_strncmp(line, "rb", 2) == 0)
			result = rb(pswap);
		else if (ft_strncmp(line, "rr\n", 3) == 0)
			result = rr(pswap);
		else if (ft_strncmp(line, "rra", 3) == 0)
			result = rra(pswap);
		else if (ft_strncmp(line, "rrb", 3) == 0)
			result = rrb(pswap);
		else if (ft_strncmp(line, "rrr", 3) == 0)
			result = rrr(pswap);
		else
		{
			free(line);
			free_end(pswap, 1, "Command not found\n");
		}
		free(line);
		if (!result)
			free_end(pswap, 1, "Not able to execute the asked steps.\n");
		print(pswap);
	}
	if (!is_sorted(pswap))
		free_end(pswap, 1, "Stack still not sorted :S\n");
	free_end(pswap, 0, "OK\n");
}
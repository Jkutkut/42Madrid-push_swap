/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:03:27 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 19:03:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#define STDIN 0

int	moves_remaining(char **s)
{
	*s = get_next_line(STDIN);
	if (*s == NULL)
		return (0);
	return (1);
}

void	operate(t_pswap *pswap)
{
	char		*line;
	char		*result;

	t_stack *a = pswap->a;
	ft_printf("Size: %i\n", ft_stack_len(a));
	while (a)
	{
		ft_printf("-> %i\n", a->content);
		a = a->next;
	}
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
			ft_printf("cmdnotfound: '%s'\n", line);
			int i = 0;
			while (line[i])
				ft_printf("- %c\n", line[i++]);
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

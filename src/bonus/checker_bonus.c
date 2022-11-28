/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:03:27 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 23:27:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#define STDIN 0

static int	moves_remaining(char **s)
{
	*s = get_next_line(STDIN);
	return (*s != NULL);
}

static int	is_operation(char *line, char *operation)
{
	return (ft_strncmp(line, operation, ft_strlen(operation)) == 0);
}

static int	apply(t_pswap *pswap, char *line, char **result)
{
	int	i;

	i = NUMBER_OPERATIONS;
	while (--i >= 0)
	{
		if (is_operation(line, pswap->operation_names[i]))
		{
			*result = pswap->operations[i](pswap);
			return (1);
		}
	}
	return (0);
}

static void	operate(t_pswap *pswap)
{
	char		*line;
	char		*result;

	while (moves_remaining(&line))
	{
		if (!apply(pswap, line, &result))
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

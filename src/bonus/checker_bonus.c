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

/**
 * @brief the GNL to obtain the next line of the STDIN.
 * @returns If the line is NULL or not (if end of file).
 */
static int	moves_remaining(char **s)
{
	*s = get_next_line(STDIN);
	return (*s != NULL);
}

/**
 * @brief Checks if the given instruction is the given valid operation.
 * @returns The result of the check.
static int	is_operation(char *line, char *operation)
{
	return (ft_strncmp(line, operation, ft_strlen(operation)) == 0);
}

/**
 * @brief Applies the operation described in the line and stores the result
 * of it on the line.
 * 
 * @param pswap Structure.
 * @param line The line describing the command to exectute.
 * @param result The result variable to store the result of the operation.
 * @returns 1 if the operation was found and executed, 0 if the cnf.
 */
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

/**
 * @brief Applies all operations described by the stdin.
 * If any operation is not valid, an error will end the program.
 * If the stack ends not sorted, it will also fail.
 * 
 * @param pswap Push swap structure.
 */
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

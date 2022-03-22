/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 09:28:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"


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
		printf("Start '%s'\n", arg + start);
		while (ft_isdigit(arg[i]))
			i++;
		printf("end '%s' -> %d\n", arg + i, arg[i] - '\0');
		if (arg[i] != ' ' && arg[i] != '\0')
			free_end(pswap, 1, "Error: invalid argument\n");
		arg[i] = '\0';
		printf("Atoi: '%s' -> %d\n", arg + start, ft_atoi(arg + start));
		ft_lstadd_back(&pswap->a, ft_lstnew(ft_atoi(arg + start)));
		if (i < len)
			arg[i] = ' ';
	}
}

t_dstack	*init_pushswap(int argv, char **arg)
{
	t_dstack	*pswap;
	int			i;

	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	pswap->b = NULL;
	pswap->a = NULL;
	i = 1;
	while (i < argv)
		parse_input(arg[i++], pswap);
	return (pswap);
}


void	check_leaks(void)
{
	system("leaks -q ft_pushswap");
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;

	atexit(check_leaks);
	if (argc == 1)
		return (1);
	pswap = init_pushswap(argc, argv);
	if (pswap == NULL)
	{
		printf("Error\n");
		return (1);
	}
	if (GRAPHIC)
		print(pswap);
	return (0);
}

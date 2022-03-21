/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 20:26:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_dstack	*init_pushswap(char *arg)
{
	t_dstack	*pswap;
	int			i;
	int		start;
	int		len;

	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	i = 0;
	pswap->b = NULL;
	len = ft_strlen(arg);
	while (i < len)
	{
		while (ft_hasany(" ", arg[i]))
			i++;
		start = i;
		while (ft_isdigit(arg[i]))
			i++;
		if (!ft_hasany(" \0", arg[i]))
			free_end(pswap, 1, "Error: invalid argument\n");
		arg[i] = '\0';
		ft_lstadd_back(&pswap->a, ft_lstnew(ft_atoi(arg + start)));
	}
	return (pswap);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	
	if (argc != 2)
		return (1);
	pswap = init_pushswap(argv[1]);
	if (pswap == NULL)
	{
		printf("Error\n");
		return (1);
	}
	if (GRAPHIC)
		print(pswap);
	return (0);
}

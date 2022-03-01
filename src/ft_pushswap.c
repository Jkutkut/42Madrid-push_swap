/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/01 18:50:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	print_row(t_list a, t_list b, buffer)
{
	size_t	i;
	char	*s;
	size_t	l;

	i = 0;
	if (a != NULL)
	{
		s = ft_itoa(a->content);
		l = ft_strlen(s);
		i += ft_strlcat(buffer, s, l);
	}
	else
	{
		l = 0;
		while (l++ < MAXNUMLEN)
		{
			
		}
		i += ft_strlcat(buffer, "   ")
	}
}

void	print_pushswap(t_dstack *pswap)
{
	char	buffer[4096];
	t_list	a;
	t_list	b;
	size_t	i;

	i = 0;
	a = pswap->a;
	b = pswap->b;
	while (a != NULL || b != NULL)
	{
		i += print_row(a, b, (buffer + i));
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	write(1, buffer, );
}

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;

	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	pswap->b = NULL;
	pswap->a = ft_lstnew(2);

	ft_lstadd_back(&pswap->a, ft_lstnew(3));
	ft_lstadd_back(&pswap->a, ft_lstnew(6));
	return (pswap);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	
	pswap = init_pushswap(argc, argv);
	// sort
	// print
	return (0);
}

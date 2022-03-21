/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/21 10:45:04 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	print_row(t_list *elements[2], char *buffer, int num_size)
{
	size_t	i;
	char	*s;
	size_t	l;
	int		len;
	int		index;

	index = 0;
	i = ft_strlcat(buffer, "| ", 2 + 1);
	while (index < 2)
	{
		s = "";
		if (elements[index] != NULL)
			s = ft_itoa(elements[index]->content);
		l = ft_strlen(s);
		len = num_size - l;
		while (len-- > 0)
			i += ft_strlcat(buffer + i, " ", 1 + 1);
		if (l > 0)
		{
			i += ft_strlcat(buffer + i, s, l + 1);
			free(s);
		}
		i += ft_strlcat(buffer + i, " | ", 3 + 1);
		index++;
	}
	i += ft_strlcat(buffer + i, "\n", 1 + 1);
	return (i);
}

void	print_pushswap(t_dstack *pswap)
{
	char	buffer[4096];
	t_list	*elements[2];
	size_t	i;
	int		num_size;

	i = 0;
	num_size = MAXNUMLEN + 2;
	while (num_size--)
		i += ft_strlcat(buffer + i, " ", 1 + 1);
	i += ft_strlcat(buffer + i, "A | B", 6 + 1);
	num_size = MAXNUMLEN + 2;
	while (num_size--)
		i += ft_strlcat(buffer + i, " ", 1 + 1);
	i += ft_strlcat(buffer + i, "\n", 1 + 1);
	elements[0] = pswap->a;
	elements[1] = pswap->b;
	while (elements[0] != NULL || elements[1] != NULL)
	{
		i += print_row(elements, (buffer + i), MAXNUMLEN);
		if (elements[0] != NULL)
			elements[0] = elements[0]->next;
		if (elements[1] != NULL)
			elements[1] = elements[1]->next;
	}
	write(1, buffer, i);
}

t_dstack	*init_pushswap(int argc, char **argv)
{
	t_dstack	*pswap;

	if (argc < 2)
		argv++;
	pswap = malloc(sizeof(t_dstack));
	if (pswap == NULL)
		return (NULL);
	pswap->b = NULL;
	// pswap->b = ft_lstnew(123);
	pswap->a = ft_lstnew(2);

	ft_lstadd_back(&pswap->a, ft_lstnew(234));
	ft_lstadd_back(&pswap->a, ft_lstnew(6));
	return (pswap);
}

int	main(int argc, char **argv)
{
	t_dstack	*pswap;
	
	pswap = init_pushswap(argc, argv);
	if (GRAPHIC)
		print_pushswap(pswap);
	// sort
	// print
	return (0);
}

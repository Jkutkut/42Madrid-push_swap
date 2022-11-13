/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:48:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:53:19 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define MAXNUMLEN 3

int	print_row(t_stack *elements[2], char *buffer, int num_size)
{
	size_t	i;
	char	*s;
	size_t	l;
	int		len;
	int		index;

	index = 0;
	ft_memmove(buffer, "| ", 2);
	i = 2;
	while (index < 2)
	{
		s = "";
		if (elements[index] != NULL)
			s = ft_itoa(elements[index]->content);
		l = ft_strlen(s);
		len = num_size - l;
		while (len-- > 0)
			ft_memmove(buffer + i++, " ", 1);
		if (l > 0)
		{
			ft_memmove(buffer + i, s, l);
			i += l;
			free(s);
		}
		ft_memmove(buffer + i, " | ", 3);
		i+= 3;
		index++;
	}
	ft_memmove(buffer + i++, "\n\0", 2);
	return (i);
}

void	print(t_dstack *pswap, int fd)
{
	char	buffer[4096];
	t_stack	*elements[2];
	size_t	i;
	int		num_size;

	i = 0;
	num_size = MAXNUMLEN + 2 - 1;
	while (num_size--)
		ft_memmove(buffer + i++, " ", 1);
	ft_memmove(buffer + i, "A | B\n", 6);
	i += 6;
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
	buffer[i] = '\0';
	write(fd, buffer, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:56:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest_signi_int(int size)
{
	int	bit;

	bit = 0;
	while (size > 0)
	{
		if ((size >> bit) & 1)
			size -= 1 << bit;
		bit++;
	}
	return (bit);
}

int	canSkipPAs(t_stack *b)
{
	int	size;
	int	current;

	size = ft_stack_len(b);
	current = b->content;
	if (size < current)
		return (0);
	while (b && current <= size)
	{
		if (current == b->content)
			current--;
		b = b->next;
	}
	return (current == -1);
}

void	skipPAs(t_dstack *p)
{
	int	v;

	if (stack_is_sorted(p->b, DESC_ORDER) || !p->b->next)
		return ;
	v = p->b->content;
	apply(p, RB);
	while (p->b->content != v)
	{
		if (p->b->content < v)
			apply(p, RB);
		else
			apply(p, PA);
	}
}

void	radix_sort(t_dstack *p)
{
	int	bit;
	int	maxBit;

	bit = 0;
	maxBit = biggest_signi_int(p->size);
	while(!is_sorted(p) && bit < maxBit)
	{
		int ops = ft_stack_len(p->a);
		while (ops-- > 0 && !stack_is_sorted(p->a, ASC_ORDER))
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else
			{
				if (p->a->next)
					apply(p, RA);
				else
					break;
			}
		}
		while (p->b)
		{
			if (canSkipPAs(p->b))
			{
				skipPAs(p);
				break;
			}
			apply(p, PA);
		}
		bit++;
	}
	while (p->b)
		apply(p, PA);
}

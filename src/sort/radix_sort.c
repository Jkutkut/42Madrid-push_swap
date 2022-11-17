/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:57:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 12:23:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Logic to obtain the position of the biggest bit in the number.
 * 
 * @param nbr number to check.
 * @return int position of the biggest bit != 0.
 */
static int	biggest_signi_bit(int nbr)
{
	int	bit;

	bit = 0;
	while (nbr > 0)
	{
		if ((nbr >> bit) & 1)
			nbr -= 1 << bit;
		bit++;
	}
	return (bit);
}

/**
 * @brief Check if some of the elements in b can not be moved to a
 * because they already are in the right position.
 * 
 * @param b stack b.
 * @return int 0 if not possible to skip, 1 otherwise.
 */
static int	can_skip_pas(t_stack *b)
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

/**
 * @brief Skip the PA movements when can_skip_pas is true.
 * 
 * @param p Push_swap structure.
 */
static int	skip_pas(t_dstack *p)
{
	int	v;

	if (!can_skip_pas(p->b))
		return (0);
	if (stack_is_sorted(p->b, DESC_ORDER) || !p->b->next)
		return (1);
	v = p->b->content;
	apply(p, RB);
	while (p->b->content != v)
	{
		if (p->b->content < v)
			apply(p, RB);
		else
			apply(p, PA);
	}
	return (1);
}

/**
 * @brief Sort the stack a using radix sort.
 * 
 * @param p Push_swap structure.
 */
void	radix_sort(t_dstack *p)
{
	int	bit;
	int	max_bit;
	int	ops;

	bit = 0;
	max_bit = biggest_signi_bit(p->size);
	while (!is_sorted(p) && bit < max_bit)
	{
		ops = ft_stack_len(p->a);
		while (ops-- && !stack_is_sorted(p->a, ASC_ORDER))
		{
			if (((p->a->content >> bit) & 1) == 0)
				apply(p, PB);
			else if (p->a->next)
				apply(p, RA);
			else
				break ;
		}
		while (p->b && !skip_pas(p))
			apply(p, PA);
		bit++;
	}
	while (p->b)
		apply(p, PA);
}

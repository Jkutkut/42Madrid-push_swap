/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:16:57 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/14 10:44:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO doc

static int	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return (0);
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

char	*pa(t_dstack *pswap)
{
	if (!push_stack(&pswap->b, &pswap->a))
		return (NULL);
	return ("pa");
}

char	*pb(t_dstack *pswap)
{
	if (!push_stack(&pswap->a, &pswap->b))
		return (NULL);
	return ("pb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/17 13:43:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

void	apply(t_dstack *pswap, t_op o);

// Swap
char	*sa(t_dstack *pswap);
char	*sb(t_dstack *pswap);
char	*ss(t_dstack *pswap);

// Push
char	*pa(t_dstack *pswap);
char	*pb(t_dstack *pswap);

// Rotate
char	*ra(t_dstack *pswap);
char	*rb(t_dstack *pswap);
char	*rr(t_dstack *pswap);

// Reverse Rotate
char	*rra(t_dstack *pswap);
char	*rrb(t_dstack *pswap);
char	*rrr(t_dstack *pswap);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/24 08:26:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "push_swap.h"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

void	apply(t_dstack *pswap, int o);

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

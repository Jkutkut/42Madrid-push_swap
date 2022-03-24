/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 08:12:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "../ft_pushswap.h"

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
int		swap_list(t_list **lst);

// Swap
char	*sa(t_dstack *pswap);
char	*sb(t_dstack *pswap);
char	*ss(t_dstack *pswap);


#endif

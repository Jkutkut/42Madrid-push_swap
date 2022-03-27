/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/27 17:10:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "../ft_pushswap.h"

int		is_sorted(t_dstack *pswap);
void	sort_small(t_dstack *pswap);
void	sort(t_dstack *pswap);

#endif

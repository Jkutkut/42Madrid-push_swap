/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:34:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 18:22:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

#include "push_swap.h"

void	check_input(t_dstack *pswap);
void	init_pushswap(t_dstack	*pswap, int argc, char **argv);
void	normalize(t_dstack *pswap);
void	parse_input(char *arg, t_dstack *pswap);

#endif
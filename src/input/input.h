/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:34:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/22 09:38:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

#include "../ft_pushswap.h"

t_dstack	*init_pushswap(int argv, char **arg);
void	parse_input(char *arg, t_dstack *pswap);

#endif
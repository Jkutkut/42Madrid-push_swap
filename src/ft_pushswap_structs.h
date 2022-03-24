/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:06:25 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/24 12:15:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_STRUCTS_H
# define FT_PUSHSWAP_STRUCTS_H

#include "t_list/t_list.h"

typedef struct	s_dstack
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		*arg;
}			t_dstack;

#endif
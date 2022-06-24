/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/06/24 08:23:56 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP
# define FT_PUSHSWAP

#include <unistd.h>
#  include <stdio.h> // TODO REMOVE
#include <stdlib.h>

#include "t_list.h"

typedef struct	s_dstack
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		*arg;
}			t_dstack;

#include "input.h"
#include "msg.h"
#include "operations.h"
#include "push_swap_utils.h"
#include "tools.h"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/03/01 18:50:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP
# define FT_PUSHSWAP

#include "libft/libft.h"
#include "t_list/t_list.h"

#ifndef DEBUG
# define GRAPHIC 0
#else
# define GRAPHIC 1
#endif

# define MAXNUMLEN 3

typedef struct	s_dstack
{
	t_list	*a;
	t_list	*b;
}			t_dstack;

#endif

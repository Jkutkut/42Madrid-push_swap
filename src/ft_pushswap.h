/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkutkut <jre-gonz@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/02/19 17:16:05 by jkutkut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP
# define FT_PUSHSWAP

#include "libft/libft.h"

#ifndef DEBUG
# define GRAPHIC 0
#else
# define GRAPHIC 1
#endif

typedef struct	s_dstack
{
	t_list	a;
	t_list	b;
}			t_dstack;

#endif

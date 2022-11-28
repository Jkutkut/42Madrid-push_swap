/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:34:49 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 23:03:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_BONUS_H
# define ELEMENTS_BONUS_H

/**
 * @brief Struct defining the linked lists used in the push_swap program.
 */
typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

/**
 * @brief Struct defining all the logic needed to encapsulate the program.
 */
typedef struct s_pswap
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*arg;
	char	*(*operations[11])(struct s_pswap*);
	char	*operation_names[11];
}		t_pswap;

/**
 * @brief Enum defining all the operations allowed in the push_swap program.
 * It also contains the number of operations.
 */
typedef enum e_op
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,
	NUMBER_OPERATIONS = 11
}	t_op;

#endif

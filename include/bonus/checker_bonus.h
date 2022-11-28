/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:26:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/11/28 19:12:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

# include "elements_bonus.h"

# define ERROR "error: \n  "
# define ERROR_MALLOC "malloc failed.\n"
# define ERROR_INV_ARG "invalid argument.\n"
# define ERROR_NBR2LARGE "number too large.\n"
# define ERROR_REPEAT_NBR "numbers must not repeat.\n"

# define ERROR_APPLY_LEN 42
# define ERROR_APPLY "not able to execute the move    .\n"
# define ERROR_APPLY_OP "operation not found.\n"
# define ERROR_APPLY_MOVE " sa sb ss pa pb ra rb rrrrarrbrrr"

// ********* input *********

# define SPACES " \t"

void	ft_check_input(t_pswap *pswap);
void	ft_init_pushswap(t_pswap *pswap, int argc, char **argv);
void	ft_normalize(t_pswap *pswap);
void	ft_parse_input(char *arg, t_pswap *pswap);

// ********* operations *********

void	ft_apply(t_pswap *pswap, t_op o);

// Push
char	*ft_pa(t_pswap *pswap);
char	*ft_pb(t_pswap *pswap);

// Reverse Rotate
char	*ft_rra(t_pswap *pswap);
char	*ft_rrb(t_pswap *pswap);
char	*ft_rrr(t_pswap *pswap);

// Rotate
char	*ft_ra(t_pswap *pswap);
char	*ft_rb(t_pswap *pswap);
char	*ft_rr(t_pswap *pswap);

// Swap
char	*ft_sa(t_pswap *pswap);
char	*ft_sb(t_pswap *pswap);
char	*ft_ss(t_pswap *pswap);

// ********* push_swap_utils *********

int		ft_binary_search(int arr[], int l, int r, int value);
void	ft_end(int endtype, char *msg);
void	ft_free_end(t_pswap *pswap, int endtype, char *msg);
// int		ft_get_from_stack(int (*f)(int, int), t_stack *stack);
// 
// // lambdas
// int		ft_max(int a, int b);
// int		ft_min(int a, int b);
// int		ft_abs(int nbr);
// 
void	ft_merge_sort(t_pswap *pswap);
// int		ft_shortest_dist_to_values(int v1, int v2, t_stack *s);
int		*ft_stack_to_array(t_stack *stack, int size);

// ********* Sort *********
int		ft_is_sorted(t_pswap *pswap);

// ********* t_stack *********

void	ft_stack_addb(t_stack **stack, t_stack *new);
void	ft_stack_addf(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_del(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_new(int value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:58:56 by jkutkut           #+#    #+#             */
/*   Updated: 2022/11/09 20:12:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP
# define FT_PUSHSWAP

# include <stddef.h>
# include <unistd.h>
#       include <stdio.h> // TODO REMOVE
# include <stdlib.h>

# include "t_list.h"

typedef struct	s_dstack
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		*arg;
}			t_dstack;

#include "msg.h"
#include "sort.h"
#include "operations.h"

// input
void	check_input(t_dstack *pswap);
void	init_pushswap(t_dstack	*pswap, int argc, char **argv);
void	normalize(t_dstack *pswap);
void	parse_input(char *arg, t_dstack *pswap);

// push_swap_utils
int		binary_search(int arr[], int l, int r, int value);
void	free_end(t_dstack *pswap, int endtype, char *msg);
int		get_from_lst(int (*f)(int, int), t_list *lst);
int		*linkedlist_to_array(t_list *lst, int size);
void	merge_sort(int *array, int size);
void	print(t_dstack *pswap, int fd);

// push_swap_utils/miscellaneous
int	ft_max(int a, int b);
int	ft_min(int a, int b);

// tools
void	end(int endtype, char *msg);
int	ft_abs(int nbr);
int		ft_atoi(const char *nptr);
int		ft_hasany(const char *str, char c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	*ft_memmove(void *dest, const void *source, size_t n);
size_t	ft_ndigits(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

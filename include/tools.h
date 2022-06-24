/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:39:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/24 08:19:25 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
#define TOOLS_H

# include <stddef.h>
# include <stdlib.h>

void	end(int endtype, char *msg);
int		ft_atoi(const char *nptr);
int		ft_hasany(const char *str, char c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	*ft_memmove(void *dest, const void *source, size_t n);
size_t	ft_ndigits(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
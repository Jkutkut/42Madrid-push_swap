/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:39:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/17 10:42:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
#define TOOLS_H

# include <stddef.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_hasany(const char *str, char c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
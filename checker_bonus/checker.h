/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:41:53 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/11 16:47:01 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "../push_swap.h"
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_free(char **buffer);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);

#endif
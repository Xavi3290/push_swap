/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:11 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/12 17:38:47 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

static void	commands(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(b, a, 1);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b, 1);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, 1);
	else
		print_error();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (error_syntax(argv) || error_int(argv) || error_dup(argv))
		print_error();
	fill_stack(&a, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		commands(&a, &b, line);
		line = get_next_line(0);
	}
	if (0 == stack_len(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:29:03 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/12 19:01:02 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **ori, t_stack **dest)
{
	t_stack	*first_node;

	first_node = *ori;
	*ori = (*ori)->next;
	if (*ori)
		(*ori)->prev = NULL;
	if (!*dest)
	{
		*dest = first_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = first_node;
		first_node->next = *dest;
		*dest = first_node;
	}
}

void	pa(t_stack **b, t_stack **a, int check)
{
	if (!*b)
		return ;
	push(b, a);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int check)
{
	if (!*a)
		return ;
	push(a, b);
	if (!check)
		write(1, "pb\n", 3);
}

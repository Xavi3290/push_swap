/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:15:34 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/11 19:28:53 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_last_node(*stack);
	first_node = *stack;
	last_node->next = *stack;
	last_node->prev->next = NULL;
	first_node->prev = last_node;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rra(t_stack **a, int check)
{
	reverse(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int check)
{
	reverse(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int check)
{
	reverse(a);
	reverse(b);
	if (!check)
		write(1, "rrr\n", 4);
}

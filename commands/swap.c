/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:48 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/12 19:01:49 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*aux;

	if (*stack || (*stack)->next)
	{
		aux = *stack;
		*stack = (*stack)->next;
		aux->next = (*stack)->next;
		(*stack)->next = aux;
		if (aux->next)
			aux->next->prev = aux;
		aux->prev = *stack;
		(*stack)->prev = NULL;
	}
}

void	sa(t_stack **a, int check)
{
	if (!*a)
		return ;
	swap(a);
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int check)
{
	if (!*b)
		return ;
	swap(b);
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	if (!*b || !*a)
		return ;
	swap(a);
	swap(b);
	if (!check)
		write(1, "ss\n", 3);
}

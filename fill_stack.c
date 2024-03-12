/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:36 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/03/08 15:30:59 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	fill_stack(t_stack **a, char **argv)
{
	int	num;
	int	i;

	i = 1;
	while (argv[i])
	{
		num = (int)ft_atol(argv[i]);
		append_node(a, num);
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (*stack && stack)
	{
		temp = *stack;
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*stack = NULL;
	}
}

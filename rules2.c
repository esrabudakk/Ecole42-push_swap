/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:46:48 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/03 19:48:04 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_array_value *arr, t_temp_value tmp)
{
	if (arr->a_size <= 0)
		return ;
	tmp.first_index_a = arr->a[0];
	ft_memmove(arr->a, arr->a + 1, 4 * arr->a_size);
	arr->a[arr->a_size - 1] = tmp.first_index_a;
	write(1, "ra\n", 3);
}

void	ft_rb(t_array_value *arr, t_temp_value tmp)
{
	if (arr->b_size < 0)
		return ;
	tmp.first_index_b = arr->b[0];
	ft_memmove(arr->b, arr->b + 1, 4 * arr->b_size);
	arr->b[arr->b_size - 1] = tmp.first_index_b;
	write(1, "rb\n", 3);
}

void	ft_rra(t_array_value *arr, t_temp_value tmp)
{
	if (arr->a_size < 0)
		return ;
	tmp.last_index_a = arr->a[arr->a_size -1];
	ft_memmove(arr->a + 1, arr->a, 4 * arr->a_size);
	arr->a[0] = tmp.last_index_a;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_array_value *arr, t_temp_value tmp)
{
	if (arr->b_size < 0)
		return ;
	tmp.last_index_b = arr->b[arr->b_size -1];
	ft_memmove(arr->b + 1, arr->b, 4 * arr->b_size);
	arr->b[0] = tmp.last_index_b;
	write(1, "rrb\n", 4);
}

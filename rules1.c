/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:47:30 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/03 19:47:53 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_array_value *arr, t_temp_value tmp)
{
	if (arr->a_size <= 0)
		return ;
	tmp.first_index_a = arr->a[0];
	tmp.second_index_a = arr->a[1];
	arr->a[1] = tmp.first_index_a;
	arr->a[0] = tmp.second_index_a;
	write(1, "sa\n", 3);
}

void	ft_sb(t_array_value *arr, t_temp_value tmp)
{
	if (arr->b_size <= 0)
		return ;
	tmp.first_index_b = arr->b[0];
	tmp.second_index_b = arr->b[1];
	arr->b[1] = tmp.first_index_b;
	arr->b[0] = tmp.second_index_b;
	write(1, "sb\n", 3);
}

void	ft_pa(t_array_value *arr, t_temp_value tmp)
{
	if (arr->b_size == -1)
		return ;
	tmp.first_index_b = arr->b[0];
	arr->a_size++;
	ft_memmove(arr->a + 1, arr->a, 4 * arr->a_size);
	arr->a[0] = tmp.first_index_b;
	ft_memmove(arr->b, arr->b + 1, 4 * arr->b_size);
	arr->b_size--;
	write(1, "pa\n", 3);
}

void	ft_pb(t_array_value *arr, t_temp_value tmp)
{
	if (arr->a_size == -1)
		return ;
	tmp.first_index_a = arr->a[0];
	arr->b_size++;
	ft_memmove(arr->b + 1, arr->b, 4 * arr->b_size);
	arr->b[0] = tmp.first_index_a;
	ft_memmove(arr->a, arr->a + 1, 4 * arr->a_size);
	arr->a_size--;
	write(1, "pb\n", 3);
}

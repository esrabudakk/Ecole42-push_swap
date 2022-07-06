/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:52:28 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/03 19:57:30 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_index_first(t_array_value *arr)
{
	int	i;
	int	*new_a;

	i = -1;
	new_a = (int *)malloc(sizeof(int) * arr->a_size);
	while (++i < arr->a_size)
		new_a[ft_make_index(arr)] = i;
	free(arr->a);
	arr->a = new_a;
}

void	start_struct(t_array_value *arr, t_temp_value *tmp)
{
	arr->a = 0;
	arr->tmparr = 0;
	arr->b = 0;
	arr->a_size = 0;
	arr->b_size = 0;
	tmp->argv_indx = 0;
	tmp->argv_elemn = 0;
	tmp->argv_count = 0;
	tmp->g = 0;
	tmp->first_index_a = 0;
	tmp->last_index_a = 0;
	tmp->first_index_b = 0;
	tmp->last_index_b = 0;
	tmp->second_index_a = 0;
	tmp->second_index_b = 0;
}

void	three_param(t_array_value *arr, t_temp_value tmp, int n)
{
	if (n != arr->a[2])
	{
		if (n == arr->a[0])
		{
			ft_ra(arr, tmp);
		}
		else
			ft_rra(arr, tmp);
	}
	if (arr->a[0] > arr->a[1])
		ft_sa(arr, tmp);
}

void	find_1_2(t_array_value *arr, t_temp_value tmp)
{
	while (arr->b_size <= 1)
	{
		if (0 == arr->a[0] || 1 == arr->a[0])
			ft_pb(arr, tmp);
		else
			ft_ra(arr, tmp);
	}
	if (0 == arr->b[0])
		ft_sb(arr, tmp);
}

void	five_param(t_array_value *arr, t_temp_value tmp)
{
	find_1_2(arr, tmp);
	three_param(arr, tmp, 4);
	ft_pa(arr, tmp);
	ft_pa(arr, tmp);
}

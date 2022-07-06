/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:49:57 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/05 01:16:57 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_array_value *arr)
{
	write(1, "Error\n", 6);
	free(arr);
	exit(0);
}

void	change_to_bit(t_array_value *arr, t_temp_value tmp, int j)
{
	if (((arr->a[0] >> j) & 0x01) == 0)
		ft_pb(arr, tmp);
	else
		ft_ra(arr, tmp);
}

void	radix_sort(t_array_value *arr, t_temp_value tmp)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	i = 0;
	j = 0;
	bit_size = 8;
	if (arr->a_size == 100)
		bit_size = 6;
	while (j <= bit_size)
	{
		i = 0;
		size = arr->a_size;
		while (i < size)
		{
			change_to_bit(arr, tmp, j);
			i++;
		}
		while (arr->b_size != 0)
			ft_pa(arr, tmp);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_array_value	*arr;
	t_temp_value	tmp;

	arr = (t_array_value *)malloc(sizeof(t_array_value));
	start_struct(arr, &tmp);
	arr->k = arg_count(argc, argv, arr);
	arg_count2(argc, argv, arr, tmp);
	ft_make_index_first(arr);
	if (arr->a_size == 2 && arr->a[0] > arr->a[1])
		ft_sa(arr, tmp);
	else if (arr->a_size == 3)
		three_param(arr, tmp, 2);
	else if (arr->a_size == 5 || arr->a_size == 4)
		five_param(arr, tmp);
	else if (arr->a_size > 5)
		radix_sort(arr, tmp);
	else
		exit(0);
	free(arr->a);
	free(arr->b);
}

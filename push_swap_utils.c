/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:49:22 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/03 19:57:15 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_count(int argc, char **argv, t_array_value *arr)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (argc--)
	{
		k += w_c(argv[i], ' ');
		i++;
	}
	arr->a_size = k - 1;
	return (k - 1);
}

void	duplicate(t_array_value *arr)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	while (i < arr->a_size)
	{
		j = i + 1;
		while (j < arr->a_size)
		{
			if (arr->a[i] == arr->a[j])
			{
				write(1, "Error\n", 6);
				free(arr);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	already_sorted(t_array_value *arr)
{
	int	i;

	i = 0;
	while (i < arr->a_size - 1)
	{
		if (arr->a[i] > arr->a[i + 1])
		{
			return ;
		}
		i++;
	}
	free(arr);
	exit(0);
}

void	arg_count2(int argc, char **argv, t_array_value *arr, t_temp_value tmp)
{
	arr->a = (int *)malloc(arg_count(argc, argv, arr) * 4);
	arr->b = (int *)malloc(arg_count(argc, argv, arr) * 4);
	while (argc-- > 1)
	{
		tmp.argv_elemn = w_c(argv[tmp.argv_indx + 1], ' ');
		if (tmp.argv_elemn == 1)
			arr->a[tmp.argv_count] = ft_atoi(argv[tmp.argv_indx + 1], arr);
		else if (tmp.argv_elemn > 1)
		{
			arr->tmparr = ft_split(argv[tmp.argv_indx + 1], ' ');
			while (tmp.argv_elemn--)
				arr->a[tmp.argv_count++] = ft_atoi(arr->tmparr[tmp.g++], arr);
			tmp.g = 0;
			while (arr->tmparr[tmp.g])
				free(arr->tmparr[tmp.g++]);
			free(arr->tmparr);
			tmp.g = 0;
			tmp.argv_count--;
		}
		tmp.argv_indx++;
		tmp.argv_count++;
	}
	already_sorted(arr);
	duplicate(arr);
}

int	ft_make_index(t_array_value *arr)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	min = 2147483647;
	while (i < arr->a_size)
	{
		if (min > arr->a[i])
		{
			min = arr->a[i];
			j = i;
		}
		i++;
	}
	arr->a[j] = 2147483647;
	return (j);
}

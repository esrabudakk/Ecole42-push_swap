/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:41:52 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/05 17:15:20 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_array_value
{
	char	**tmparr;
	int		*a;
	int		*b;
	int		*index;
	int		a_size;
	int		b_size;
	int		k;
}	t_array_value;

typedef struct s_temp_value
{
	int	argv_indx;
	int	argv_elemn;
	int	argv_count;
	int	first_index_a;
	int	last_index_a;
	int	first_index_b;
	int	last_index_b;
	int	second_index_a;
	int	second_index_b;
	int	g;
}	t_temp_value;

int		ft_atoi(const char *str, t_array_value *arr);
int		ft_strlen(const char *s);
int		main(int argc, char **argv);
char	**ft_split(char const *s, char c);
size_t	w_c(char const *s, char c);
size_t	w_l(char const *s, char c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *str);
int		arg_count(int argc, char **argv, t_array_value *arr);
void	arg_count2(int argc, char **argv, t_array_value *arr, t_temp_value tmp);
void	ft_make_index_first(t_array_value *arr);
int		ft_make_index(t_array_value *arr);
void	start_struct(t_array_value *arr, t_temp_value *tmp);
void	five_param(t_array_value *arr, t_temp_value tmp);
void	ft_sa(t_array_value *arr, t_temp_value tmp);
void	ft_sb(t_array_value *arr, t_temp_value tmp);
void	ft_ra(t_array_value *arr, t_temp_value tmp);
void	ft_rb(t_array_value *arr, t_temp_value tmp);
void	ft_rra(t_array_value *arr, t_temp_value tmp);
void	ft_rrb(t_array_value *arr, t_temp_value tmp);
void	ft_pa(t_array_value *arr, t_temp_value tmp);
void	ft_pb(t_array_value *arr, t_temp_value tmp);
void	ft_error(t_array_value *arr);
void	three_param(t_array_value *arr, t_temp_value tmp, int n);

#endif
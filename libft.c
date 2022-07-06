/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:54:54 by ebudak            #+#    #+#             */
/*   Updated: 2022/07/03 19:56:19 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_array_value *arr)
{
	int		neg_value;
	int		i;
	long	value;

	i = 0;
	neg_value = 1;
	value = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg_value *= -1;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			value = value * 10 + (str[i++] - 48);
			if ((value * neg_value) < -2147483648
				|| (value * neg_value) > 2147483647)
				ft_error(arr);
		}
		else
			ft_error(arr);
	}
	return (value * neg_value);
}

size_t	w_l(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

size_t	w_c(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;
	size_t	l;
	size_t	w_i;

	if (!s)
		return (NULL);
	l = w_c(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		while (*s == c && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * w_l(s, c) + 1);
		w_i = 0;
		while (*s != c && *s != '\0')
			r[i][w_i++] = *s++;
		r[i][w_i] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}

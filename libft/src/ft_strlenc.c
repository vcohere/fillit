/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:55:59 by vcohere           #+#    #+#             */
/*   Updated: 2016/02/16 18:57:24 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_strlenc(const char *s, char c)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			res++;
		i++;
	}
	return (res);
}

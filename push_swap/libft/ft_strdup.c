/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:16:10 by mda-silv          #+#    #+#             */
/*   Updated: 2021/02/19 12:13:41 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*dup;

	count = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[count])
	{
		dup[count] = s1[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   natural.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:08:37 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:05:54 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_create_natural(const char *pattern, size_t start,
															size_t stop)
{
	t_regexp_natural	*natural;
	t_regexp_elem		*element;

	printf("ft_regexp_create_natural %s %zu %zu \n", pattern, start, stop);
	natural = (t_regexp_natural *)ft_calloc(1, sizeof(t_regexp_natural));
	if (!natural)
		return (0);
	natural->start = start;
	natural->stop = stop;
	natural->pattern = pattern;
	element = ft_regexp_create_element("natural", natural);
	if (!element)
		ft_regexp_delete_void((void *)natural);
	else
		element->destructor = ft_regexp_delete_natural;
	return (element);
}

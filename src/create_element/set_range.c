/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:30:04 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 07:23:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_set_range;
	element->check = ft_regexp_check_set_range;
	element->process = ft_regexp_process_set_range;
}

t_regexp_elem	*ft_regexp_create_set_range(const char from, const char to)
{
	t_regexp_set_range	*set_range;
	t_regexp_elem		*element;

	// printf("ft_regexp_create_set_range\n");
	if (from > to)
		return (ft_regexp_create_void());
	set_range = (t_regexp_set_range *)ft_calloc(1, sizeof(t_regexp_set_range));
	if (!set_range)
		return (0);
	set_range->from = from;
	set_range->to = to;
	element = ft_regexp_create_element("set_range", set_range);
	if (!element)
		ft_regexp_delete_set_range(set_range);
	else
		ft_init_metods(element);
	// printf("ft_regexp_create_set_range finish\n");
	return (element);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:19:13 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 16:01:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_range;
	element->check = ft_regexp_check_range;
	element->process = ft_regexp_process_range;
}

t_regexp_elem	*ft_regexp_create_range(t_regexp_elem *elem, size_t min,
															size_t max)
{
	t_regexp_range	*range;
	t_regexp_elem	*element;

	range = (t_regexp_range *)ft_calloc(1, sizeof(t_regexp_range));
	if (!range)
	{
		ft_regexp_delete_element(elem);
		return (0);
	}
	range->min = min;
	range->max = max;
	range->elem = elem;
	element = ft_regexp_create_element("range", range);
	if (!element)
		ft_regexp_delete_range(range);
	else
		ft_init_metods(element);
	return (element);
}

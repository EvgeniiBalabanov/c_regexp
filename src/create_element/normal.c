/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:20:38 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:39:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_normal;
	element->check = ft_regexp_check_normal;
	element->process = ft_regexp_process_normal;
}

t_regexp_elem	*ft_regexp_create_normal(const char *string, size_t start, size_t stop)
{
	t_regexp_normal	*normal;
	t_regexp_elem	*element;

	if (stop == start)
		return (ft_regexp_create_void());
	normal = (t_regexp_normal *)ft_calloc(1, sizeof(t_regexp_normal));
	if (!normal)
		return (0);
	normal->string = ft_substr(string, start, stop - start);
	if (!normal->string)
	{
		free(normal);
		return (0);
	}
	element = ft_regexp_create_element("normal", normal);
	if (!element)
		ft_regexp_delete_normal(normal);
	else
		ft_init_metods(element);
	return (element);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:31:30 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 10:19:50 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_any;
	element->check = ft_regexp_check_any;
	element->process = ft_regexp_process_any;
}

t_regexp_elem	*ft_regexp_create_any(void)
{
	t_regexp_any	*any;
	t_regexp_elem	*element;

	any = (t_regexp_any *)ft_calloc(1, sizeof(t_regexp_any));
	if (!any)
		return (0);
	element = ft_regexp_create_element("any", any);
	if (!element)
		ft_regexp_delete_any(any);
	else
		ft_init_metods(element);
	return (element);
}

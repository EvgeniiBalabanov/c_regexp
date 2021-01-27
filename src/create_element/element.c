/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:15:31 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 07:13:41 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_create_element(char *type, void *content)
{
	t_regexp_elem *element;

	element = (t_regexp_elem *)ft_calloc(1, sizeof(t_regexp_elem));
	if (element)
	{
		element->type = type;
		element->content = content;
	}
	return (element);
}

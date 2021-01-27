/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:12:37 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:01:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_element(t_regexp_elem *element)
{
	if (element)
	{
		((void (*)(void *))element->destructor)(element->content);
		free(element);
	}
}

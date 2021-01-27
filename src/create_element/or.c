/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:57:22 by telron            #+#    #+#             */
/*   Updated: 2021/01/27 14:51:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_or;
	element->check = ft_regexp_check_or;
	element->process = ft_regexp_process_or;
}

t_regexp_elem	*ft_regexp_create_or(t_regexp_elem *left, t_regexp_elem *right)
{
	t_regexp_or		*or;
	t_regexp_elem	*element;

	or = (t_regexp_or *)ft_calloc(1, sizeof(t_regexp_or));
	if (!or)
	{
		ft_regexp_delete_element(left);
		ft_regexp_delete_element(right);
		return (0);
	}
	or->left = left;
	or->right = right;
	element = ft_regexp_create_element("or", or);
	if (!element)
		ft_regexp_delete_or(or);
	else
		ft_init_metods(element);
	return (element);
}

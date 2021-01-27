/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:18:29 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 09:26:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_void;
	element->check = ft_regexp_check_void;
	element->process = ft_regexp_process_void;
}

t_regexp_elem	*ft_regexp_create_void(void)
{
	t_regexp_void	*void_struct;
	t_regexp_elem	*element;

	ft_putstr_fd("Warning! struct pattern have void element!\n", 2);
	void_struct = (t_regexp_void *)ft_calloc(1, sizeof(t_regexp_void));
	if (!void_struct)
		return (0);
	element = ft_regexp_create_element("void", void_struct);
	if (!element)
		ft_regexp_delete_void(void_struct);
	else
		ft_init_metods(element);
	return (element);
}

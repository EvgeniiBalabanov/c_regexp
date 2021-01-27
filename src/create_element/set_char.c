/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_сhar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 07:46:56 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_set_char;
	element->check = ft_regexp_check_set_char;
	element->process = ft_regexp_process_set_char;
}

t_regexp_elem	*ft_regexp_create_set_char(const char *chars)
{
	t_regexp_set_chars	*set_char;
	t_regexp_elem	*element;

	if (!chars[0])
		return (ft_regexp_create_void());
	set_char = (t_regexp_set_chars *)ft_calloc(1, sizeof(t_regexp_set_chars));
	if (!set_char)
		return (0);
	set_char->chars = ft_strdup(chars);
	if (!set_char->chars)
	{
		free(set_char);
		return (0);
	}
	element = ft_regexp_create_element("set_char", set_char);
	if (!element)
		ft_regexp_delete_set_char(set_char);
	else
		ft_init_metods(element);
	return (element);
}

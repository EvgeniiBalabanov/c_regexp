/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:28:48 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:35:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void	ft_put_elements(size_t index, void *element)
{
	if (index)
		ft_putstr_fd(", ", 1);
	ft_regexp_check_element((t_regexp_elem *)element);
}

void		ft_regexp_check_set(t_regexp_set *set)
{
	ft_putstr_fd("set(", 1);
	ft_regexp_check_element(set->set_сhars);
	ft_putstr_fd(", ", 1);
	ft_lstiteri(set->l_set_range, ft_put_elements);
	ft_putstr_fd(")", 1);
}

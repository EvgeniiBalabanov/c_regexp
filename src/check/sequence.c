/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:28:11 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 07:28:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void	ft_put_elements(size_t index, void *element)
{
	if (index)
		ft_putstr_fd(", ", 1);
	ft_regexp_check_element((t_regexp_elem *)element);
}

void		ft_regexp_check_sequence(t_regexp_sequence *sequence)
{
	ft_putstr_fd("sequence(", 1);
	ft_dlstiteri(sequence->l_elems, ft_put_elements);
	ft_putstr_fd(")", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:25:16 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:03:32 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_sequence(t_regexp_sequence *sequence)
{
	if (sequence)
	{
		ft_dlstclear(&sequence->l_elems, (void (*)(void *))ft_regexp_delete_element);
		free(sequence);
	}
}

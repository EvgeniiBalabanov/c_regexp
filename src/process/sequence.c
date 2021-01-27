/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:13:08 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 04:32:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_sequence(t_regexp_sequence *sequence,\
										t_process *process)
{
	t_dlist	*dlst;

	dlst = sequence->l_elems;
	while (dlst)
	{
		if (!ft_regexp_process_element(dlst->content, process))
			return (0);
		dlst = dlst->right;
	}
	return (process);
}

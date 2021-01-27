/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:17:01 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 06:07:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_element(t_regexp_elem *elem, t_process *process)
{
	// printf("\nft_regexp_process_element\n%s\n%s\n", elem->type, process->string + process->start);
	return ((t_process *(*)(void *, t_process *))elem->process)(elem->content, process);
}

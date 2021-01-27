/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:23:11 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:04:23 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_void(t_regexp_void *void_struct)
{
	if (void_struct)
		free(void_struct);
}

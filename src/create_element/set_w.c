/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:29:50 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 15:15:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_create_set_w(void)
{
	t_list			*lst;
	t_regexp_elem	*set_az;
	t_regexp_elem	*set_AZ;
	t_regexp_elem	*set_digit;
	t_regexp_elem	*set_char;

	lst = 0;
	set_az = 0;
	set_AZ = 0;
	set_digit = 0;
	// if ((set_char = ft_regexp_create_set_char("_")))
	// 	if ((set_az = ft_regexp_create_set_range('a', 'z')))
	// 		if ((set_AZ = ft_regexp_create_set_range('A', 'Z')))
	// 			if ((set_digit = ft_regexp_create_set_range_digit()))
	// 				if (ft_lstadd_back_content(&lst, set_az))
	// 					if (ft_lstadd_back_content(&lst, set_AZ))
	// 						if (ft_lstadd_back_content(&lst, set_digit))
	// 						{
								
	// 						}
	if (!(set_char = ft_regexp_create_set_char("_")) ||\
		!(set_az = ft_regexp_create_set_range('a', 'z')) ||\
		!(set_AZ = ft_regexp_create_set_range('A', 'Z')) ||\
		!(set_digit = ft_regexp_create_set_range_digit()) ||\
		!ft_lstadd_back_content(&lst, set_az) ||\
		!ft_lstadd_back_content(&lst, set_AZ) ||\
		!ft_lstadd_back_content(&lst, set_digit))
	{
		ft_lstclear(&lst, 0);
		ft_regexp_delete_element(set_char);
		ft_regexp_delete_element(set_az);
		ft_regexp_delete_element(set_AZ);
		ft_regexp_delete_element(set_digit);
		return (0);
	}
	return (ft_regexp_create_set(set_char, lst));
}
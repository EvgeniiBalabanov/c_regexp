/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regexp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:38:02 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 16:24:22 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEXP_H
# define REGEXP_H

# include <stddef.h>
#include <stdio.h>
# include "libft.h"
# include "list.h"
# include "dlist.h"

typedef struct		s_regexp_elem
{
	char			*type;
	void			*content;
	void			*destructor;
	void			*check;
	void			*process;
}					t_regexp_elem;

typedef struct		s_regexp_segment
{
	size_t			index;
	size_t			start;
	size_t			stop;
}					t_regexp_segment;

typedef struct		s_process
{
	char			*string;
	size_t			start;
	size_t			stop;
	t_list			*l_segment;
}					t_process;

typedef struct		s_regexp_natural
{
	const char		*pattern;
	size_t			start;
	size_t			stop;
}					t_regexp_natural;

typedef struct		s_regexp_group
{
	t_regexp_elem	*elem;
	size_t			index;
}					t_regexp_group;

typedef struct		s_regexp_void
{
}					t_regexp_void;

typedef struct		s_regexp_normal
{
	char			*string;
}					t_regexp_normal;

typedef struct		s_regexp_set_range
{
	char			from;
	char			to;
}					t_regexp_set_range;

typedef struct		s_regexp_set_chars
{
	char			*chars;
}					t_regexp_set_chars;

typedef struct		s_regexp_set
{
	t_regexp_elem	*set_сhars;
	t_list			*l_set_range;
}					t_regexp_set;

typedef struct		s_regexp_any
{
}					t_regexp_any;

typedef struct		s_regexp_start
{
}					t_regexp_start;

typedef struct		s_regexp_end
{
}					t_regexp_end;

typedef struct		s_regexp_range
{
	t_regexp_elem	*elem;
	size_t			min;
	size_t			max;
}					t_regexp_range;

typedef struct		s_regexp_or
{
	t_regexp_elem	*left;
	t_regexp_elem	*right;
}					t_regexp_or;

typedef struct		s_regexp_sequence
{
	t_dlist			*l_elems;
}					t_regexp_sequence;

// typedef struct		s_regexp
// {
// 	t_regexp_elem	**elems;
// 	size_t			count;
// }					t_regexp;

t_process			*ft_regexp_parse(const char *pattern, const char *string);

t_regexp_elem		*ft_regexp_parse_other(t_dlist *dlist);
t_regexp_elem		*ft_regexp_parse_or(t_dlist **dlist);
t_regexp_elem		*ft_regexp_parse_group(t_regexp_elem *base, size_t *index_group);
int					ft_regexp_parse_delete_guard(t_dlist **build);
int					ft_regexp_parse_iter_natural(t_dlist **build,\
					int (*func)(t_dlist **dlist, t_regexp_natural *natural));
int					ft_regexp_parse_sd_d_sp_ss_m(t_dlist **build,\
											t_regexp_natural *natural);

t_regexp_elem		*ft_regexp_create_element(char *type, void *content);
void				ft_regexp_delete_element(t_regexp_elem *element);
void				ft_regexp_check_element(t_regexp_elem *elem);
t_process			*ft_regexp_process_element(t_regexp_elem *elem,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_normal(const char *string, size_t start,\
											size_t stop);
void				ft_regexp_delete_normal(t_regexp_normal *normal);
void				ft_regexp_check_normal(t_regexp_normal *normal);
t_process			*ft_regexp_process_normal(t_regexp_normal *normal,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_range(t_regexp_elem *elem, size_t min,
											size_t max);
void				ft_regexp_delete_range(t_regexp_range *range);
void				ft_regexp_check_range(t_regexp_range *range);
t_process			*ft_regexp_process_range(t_regexp_range *range,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_or(t_regexp_elem *left,\
											t_regexp_elem *right);
void				ft_regexp_check_or(t_regexp_or *or);
void				ft_regexp_delete_or(t_regexp_or *or);
t_process			*ft_regexp_process_or(t_regexp_or *or, t_process *process);

t_regexp_elem		*ft_regexp_create_sequence(t_dlist *l_elems);
void				ft_regexp_delete_sequence(t_regexp_sequence *sequence);
void				ft_regexp_check_sequence(t_regexp_sequence *sequence);
t_process			*ft_regexp_process_sequence(t_regexp_sequence *sequence,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_group(t_regexp_elem *elem, size_t index_group);
void				ft_regexp_delete_group(t_regexp_group *group);
void				ft_regexp_check_group(t_regexp_group *group);
t_process			*ft_regexp_process_group(t_regexp_group *group,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_void(void);
void				ft_regexp_delete_void(t_regexp_void *void_struct);
void				ft_regexp_check_void(t_regexp_void *void_struct);
t_process			*ft_regexp_process_void(t_regexp_void *void_scruct,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_any(void);
void				ft_regexp_delete_any(t_regexp_any *any);
void				ft_regexp_check_any(t_regexp_any *any);
t_process			*ft_regexp_process_any(t_regexp_any *any,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_set_char(const char *chars);
void				ft_regexp_delete_set_char(t_regexp_set_chars *set_char);
void				ft_regexp_check_set_char(t_regexp_set_chars *set_char);
t_process			*ft_regexp_process_set_char(t_regexp_set_chars *set_char,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_set_range(const char from, const char to);
void				ft_regexp_delete_set_range(t_regexp_set_range *set_range);
void				ft_regexp_check_set_range(t_regexp_set_range *set_range);
t_process			*ft_regexp_process_set_range(t_regexp_set_range *set_range,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_set(t_regexp_elem *elem_set_chars,\
											t_list *l_set_range);
void				ft_regexp_delete_set(t_regexp_set *set);
void				ft_regexp_check_set(t_regexp_set *set);
t_process			*ft_regexp_process_set(t_regexp_set *set,\
											t_process *process);

t_regexp_elem		*ft_regexp_create_natural(const char *string, size_t start, size_t stop);
void				ft_regexp_delete_natural(t_regexp_natural *natural);

t_regexp_elem		*ft_regexp_create_zero_or_more(t_regexp_elem *element);

t_regexp_elem		*ft_regexp_create_one_or_more(t_regexp_elem *element);

t_regexp_elem		*ft_regexp_create_set_range_digit(void);

t_regexp_elem		*ft_regexp_create_set_w(void);

#endif
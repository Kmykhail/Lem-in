/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# define CHR ft_strchr
# define STRSTR ft_strstr
# define LNE	lem->line
# define CMP ft_strcmp
# define ERROR	lem->error
# define MAX_ROOM 2147483647
# define MAX_ANT 2147483647
# define MA_ANT 214748364
# define ROOMS	lem->rooms
# define ARR	arr[0][0]
# define STR	lem->str
# define END	lem->end
# define ST_END	lem->st_end_r
# define ANT_1	"L%d-%s", i + 1, tmp->nm_c
# define ANT_NEXT " L%d-%s", i + 1, tmp->nm_c
# define COORS	lem->coors
# define ITR	lem->itr
# define RM		lem->help_rm
# define F		lem->help_f
# define R_VAL	lem->r_val
# define CC		lem->help_c
# define CNT	lem->count

typedef struct				s_lem
{
	int						skip;
	char					*line;
	int						ires;
	int						st_end_r;
	int						s_ant;
	int						coor_st_r;
	int						coor_end_r;
	char					**rooms;
	int						*coors;
	char					*stor;
	char					**sml;
	int						error;
	int						str;
	int						end;
	int						itr;
	int						step;
	int						stop;
	int						indx;
	int						help_f;
	int						help_c;
	int						help_rm;
	int						val;
	int						count;
	int						r_val;
}							t_lem;

typedef struct				s_r
{
	char					*nm_c;
	int						cr_y;
	int						cr_x;
	int						str;
	int						end;
	int						num;
	int						ant;
	int						mark;
	int						dist;
	char					*link;
	char					**lnk;
	struct s_r				**qw;
	struct s_r				*next;
}							t_room;

typedef struct				s_lst
{
	char					*str;
	int						fd;
	struct s_lst			*next;
}							t_lst;

int							ft_valid(t_lem *lem, t_room *room);
void						ft_free_double(char **arr, int size);
void						ft_realloc(char **src, char **line, int cnt, int k);
int							ft_check_case(t_lem *lem, t_room *room, int i);
int							ft_dig_all(char *line);
int							ft_analyze_error(t_room *room, t_lem *lem);
int							ft_parse_algo(t_lem *lem, t_room *r, int i);
void						ft_sort_room_str(t_room **room);
void						ft_sort_room_end(t_room **room);
int							ft_move_ants(t_room *room, t_room *new, t_lem *lem);
int							ft_short_way(t_room *new, int f, int ***a_ant);
int							ft_empty_room(int **a_ant, t_room *new);
int							ft_analyze_data(t_room *r, t_lem *lem, int status);
int							ft_anlyze_lne(char *s);
int							ft_fake_room(t_lem *lem, char **f, int nm, int i);
int							ft_check_room(char **arr, t_lem *lem);
void						ft_sort_ants(int ***arrant, int size);
void						ft_free_ant(int ***arrant);
void						ft_free_room(t_room **room);
void						ft_write_num(t_room **room);
void						ft_realloc_coor(t_lem *l, char **a, int i, int c);
int							get_next_line_q(const int fd, char **line);
int							ft_same_pipe(t_lem *lem);
int							ft_ant_instart(int **arrant);
int							ft_check_room(char **arr, t_lem *lem);
int							ft_check_ants(char *line, t_lem *lem);
int							ft_helper_check_case(t_room *r, t_lem *l, char **a);
void						ft_helper_algo_2(t_room *r, t_room *n, t_lem *l);
void						ft_helper_parse_algo_1(t_room *r, int *i, int *ch);
void						ft_realloc_coor(t_lem *l, char **arr, int i, int c);
void						ft_canmove(t_room *n, int ***a, int f, int rm);
int							ft_canmove_1(t_room *n, t_lem *l, int ***a, int s);
void						ft_canmove_2(t_room *n, t_lem *l, int *v, int ***a);
void						ft_choose_way(t_room *room, t_lem *lem);
void						ft_init_room(t_room *room, t_lem *lem, char **arr);
void						ft_helper_check_sml(t_lem *lem, int i, int c);
void						ft_help_check_rm(t_lem *l, char **a, int c, int i);
int							ft_fake_room(t_lem *lem, char **f, int nm, int i);
t_room						*ft_newroom(char **a, int size, int st_end, int n);
void						ft_helper_print_res(int ***ant, int i, int end);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:05:01 by kmykhail          #+#    #+#             */
/*   Updated: 2018/01/27 18:24:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <locale.h>

# define MINUS		ft_strchr(pr->str_flag, '-')
# define PLUS		ft_strchr(pr->str_flag, '+')
# define SP			ft_strchr(pr->str_flag, ' ')
# define ZR			ft_strchr(pr->str_flag, '0')
# define SRP		ft_strchr(pr->str_flag, '#')
# define T_D		((*str)[cnt] == 'd' || (*str)[cnt] == 'D')
# define T_U		((*str)[cnt] == 'u' || (*str)[cnt] == 'U')
# define T_O		((*str)[cnt] == 'o' || (*str)[cnt] == 'O')
# define T_X		((*str)[cnt] == 'x' || (*str)[cnt] == 'X')
# define T_S		((*str)[cnt] == 's' || (*str)[cnt] == 'S')
# define T_C		((*str)[cnt] == 'c' || (*str)[cnt] == 'C')
# define T_X_SRC	(ft_strchr(pr->src_t, 'x') || ft_strchr(pr->src_t, 'X'))
# define T_2_3		(type != 2 && type != 3)
# define Z			((*str)[cnt - 1] == 'Z' && cnt != 0)
# define P			ft_itoa_base(((uint64_t)va_arg(ap, void*)), 16)
# define L_D		ft_itoa_an((int)va_arg(ap, void*))
# define Z_X		ft_itoa_base(((size_t) va_arg(ap, void*)), 16)
# define J_X		ft_itoa_base(((intmax_t)va_arg(ap, void*)), 16)
# define HH_X		ft_itoa_base(((unsigned char)va_arg(ap, void*)), 16)
# define H_X		ft_itoa_base(((unsigned short)va_arg(ap, void*)), 16)
# define LL_X		ft_itoa_base(((uint64_t)va_arg(ap, void*)), 16)
# define Z_D		ft_itoa_an((ptrdiff_t)va_arg(ap, void*))
# define J_D		ft_itoa_an((intmax_t)va_arg(ap, void*))
# define Z_U		ft_itoa_ui((size_t)va_arg(ap, void*))
# define Z_O		(ft_itoa_base(((size_t)va_arg(ap, void*)), 8))
# define J_U		ft_itoa_ui((uint64_t)va_arg(ap, void*))
# define LL_U		ft_itoa_ui((uint64_t) va_arg(ap, void*))
# define LL_O		ft_itoa_base(((uint64_t)va_arg(ap, void*)), 8)
# define J_O		(ft_itoa_base(((uintmax_t)va_arg(ap, void*)), 8))
# define HH_D		ft_itoa_an((char)va_arg(ap, void*))
# define HH_U		ft_itoa_ui((unsigned char)va_arg(ap, void*))
# define HH_O		(ft_itoa_base(((unsigned char)va_arg(ap, void*)), 8))
# define H_D		ft_itoa_an((short)va_arg(ap, void*))
# define H_U		ft_itoa_ui((unsigned short)va_arg(ap, void*))
# define H_O		(ft_itoa_base(((unsigned short)va_arg(ap, void*)), 8))
# define U		ft_strchr(pr->src_t, 'U')
# define O		ft_strchr(pr->src_t, 'O')
# define D		ft_strchr(pr->src_t, 'D')
# define S		ft_strchr(pr->src_t, 'S')
# define SRC_L	ft_strchr(pr->src_t, 'l')
# define MINUS	ft_strchr(pr->str_flag, '-')
# define PLUS	ft_strchr(pr->str_flag, '+')
# define SP		ft_strchr(pr->str_flag, ' ')
# define ZR		ft_strchr(pr->str_flag, '0')
# define SRP	ft_strchr(pr->str_flag, '#')
# define NO_H	ft_strchr(pr->st_arg, 'h')
# define NO_L	ft_strchr(pr->st_arg, 'l')
# define NO_Z	ft_strchr(pr->st_arg, 'z')
# define NO_J	ft_strchr(pr->st_arg, 'j')
# define YES_Z	ft_strchr(pr->st_arg, 'Z')
# define STAR	ft_atoi_ll(ft_strchr(pr->src_t, '*') + 1)
# define PREC	ft_atoi_ll(ft_strchr(pr->src_t, '.') + 1)
# define FLAG	(ft_isdigit(pr->src_t[i - 1]) && pr->src_t[i - 1] != '0')
# define SRC_T	(pr->src_t[i - 1] == '.')
# define CH_MOD	ft_check_mod
# define LEN_ARG	ft_strlen_my(pr->st_arg)
# define LEN_RES ft_strlen_my(pr->result)
# define NO_SRC	ft_strchr(pr->src_t, '.')
# define RES_0 ft_strchr(pr->result, '0')
# define ARG_MIN ft_strchr(pr->st_arg, '-')
# define W_LESS_P width < precis
# define W_LESS_Q_P width <= precis
# define W_MORE_P width > precis
# define W_MORE_Q_P width >+ precis
# define RES_A		pr->result[a] == ' ' && pr->result[a + 1] != ' '
# define RES_CNT pr->result[pr->cnt] == ' ' && pr->result[pr->cnt + 1] != ' '
# define RES_A_OR	pr->result[a] == ' ' || pr->result[a] == '-'
# define JOIN		ft_strjoin_no_liks
# define RES1		pr->result[1] = 'x'
# define RES2		pr->result[1] = 'X'
# define CONVERT		ft_convert_result_flags
# define RES_SP		ft_strchr(pr->result, ' ')
# define JUST_MIN MINUS && !PLUS && !SP && !ZR && !SRP
# define JUST_ZR		!MINUS && !PLUS && !SP && ZR && !SRP
# define JUST_PLUS		!MINUS && PLUS && !SP && !ZR && !SRP
# define JUST_SP		!MINUS && !PLUS && SP && !ZR && !SRP
# define JUST_SRP		!MINUS && !PLUS && !SP && !ZR && SRP
# define PLUS_SP		!MINUS && PLUS && SP && !ZR && !SRP
# define PLUS_ZR		!MINUS && PLUS && !SP && ZR && !SRP
# define SP_ZR			!MINUS && !PLUS && SP && ZR && !SRP
# define ZR_SRP			!MINUS && !PLUS && !SP && ZR && SRP
# define MIN_ZR			MINUS && !PLUS && !SP && ZR && !SRP
# define MIN_PLUS		MINUS && PLUS && !SP && !ZR && !SRP
# define MIN_SP			MINUS && !PLUS && SP && !ZR && !SRP
# define MIN_SRP		MINUS && !PLUS && !SP && !ZR && SRP
# define MIN_PLUS_ZR	MINUS && PLUS && !SP && ZR && !SRP
# define ALL_FLAG_ON	MINUS && PLUS && SP && ZR && SRP
# define SP_ZR_STAR	!MINUS && !PLUS && SP && ZR && !SRP && STRCHR_STAR
# define ZR_STAR		!MINUS && !PLUS && !SP && ZR && !SRP && STRCHR_STAR
# define MIN_ZR_SRP	MINUS && !PLUS && !SP && ZR && SRP
# define CHECK_STR	ft_pre_check_str

typedef struct		s_print
{
	unsigned int	utf;
	int				b;
	int				star;
	int				prec;
	int				sp;
	int				byte_add;
	int				cnt;
	char			sym;
	char			*buff;
	char			*result;
	char			*str_flag;
	char			*src_t;
	char			*st_arg;
	int				*wchar;
	int				cp_star;
	int				ch_star;
	int				it;
	int				type;
	size_t			ct;
	ptrdiff_t		len;
}					t_print;

typedef struct		s_utf
{
	unsigned char	add1;
	unsigned char	add2;
	unsigned char	add3;
	unsigned char	add4;
	unsigned char	res_char;
	unsigned char	uf_mass[4];
	uint64_t		mask1;
	uint64_t		mask2;
	uint64_t		mask3;
	uint32_t		cp_utf;
}					t_utf;

char				*ft_itoa_an(ptrdiff_t nbr);
char				*ft_strdup_pr(const char *s1);
char				*ft_itoa_ui(size_t n);
char				*ft_itoa_base(size_t value, int base);
void				ft_convert_result_flags(t_print	*pr, int i, int c, int ch);
ptrdiff_t			ft_atoi_ll(const char *str);
int					ft_check_mod(t_print *pr, va_list ap, int t, int i);
int					ft_printf(const char *format, ...);
int					ft_check_flags(t_print *pr);
int					ft_check_flags_helper(t_print *pr, int cnt, int n, int i);
int					ft_flags(int c);
int					ft_len_byte(int *nb);
int					len_binary(int nb);
int					ft_utf(t_print *pr, t_utf *uf);
int					ft_number(t_print *pr);
int					ft_analys_str(t_print *pr, int i, int a, t_utf *uf);
void				ft_convert_result_flags(t_print	*pr, int i, int c, int ch);
void				ft_only_precision_str(t_print *pr);
void				ft_del_concrete_sym(char **arr, char sym);
void				ft_width_precision_str(t_print *pr);
void				ft_width_precision(t_print *pr, int type, va_list ap);
void				ft_un_behavior(t_print *pr, int type);
void				ft_char(t_print *pr, va_list ap, int type, int i);
void				ft_digit(t_print *pr, va_list ap, int type);
void				ft_count_len(int *c, t_print *pr);
void				ft_del_flags(t_print *pr, int type);
void				ft_del_flags_helper(t_print *pr, int t, char **b, int i);
void				ft_w_p_star(t_print *pr, va_list ap, ptrdiff_t *w,\
ptrdiff_t *p);
void				ft_w_p_same(t_print *pr, size_t i);
void				ft_w_p_1(t_print *pr, ptrdiff_t w, ptrdiff_t p, int type);
void				ft_w_p_2(t_print *pr, ptrdiff_t precis, ptrdiff_t len,\
int type);
void				ft_check_width_precision(t_print *pr, int type, va_list ap);
void				ft_check_mod_1(t_print *pr, va_list ap, int type, int i);
void				ft_check_mod_2(t_print *pr, va_list ap, int type, int i);
void				ft_check_mod_3(t_print *pr, va_list ap, int type, int i);
void				ft_check_flags_char(t_print *pr, int type);
int					ft_check_mod_4(t_print *pr, va_list ap, int type, int c);
void				ft_only_width_str(t_print *pr, int i);
void				ft_only_prec_str_1(t_print *pr, ptrdiff_t l, ptrdiff_t p,\
int *arr);
void				ft_width_char(t_print *pr);
void				ft_check_flags_char(t_print *pr, int type);
int					ft_analys_str(t_print *pr, int i, int a, t_utf *uf);
void				ft_print_ascii(t_print *pr);
void				ft_strjoin_no_liks(char	*s1, t_print *pr);
void				ft_fl_plus_1(t_print *pr, int ch, ptrdiff_t w, ptrdiff_t p);
void				ft_add_flags_to_result(t_print *pr, int type);
void				ft_only_width(t_print *pr);
void				ft_pointer(t_print *pr, va_list ap, int type);
void				ft_only_precision(t_print *pr, int type, int i, int c);
void				ft_fl_zr(t_print *pr, ptrdiff_t width, ptrdiff_t precis,\
int ch);
void				ft_fl_srp_1(t_print *pr, ptrdiff_t width, ptrdiff_t precis,\
int ch);
void				ft_sp_zr(t_print *pr, ptrdiff_t width, ptrdiff_t precis,\
int ch);
void				ft_fl_minus_2(t_print *pr, char **arr, int len, int ch);
void				ft_init_char(t_print *pr, va_list ap, int type);
void				ft_fl_srp_2(t_print *pr, size_t a);
void				ft_w_p_3(t_print *pr, char **buff, ptrdiff_t l,\
ptrdiff_t p);
void				ft_fl_pl(t_print *pr, char **arr, ptrdiff_t len, int ch);
void				ft_only_width_1(t_print *pr, ptrdiff_t w, ptrdiff_t l,\
char **arr);
int					ft_utf(t_print *pr, t_utf *uf);
int					ft_last_check_str(t_print *pr, char *s, int *n, int type);
int					ft_no_type (t_print *pr);
int					ft_len_zero(t_print *pr);
int					ft_len_byte(int *nb);
int					len_binary(int nb);
int					ft_check_flags_1(t_print *pr);
int					ft_len_zero(t_print *pr);
int					ft_variant_str(char **str, va_list ap, int *c,\
t_print *pr);
int					ft_variant_nb(char **str, va_list ap, int *c, t_print *pr);
int					ft_variant_text(char **str, size_t cnt, int *c,\
t_print *pr);
int					ft_print_text(char **str, t_print *pr, int *c);
int					ft_pre_check_str(char *str, int *c, t_print *pr);
int					ft_what_precis(t_print *pr, int c);

#endif

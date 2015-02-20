/*
** my.h for my_lib in /home/geiger_a/lib/lib/my/include
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 18:31:36 2015 anthony geiger
** Last update Tue Jan 13 11:12:57 2015 Anthony Geiger
*/

#ifndef MY_H_
# define MY_H_
# include <stdarg.h>
# include <stdlib.h>

/*
** ======================
** Repository : src/str
** ======================
*/

int	my_strcmp(char *a, char *b);
int	my_strlen(char *str);
char    *my_strcpy(char *dest, char *src);
char    *my_strdup(char *src);
char    *get_next_line(const int fd);
char    **my_spe_in_tab(char *str, char sep);
int	my_strncmp(char *a, char *b, int nb);
void	my_putnstr(char *str, int nb);
char    *my_strndup(char *src, int nb);
char    *my_strncpy(char *dest, char *src, int nb);
char    *my_strnsdup(char *src, int nb);
char    *my_strnscpy(char *dest, char *src, int nb);
void    remove_str_in_tab(char **tab, int x);
int	my_tablen(char **tab);
int	my_strglen(long *a);
char            *my_strconcat(char *s1, char *s2);

/*
** ======================
** File : my_printf.h
** ======================
*/

typedef struct		s_index
{
  int			i;
  int			n;
  int			nb;
  int			r;
  int			res;
  int			p;
  int			nbr;
}			t_index;

typedef	struct		s_struc
{
  char			c;
  int			(*ptr_tab)(void *argv, t_index *s,
				   const char *format, const struct s_struc *tab);
}			t_struc;

int		        my_printf(const char *format, ...);
void			my_putchar(char c);
int			my_putstr(char *str);
int			my_putnbr(int nb);
int			my_unputnbr(unsigned int nb);
int			my_strlen(char *str);
int			my_rev_int_tab_long(char *tab, long i);
void			my_rev_int_tab_un(char *tab, long i);
void			my_rev_int_tab(int *tab, int i);
void			my_rev_unint_tab(unsigned int *tab, int i);
void			my_rev_caract_nimpr(int *tab, int i);
int			my_nb_stack(char n);
int			convert_base_deci_2(int nb);
int			convert_base_deci_octal(char strnb, char *str);
int			convert_base_deci_8_unint(unsigned int nb);
int			convert_base_deci_16_un(unsigned int nb, char *str);
int			convert_base_deci_16(long nb, char *str);
int			s_putstr(void *argv, t_index *s, const char *format,
				 const t_struc *tab);
int			case_p(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_x(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_c(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_s(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_b(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_di(void *argv, t_index *s, const char *format,
				const t_struc *tab);
int			case_o(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			x_case(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_u(void *argv, t_index *s,
			       const char *format, const t_struc *tab);
int			case_pres(void *argv, t_index *s, const char *format,
				  const t_struc *tab);
int			case_sharp(void *argv, t_index *s,
				   const char *format, const t_struc *tab);
int			my_strlen(char *str);
int			my_rev_int_tab_long(char *tab, long i);
void			my_rev_int_tab_un(char *tab, long i);
void			my_rev_int_tab(int *tab, int i);
void			my_rev_unint_tab(unsigned int *tab, int i);
void			my_rev_caract_nimpr(int *tab, int i);
int			my_nb_stack(char n);
int			convert_base_deci_2(int nb);
int			convert_base_deci_octal(char strnb, char *str);
int			convert_base_deci_8_unint(unsigned int nb);
int			convert_base_deci_16_un(unsigned int nb, char *str);
int			convert_base_deci_16(long nb, char *str);
int			case_sharp2(t_index *s, const char *format, int i,
				    const t_struc *tab);
int			case_zero(void *argv, t_index *s, const char *format,
				  const t_struc *tab);
int			my_putnbrnoaffich(int nb);
int			my_putnbrs(int nb, int p, int nbr);
int			my_unputnbrnoaffich(unsigned int nb);
int			my_unputnbrs(unsigned int nb, int p, int nbr);
int			case_l(void *argv, t_index *s, const char *format,
			       const t_struc *tab);
int			my_lunputnbr(long unsigned int nb);
int			my_lputnbr(long int nb);
int                     convert_base_deci_16_lun(long unsigned int nb,
						 char *str);
void			my_rev_lunint_tab(long unsigned int *tab, int i);
int                     convert_base_deci_8_lunint(long unsigned int nb);

/*
** ======================
** File : my_word_in_tab.h
** ======================
*/

typedef	struct	s_win
{
  int		i;
  int		nb;
  int		j;
  int		word;
  int		lines;
}		t_win;

char     **my_word_in_tab(char *str);

/*
** ======================
** File : my_word_in_tab.h
** ======================
*/

# define SIZE_OF_READ 1

typedef	struct	s_getline
{
  int		stop;
  int		i;
  int		ret;
  int		s;
  char		*dest;
  char		*buffer;
  int		errgest;
}		t_getline;

char			*get_next_line(const int fd);
char			*getbuffer(char *buffer, char *retbuffer);
char			*stat_in_buff(char *strtbuffer, char *buffer,
				      t_getline *s, char *dest);
void			where_my_buff_end(char *statbuffer,
					  char *stockstat, int j);
void			my_gstrcpy(char *buffer, char *stockstat,
				  t_getline *s, char *dest);


#endif /* !MY_H_ */

/*
** my.h for m in /home/geiger_a/rendu/CPE_2014_Pushswap
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Sat Dec  6 13:23:29 2014 anthony geiger
** Last update Mon Jan 19 13:36:00 2015 Anthony Geiger
*/

#ifndef MYSH_H_
# define MYSH_H_

typedef struct	s_ptrtab
{
  char		*str;
  int           (*ptr_tab)(char **env, char *c);
}		t_ptrtab;

typedef struct	s_alias
{
  char		*name;
  char		*new_name;
}		t_alias;

char		*get_next_line(const int fd);
void	       	my_prompt(char **env);
int		minishell1(char **env, char *c, t_alias **alias);
void		my_aff_env(char **env);
char		**my_add_to_tab(char *name, char **tab);
int		my_unsetenv(char *name, char **env);
void		my_find_pwd(char **env);
int             case_unsetenv(char *c, char **env);
int             case_setenv(char *c);
int		case_exit(char **env, char *c);
int		case_env(char **env, char *c);
int		case_pwd(char **env, char *c);
int             my_envset_fonc(char *c, char **env);
int             ptr_tab_fonc(char *c, char **env, t_alias *alias);
char		**my_realloc_tab_str(char **tab, int size, char *name);
char    **end_of_tab(char **tmp_tab, int i, int x, char *name);
char            *my_strconcat(char *s1, char *s2);
int             my_cd(char **env, char *name);
int             case_cd(char **env, char *c);
int             case_ls(char **env, char *c);
char    *save_pwd(char **env);
int  my_exec_fonc(char *c, char **env, t_alias *alias, int i);
int     child_fonc_ls(char **env, char **argv, int pid);
int             exec_child(char **path, char *exec, char **argv, char **env);
int             child_fonc(char **env, char **argv);
int             my_take_alias(t_alias *alias);
int             my_read_bash(t_alias **alias);
int             loop_main(char *c, int ret, t_alias **alias, char **env);

#endif /* !MYSH_H_ */

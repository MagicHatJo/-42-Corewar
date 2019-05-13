/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 21:00:29 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 15:28:20 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <curses.h>
# include <time.h>
# include "op.h"
# include "err.h"
# include "libft.h"

/*
** Macros
*/

# define MEM(x) (((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE))
# define IDX(x) ((x) % IDX_MOD)

# define ARR -1, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2
# define WAIT_MOD(x) (uint16_t[]){ARR}[(x)]

# define ACB_ARG(x)		((int[]){0, 1, 2, 4}[x])
# define ACB_ARG_1(x)	((int[]){0, 1, 2, 2}[x])
# define REG(r)			((r) > 0 && (r) <= REG_NUMBER)

# define FLASH_LEN		50

# define MAX_DUMP_CYCLES 1000
# define MEM_WIDTH		64
# define MEM_HEIGHT		64
# define MEM_SIZE		(MEM_HEIGHT * MEM_WIDTH)
# define IDX_MOD		(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE	(MEM_SIZE / 6)

# define HEX_SET				"0123456789abcdef"
# define STACK_LIMIT			7000000
# define DEBUG_BYTESTRING_LOC	"debug/current.bytestring"

/*
** Structs
*/

typedef struct		s_mem
{
	uint8_t			byte;
	int				pnum;
	uint8_t			timer;
	uint16_t		active;
}					t_mem;

typedef struct		s_flag
{
	uint8_t			p;
	uint8_t			b;
	uint8_t			n;
	uint8_t			s;
	uint32_t		d;
	uint8_t			v;
	uint8_t			h;
	uint32_t		w;
}					t_flag;

typedef struct		s_head
{
	int				pnum;
	int				live;
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	int				size;
	uint8_t			code[CHAMP_MAX_SIZE];
}					t_head;

typedef struct		s_pc
{
	uint16_t		i;
	int				r[REG_NUMBER + 1];
	uint8_t			carry;
	uint16_t		alive;
	int16_t			wait;
	struct s_pc		*next;
	struct s_pc		*prev;
}					t_pc;

typedef struct		s_cyc
{
	int32_t			cycle;
	int16_t			last;
	int32_t			die;
	uint32_t		breakdown[2];
	uint8_t			num_champs;
	uint32_t		last_live[MAX_PLAYERS];
	uint32_t		current_live[MAX_PLAYERS];
	uint32_t		prev_live[MAX_PLAYERS];
	uint32_t		pcount[MAX_PLAYERS];
	uint32_t		pc_info[MAX_PLAYERS];
	char			*verification_bytestring;
	t_mem			*mem;
}					t_cyc;

typedef struct		s_loc
{
	int				row;
	int				col;
}					t_loc;

/*
** Dispatch Array
*/

void				op_live(t_cyc *cyc, t_pc *pc);
void				op_ld(t_cyc *cyc, t_pc *pc);
void				op_st(t_cyc *cyc, t_pc *pc);
void				op_add(t_cyc *cyc, t_pc *pc);
void				op_sub(t_cyc *cyc, t_pc *pc);
void				op_and(t_cyc *cyc, t_pc *pc);
void				op_or(t_cyc *cyc, t_pc *pc);
void				op_xor(t_cyc *cyc, t_pc *pc);
void				op_zjmp(t_cyc *cyc, t_pc *pc);
void				op_ldi(t_cyc *cyc, t_pc *pc);
void				op_sti(t_cyc *cyc, t_pc *pc);
void				op_fork(t_cyc *cyc, t_pc *pc);
void				op_lld(t_cyc *cyc, t_pc *pc);
void				op_lldi(t_cyc *cyc, t_pc *pc);
void				op_lfork(t_cyc *cyc, t_pc *pc);
void				op_aff(t_cyc *cyc, t_pc *pc);

typedef void		(*t_fn)(t_cyc *, t_pc *);
extern const t_fn	g_op_fn[];

/*
** Globals
*/

clock_t				g_time;
t_pc				*g_head;

/*
** Functions
*/

uint16_t			acb_len(uint8_t acb, bool last_field);
void				display_winner(t_head *head, int winner);
int					file_handler(int ac, char **av, t_head *head);
t_flag				ft_setopt(int ac, char **av);
t_cyc				*init_cyc(t_mem *mem, t_flag *flags, int n);
t_mem				*init_mem(t_head *head, int n);
void				init_pc(t_mem *mem, t_head *head, int n);
int					player_count(t_head *head);
void				vm(t_cyc *cyc, t_head *head, t_flag *flags);

/*
** PC
*/

void				pc_app(t_pc **lst, t_pc *node);
void				pc_free(t_pc *pc);
t_pc				*pc_new(uint32_t pnum, uint16_t loc, uint8_t op);
void				pc_scan_op(t_cyc *cyc, t_pc *pc);
void				pc_scan_rem(t_cyc *cyc, t_pc **pc);

/*
** Util
*/

void				ft_memrcpy(void *dst, void *src, size_t n);
void				ft_putwchar(uint32_t c);
void				cw_memcp(t_mem *dst, t_mem *src, size_t n);
void				cw_memwen(t_mem *mem, void *src, size_t n, int pnum);
void				cw_memren(void *dst, t_mem *mem, size_t n);

/*
** Debug
*/

void				cw_dump_mem(t_cyc *cyc, int erow, int ecol);
void				cw_dump_pcs(void);
char				*read_bytestring(void);
void				verify_cycle_bytes(t_cyc *cyc, char *bytestring);

#endif

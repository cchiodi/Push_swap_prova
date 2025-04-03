#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int *stack_a;    // Array per la pila a
	int *stack_b;    // Array per la pila b
	int size_a;      // Dimensione attuale di stack_a
	int size_b;      // Dimensione attuale di stack_b
	int start_a; // Indice di inizio per stack_a
	int start_b; // Indice di inizio per stack_b (se serve per altre operazioni)
	int capacity; // Capacità massima dell'array
} t_stack;



int		ft_putnbr(long int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);

void    sa(t_stack *stacks); // Scambia i primi due elementi di stack_a
void    sb(int *stack_b, int size_b); // Scambia i primi due elementi di stack_b
void    ss(t_stack *stacks);          // Esegue sa e sb contemporaneamente
void    pa(t_stack *stacks);          // Sposta il primo elemento di stack_b in stack_a
void    pb(t_stack *stacks);          // Sposta il primo elemento di stack_a in stack_b
void    ra(t_stack *stacks);     // Ruota verso l'alto gli elementi di una pila
void    rb(t_stack *stacks);     // Ruota verso l'alto gli elementi di stack_b
void    rr(t_stack *stacks);          // Esegue ra e rb contemporaneamente
void    rra(t_stack *stacks);    // Ruota verso il basso gli elementi di una pila
void    rrb(t_stack *stacks);    // Ruota verso il basso gli elementi di stack_b
void    rrr(t_stack *stacks);         // Esegue rra e rrb contemporaneamente

// Funzioni di ordinamento (da implementare)
void    sort_three_elements(t_stack *stacks);// Algoritmo di ordinamento per tre elementi
void    sort_small_stack(t_stack *stacks); // Algoritmo di ordinamento per pochi elementi
void    sort_large_stack(t_stack *stacks); // Algoritmo di ordinamento per molti elementi




#endif

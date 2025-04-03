#include "push_swap.h"

void sa(t_stack *stacks)
{
    if (stacks->size_a > 1)
    {
        int temp = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0);
        set_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0,
                          get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 1));
        set_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 1, temp);
        ft_putstr("sa\n");
    }
}


void sb(t_stack *stacks)
{
    if (stacks->size_b > 1)
    {
        int temp = get_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 0);
        set_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 0,
                          get_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 1));
        set_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 1, temp);
        ft_putstr("sb\n");
    }
}


void ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_putstr("ss\n");
}

void pa(t_stack *stacks)
{
    if (stacks->size_b > 0)
    {
        // Decrementa start_a per inserire l'elemento in cima a stack_a
        stacks->start_a = (stacks->start_a - 1 + stacks->capacity) % stacks->capacity;

        // Aggiungi l'elemento di stack_b alla cima di stack_a
        set_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0,
                          get_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 0));

        stacks->size_a++;

        // Incrementa start_b per rimuovere l'elemento dalla cima di stack_b
        stacks->start_b = (stacks->start_b + 1) % stacks->capacity;
        stacks->size_b--;

        ft_putstr("pa\n");
    }
}



void pb(t_stack *stacks)
{
    if (stacks->size_a > 0)
    {
        // Decrementa start_b per inserire l'elemento in cima a stack_b
        stacks->start_b = (stacks->start_b - 1 + stacks->capacity) % stacks->capacity;

        // Aggiungi l'elemento di stack_a alla cima di stack_b
        set_stack_element(stacks->stack_b, stacks->start_b, stacks->capacity, 0,
                          get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0));

        stacks->size_b++;

        // Incrementa start_a per rimuovere l'elemento dalla cima di stack_a
        stacks->start_a = (stacks->start_a + 1) % stacks->capacity;
        stacks->size_a--;

        ft_putstr("pb\n");
    }
}



void ra(t_stack *stacks)
{
    // Se lo stack ha più di un elemento
    if (stacks->size_a > 1)
    {
        // Incrementa l'indice start_a per effettuare la rotazione
        stacks->start_a = (stacks->start_a + 1) % stacks->capacity;

        // Stampa l'operazione
        ft_putstr("ra\n");
    }
}



void rb(t_stack *stacks)
{
    if (stacks->size_b > 1)
    {
        // Incrementa start_b per ruotare stack_b verso l'alto
        stacks->start_b = (stacks->start_b + 1) % stacks->capacity;
        ft_putstr("rb\n");
    }
}


void rr(t_stack *stacks)
{
    if (stacks->size_a > 1 || stacks->size_b > 1)
    {
        if (stacks->size_a > 1)
        {
            // Incrementa start_a per ruotare stack_a verso l'alto
            stacks->start_a = (stacks->start_a + 1) % stacks->capacity;
        }
        if (stacks->size_b > 1)
        {
            // Incrementa start_b per ruotare stack_b verso l'alto
            stacks->start_b = (stacks->start_b + 1) % stacks->capacity;
        }
        ft_putstr("rr\n");
    }
}


void rra(t_stack *stacks)
{
    if (stacks->size_a > 1)
    {
        // Decrementa start_a per ruotare stack_a verso il basso
        stacks->start_a = (stacks->start_a - 1 + stacks->capacity) % stacks->capacity;
        ft_putstr("rra\n");
    }
}

void rrb(t_stack *stacks)
{
    if (stacks->size_b > 1)
    {
        // Decrementa start_b per ruotare stack_b verso il basso
        stacks->start_b = (stacks->start_b - 1 + stacks->capacity) % stacks->capacity;
        ft_putstr("rrb\n");
    }
}


void rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_putstr("rrr\n");
}

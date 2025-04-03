#include "push_swap.h"

int get_stack_element(int *stack, int start, int capacity, int index)
{
    if (index < 0 || index >= capacity) // Verifica che l'indice sia valido
    {
        ft_putstr("Error: invalid index access\n");
        return (0); // Restituisci un valore predefinito o gestisci l'errore
    }
    return stack[(start + index) % capacity];
}


void set_stack_element(int *stack, int start, int capacity, int index, int value)
{
    if (index < 0 || index >= capacity) // Verifica che l'indice sia valido
    {
        ft_putstr("Error: invalid index access\n");
        return; // Non esegue l'operazione se l'indice non è valido
    }
    stack[(start + index) % capacity] = value;
}



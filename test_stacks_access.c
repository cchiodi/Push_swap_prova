#include "push_swap.h"

void test_stacks_access()
{
    int stack[5] = {10, 20, 30, 40, 50};
    int start = 0;
    int capacity = 5;

    // Test get_stack_element con indici validi
    ft_putstr("Test 1: Indice valido\n");
    int value = get_stack_element(stack, start, capacity, 2); // Atteso: 30
    if (value == 30)
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");

    // Test get_stack_element con indice negativo
    ft_putstr("Test 2: Indice negativo\n");
    value = get_stack_element(stack, start, capacity, -1); // Atteso: messaggio di errore
    if (value == 0) // Restituiamo 0 come valore di fallback
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");

    // Test get_stack_element con indice oltre la capacità
    ft_putstr("Test 3: Indice fuori capacità\n");
    value = get_stack_element(stack, start, capacity, 6); // Atteso: messaggio di errore
    if (value == 0)
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");

    // Test set_stack_element con indici validi
    ft_putstr("Test 4: Set indice valido\n");
    set_stack_element(stack, start, capacity, 3, 99); // Cambia stack[3] in 99
    if (stack[3] == 99)
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");

    // Test set_stack_element con indice negativo
    ft_putstr("Test 5: Set indice negativo\n");
    set_stack_element(stack, start, capacity, -1, 99); // Atteso: messaggio di errore
    if (stack[3] == 99) // Il valore precedente non deve cambiare
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");

    // Test set_stack_element con indice oltre la capacità
    ft_putstr("Test 6: Set indice fuori capacità\n");
    set_stack_element(stack, start, capacity, 10, 88); // Atteso: messaggio di errore
    if (stack[3] == 99) // Il valore precedente non deve cambiare
        ft_putstr("Passato\n");
    else
        ft_putstr("Fallito\n");
}

int main()
{
    test_stacks_access();
    return 0;
}

#include "push_swap.h"
#include <climits>

// Funzione per controllare se una stringa rappresenta un numero intero valido
int is_number(const char *str)
{
    int i = 0;

    // Gestisce il segno opzionale
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Controlla che tutti i caratteri rimanenti siano numeri
    if (str[i] == '\0') // Caso di soli segni (+ o - senza numeri)
        return (0);
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

// Funzione per controllare duplicati nell'array
int has_duplicates(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                return (1);
        }
    }
    return (0);
}

// Funzione per convertire stringa in int con gestione errori
int safe_atoi(const char *str, int *error)
{
    long long result = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str)
    {
        if (!isdigit(*str))
        {
            *error = 1;
            return (0);
        }
        result = result * 10 + (*str - '0');
        if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
        {
            *error = 1;
            return (0);
        }
        str++;
    }
    return ((int)(result * sign));
}

// Funzione per validare input
int is_valid_input(int argc, char **argv, int *stack_a)
{
    int error = 0;

    for (int i = 0; i < argc - 1; i++)
    {
        if (!is_number(argv[i + 1]))
            return (0);
        stack_a[i] = safe_atoi(argv[i + 1], &error);
        if (error)
            return (0);
    }
    if (has_duplicates(stack_a, argc - 1))
        return (0);
    return (1);
}

#include "push_swap.h"

void initialize_stacks(t_stack *stacks, int *stack_a, int *stack_b, int size)
{
    stacks->stack_a = stack_a;
    stacks->stack_b = stack_b;
    stacks->size_a = size;
    stacks->size_b = 0;
    stacks->start_a = 0;
    stacks->start_b = 0;
    stacks->capacity = 100;
}

int main(int argc, char **argv)
{
    t_stack stacks;
    int stack_a[100];
    int stack_b[100];

    if (argc < 2)
        return (ft_putstr("Error: not enough arguments\n"), 1);

    if (!is_valid_input(argc, argv, stack_a))
        return (ft_putstr("Error: invalid input\n"), 1);

    initialize_stacks(&stacks, stack_a, stack_b, argc - 1);

    if (stacks.size_a <= 3)
        sort_three_elements(&stacks);
    else if (stacks.size_a <= 5)
        sort_small_stack(&stacks);
    else
        sort_large_stack(&stacks);

    return (0);
}


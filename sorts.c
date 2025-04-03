#include "push_swap.h"

int find_min_index(t_stack *stacks)
{
    int min_index = 0;
    int min_value = stacks->stack_a[stacks->start_a];
    int i = 1;

    while (i < stacks->size_a)
    {
        int value = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, i);
        if (value < min_value)
        {
            min_value = value;
            min_index = i;
        }
        i++;
    }
    return (min_index);
}
void move_min_to_top(t_stack *stacks, int min_index)
{
    if (min_index <= stacks->size_a / 2)
    {
        while (min_index--)
            ra(stacks);
    }
    else
    {
        while (min_index++ < stacks->size_a)
            rra(stacks);
    }
}



void sort_three_elements(t_stack *stacks)
{
	int first = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0);
	int second = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 1);
	int third = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 2);

	if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > third && third > second)
		ra(stacks);
	else if (second > third && third > first)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (second > first && first > third)
		rra(stacks);
	else if (third > first && first > second)
		sa(stacks);
}



void sort_small_stack(t_stack *stacks)
{
    while (stacks->size_a > 3)
    {
        int min_index = find_min_index(stacks);
        move_min_to_top(stacks, min_index);
        pb(stacks);
    }

    sort_three_elements(stacks);

    while (stacks->size_b > 0)
        pa(stacks);
}

int calculate_max_bits(t_stack *stacks)
{
    int max_bits = 0;
    int size = stacks->size_a;
    int i = 0;

    while (i < size)
    {
        int value = stacks->stack_a[(stacks->start_a + i) % stacks->capacity];
        if (value > (1 << max_bits) - 1)
            max_bits++;
        i++;
    }
    return (max_bits);
}
void radix_sort_pass(t_stack *stacks, int bit)
{
    int count = 0;
    int initial_size = stacks->size_a;

    while (count < initial_size)
    {
        int value = get_stack_element(stacks->stack_a, stacks->start_a, stacks->capacity, 0);
        if ((value >> bit) & 1)
            ra(stacks);
        else
            pb(stacks);
        count++;
    }

    while (stacks->size_b > 0)
        pa(stacks);
}
void sort_large_stack(t_stack *stacks)
{
    int max_bits = calculate_max_bits(stacks);
    int bit = 0;

    while (bit < max_bits)
    {
        radix_sort_pass(stacks, bit);
        bit++;
    }
}

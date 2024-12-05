#include "ft_printf.h"

int check_count(int current_count, int new_count)
{
    if (new_count == -1)
        return (new_count);
    else
        return (current_count + new_count);
}
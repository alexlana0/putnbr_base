#include <unistd.h>
#include <string.h>

static int is_valid_base(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (i >= 2);
}

void putnbr_base(int nbr, char *base)
{
    long num;
    int base_size;
    char c;

    if (!is_valid_base(base))
        return;
    num = (long)nbr;
    base_size = strlen(base);
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
    if (num >= base_size)
        putnbr_base(num / base_size, base);
    c = base[num % base_size];
    write(1, &c, 1);
}
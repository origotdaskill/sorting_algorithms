#include "sort.h"
#include <stdlib.h>

void counting_sort(int *array, size_t size)
{
    size_t i;
    int max = array[0];
    int *counting_array = malloc((max + 1) * sizeof(int));
        int j = 0;



    /* Find the maximum value in the array */
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for the counting array */
    if (counting_array == NULL)
    {
        free(counting_array);
        return;
    }

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    print_array(counting_array, max + 1);

    /* Update array with sorted elements */
    for (i = 0; i <= (size_t)max; i++)
    {
        while (counting_array[i] > 0)
        {
            array[j++] = (int)i;
            counting_array[i]--;
        }
    }

    /* Free dynamically allocated memory */
    free(counting_array);
}

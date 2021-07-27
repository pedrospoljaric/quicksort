#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Quicksort(int *all, int esq, int dir)
{
    int i = esq, j = dir;
    int pivot = (i + j)/2;
    int item;
    item = all[pivot];

    do
    {
        while (item > all[i]) i++;
        while (item < all[j]) j--;

        if (i <= j)
        {
            int aux = all[i];
            all[i] = all[j];
            all[j] = aux;
            i++;
            j--;
        }
    }while (i <= j);

    if (esq < j) Quicksort(all, esq, j);
    if (i < dir) Quicksort(all, i, dir);
}

int main()
{
    clock_t tic = clock();

    int i, *v = (int*) malloc(1000000 * sizeof(int));

    for (i = 0; i < 1000000; i++)
        v[i] = i+1;

    for (i = 0; i < 1000000; i++)
    {
        int temp = v[i];
        int randomIndex = rand() % 1000000;

        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }

    Quicksort(v, 0, 999999);

    clock_t toc = clock();
    printf("Tempo gasto: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    Quicksort(v, 0, 999999);

    toc = clock();
    printf("Tempo gasto: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    scanf("%d", v[0]);

    return 0;
}

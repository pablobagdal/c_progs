#include <stdio.h>
#include <malloc.h>
// #include <conio.h>

// Описание алгоритма «Сортировка Шелла»
// Этот метод сортировки Д. Шелл предложил в 1959 г. Он использует минимум памяти и показывает 
// высокие скорости при сортировке. По сути в методе Шелла применяются сравнения и перестановки
// элементов аналогичные методу вставок, но при этом порядок сравниваемых элементов совершенно 
// другой.

// Идея сортировки методом Шелла состоит в том, чтобы сортировать элементы отстоящие друг от друга 
// на некотором расстоянии step. Затем сортировка повторяется при меньших значениях step, и в конце процесс сортировки Шелла завершается при step = 1 (а именно обычной сортировкой вставками).

// До сих пор продолжает обсуждаться вопрос выбора шага сортировки step. Шелл предложил такую 
// последовательность: N/2, N/4, N/8 …, где N — количество элементов в сортируемом массиве.


// Сортировка Шелла требует около log2N проходов для упорядочивания последовательности длиной N.


//сортировка методом Шелла
void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];// 4
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

int main()
{
    //ввод N
    int N;
    printf("Input N: ");
    scanf_s("%d", &N);
    //выделение памяти под массив
    int* mass;
    mass = (int *)malloc(N * sizeof(int));
    //ввод элементов массива
    printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
        scanf_s("%d", &mass[i]);
    //сортировка методом Шелла
    ShellSort(N, mass);
    //вывод отсортированного массива на экран
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");
    //освобождение памяти
    free(mass);
    _getch();
    return 0;
}
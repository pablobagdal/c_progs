// Алгоритм основывается на разделении рассматриваемой части массива на две части меньшего 
// размера таким образом, что все элементы из одной части не превосходят любого элемента из 
// другой части. Для такого разделения необходимо выбирать опорный элемент. 
// Теоретически следует выбирать медиану, однако на практике руководствуются лишь 
// принципом постоянного выбора, то есть каждый раз при разбиении опорный элемент 
// выбирается из одних и тех же соображений. Как вы уже догадались, функция сортировки 
// является рекурсивной функцией (строки кода 27 и 29).

void hoarasort(double* a, int first, int last)
{
 
int i = first, j = last;
double tmp, x = a[(first + last) / 2];
 
do {
   while (a[i] < x)
     i++;
   while (a[j] > x)
     j--;
 
   if (i <= j) 
   {
     if (i < j)
     {
       tmp=a[i];
       a[i]=a[j];
       a[j]=tmp;
     }
     i++;
     j--;
   }
} while (i <= j);
 
if (i < last)
   hoarasort(a, i, last);
if (first < j)
   hoarasort(a, first,j);
}

// void main() {
//     hoarasort(a,0,n-1);
// }
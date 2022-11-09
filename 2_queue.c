// очередь в кассу кинотеатра


// Очередь — объект (абстрактный тип данных. Он поддерживает такие операции:

// Enqueue — позволяет добавить элемент в конец очереди. 
// Pop — позволяет удалить элемент из начала очереди.
// IsEmpty — проверяет, пуста ли очередь.
// IsFull — проверяет, заполнена ли очередь.
// Peek — позволяет получить элемент в начале очереди без его удаления.

// Операция enqueue push
// Проверьте, не полна ли очередь.
// При добавлении первого элемента присвойте значение 0 указателю FRONT
// Увеличьте значение REAR на 1.
// Добавьте новый элемент на позицию, куда указывает REAR.

// Операция dequeue pop
// Проверьте, не пуста ли очередь.
// Получите значение, на которое указывает FRONT.
// Увеличьте значение FRONT на 1.
// При удалении последнего элемента присвойте значение -1 указателям FRONT и REAR.

// Реализация очередей в C

#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
  //функцию deQueue нельзя применять к пустой очереди
  deQueue();

  // Добавляем в очередь 5 элементов
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Шестой элемент добавить нельзя — очередь заполнена
  enQueue(6);

  display();

  // Функция deQueue удаляет первый элемент — 1
  deQueue();

  // Теперь внутри очереди 4 элемента
  display();

  return 0;
}

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nОчередь заполнена");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nДобавлено значение -> %d", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nОчередь пуста");
  else {
    printf("\nУдален элемент: %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Функция выводит очередь в консоль
void display() {
  if (rear == -1)
    printf("\nОчередь пуста");
  else {
    int i;
    printf("\nЭлементы очереди:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}


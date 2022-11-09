
// Стек – это структура данных, в которой элементы поддерживают принцип LIFO (“Last in – first out”): последним зашёл – первым вышел. Или первым зашёл – последним вышел.
// как стопка тарелок
// Стек позволяет хранить элементы и поддерживает, обычно, две базовые операции:

// PUSH – кладёт элемент на вершину стека
// POP – снимает элемент с вершины стека, перемещая вершину к следующему элементу

// Реализация стека в C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

// Создаем стек
struct stack {
  int items[MAX];
  int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Проверяем, не заполнен ли стек
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Проверяем, не пуст ли стек
int isempty(st *s1) {
  if (s1->top == -1)
    return 1;
  else
    return 0;
}

// Добавляем элементы в стек
void push(st *s, int newitem) {
  if (isfull(s)) {
    printf("Стек заполнен");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Удаляем элементы из стека
void pop(st *s) {
  if (isempty(s)) {
    printf("\n Стек пуст \n");
  } else {
    printf("Удален элемент= %d", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Выводим в консоль элементы стека
void printStack(st *s) {
  printf("Стек: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Функция main
int main() {
  int ch;
  st *s = (st *)malloc(sizeof(st));

  createEmptyStack(s);

  st *d = (st *)malloc(sizeof(st));

  createEmptyStack(d);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  printf("\nПосле удаления\n");
  printStack(s);
}
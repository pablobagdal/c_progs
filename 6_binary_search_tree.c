// Дерево двоичное, потому что у каждого узла не более двух дочерних элементов. 
// Дерево поиска, потому что его можно использовать для проверки вхождения 
// числа — за время O(log(n)). 

// Чем отличается от обычного двоичного дерева
// Все узлы левого поддерева меньше корневого узла.
// Все узлы правого поддерева больше корневого узла.
// Оба поддерева каждого узла тоже являются деревьями двоичного поиска,
//  т. е. также обладают первыми двумя свойствами. 

// Операции с двоичным деревом поиска на C

#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};

// Создаем узел
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Отсортированный (inorder) обход 
void inorder(struct node *root) {
  if (root != NULL) {
    // Обходимо лево
    inorder(root->left);

    // Обходим корень
    printf("%d -> ", root->key);

    // Обходимо право
    inorder(root->right);
  }
}

// Вставка узла
struct node *insert(struct node *node, int key) {
  // Возвращаем новый узел, если дерево пустое
  if (node == NULL) return newNode(key);

  // Проходим в нужное место и вставляем узел
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Поиск inorder-преемника
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Находим крайний левый лист — он и будет inorder-преемником
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Удаляем узел
struct node *deleteNode(struct node *root, int key) {
  // Возвращаем, если дерево пустое
  if (root == NULL) return root;

  // Ищем узел, который нужно удалить
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Если у узла только один дочерний элемент или их вообще нет
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Если у узла два дочерних элемента
    struct node *temp = minValueNode(root->right);

    // Помещаем inorder-преемника на место узла, который хотим удалить
    root->key = temp->key;

    // Удаляем inorder-преемника
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Тестим функции
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Отсортированный обход: ");
  inorder(root);

  printf("\nПосле удаления 10\n");
  root = deleteNode(root, 10);

  printf("Отсортированный обход: ");
  inorder(root);
}
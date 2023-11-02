#include <stdio.h>
#include <stdlib.h>

struct Node;    // Структура, отвечающая за бинарное дерево
struct Node *CreateTree(struct Node *, struct Node *, int); // Создание и добавление элемента
void PrintTree(struct Node *, int); // Вывод дерева в консоль
void SearchElement(struct Node *, int); // Поиск введённого элемента
void Occurrence(struct Node *, int);    // Поиск числа вхождений элементов

int finding, entry = 0; // переменные наличия элемента и числа вхождений


int main()
{
    srand(time(NULL));
    struct Node *root = NULL;
    int D, amount = 0, operation = 0, element = 0;

    printf("\t# Binary Tree #\n\n");
    printf(" 0 - Quit\n 1 - Search the element\n 2 - Occurrence of element\n\n");
    printf("Enter amount of elements: ");
    scanf("%d", &amount);

	for(int i = 0; i < amount; i++)
	{
		D = rand() % 21 - 10;
        root = CreateTree(root, root, D);
        printf("Element: %d\n", D);
	}
    printf("Binary Tree\n");
	PrintTree(root,0);

    label:
	printf("Enter operation: ");
	scanf("%d", &operation);

	switch(operation)
	{
	case 0:
        return 0;
	break;

	case 1: // Первая задача: поиск элемента, введённого с клавиатуры
        finding = 0;
        printf("Enter the element you wont to search: ");
        scanf("%d", &element);
        SearchElement(root, element);
        if(finding == 1) printf("Element found!\n");
        else if(finding == 0) printf("Element not found!\n");
	break;

	case 2: // Вторая задача: число вхождений элемента
        printf("Enter the element you wont to search: ");
        scanf("%d", &element);
        Occurrence(root, element);
        printf("Number of occurrences of the element: %d\n", entry);
        entry = 0;
	break;

	default:
	printf("Invalid operation!\n");
	}
	goto label;

    return 0;
}

struct Node
{
    int data;   // Данные
    struct Node* left;  // Указатель на левого потомка
    struct Node* right; // Указатель на правого потомка
};

struct Node *CreateTree(struct Node *root, struct Node *pointer, int data)
{
    if (pointer == NULL)
	{
		pointer = (struct Node *)malloc(sizeof(struct Node));   // Выделение памяти

		pointer->left = NULL;
		pointer->right = NULL;
		pointer->data = data;
		if (root == NULL) return pointer;

		if (data > root->data)	root->left = pointer;   // Если данные больше данных корня, запись идёт в левый потомок
		else root->right = pointer; // Иначе, запись производится в правый потомок
		return pointer;
	}

	if (data > pointer->data)   //Если данные больше родителя, они будут записываться в левый потомок
		CreateTree(pointer, pointer->left, data);
	else    // Иначе, запись производится в правый потомок
		CreateTree(pointer, pointer->right, data);

	return root;
}

void PrintTree(struct Node *pointer, int l)
{
    if (pointer == NULL)    // Если родитель указывает на NULL, то return
	{
		return;
	}

	PrintTree(pointer->right, l + 1);   // В качестве родителя передаётся указатель на правого потомка
	for(int i = 0; i < l; i++)
	{
		printf("   ");
	}

	printf("%d\n", pointer->data);
	PrintTree(pointer->left,  l+1); // В качестве родителя передаётся указатель на левого потомка
}

void SearchElement(struct Node *pointer, int element)
{
    if (pointer == NULL)
	{
		return;
	}

	SearchElement(pointer->right, element);

	if(pointer -> data == element) finding = 1;

	SearchElement(pointer->left, element);
}

void Occurrence(struct Node *pointer, int element)
{
     if (pointer == NULL)
	{
		return;
	}

	Occurrence(pointer->right, element);

	if(pointer -> data == element) entry++;

	Occurrence(pointer->left, element);
}

/* Сложность процедуры поиска в бинарном дереве по значению  O(2N), где N - число рекурсивных вызовов,
так как операция сравнения происходит столько же раз, сколько и вызывается функция.
Умножене на 2 происходит из-за вызова рекурсии внутрии себя дважды */


#include <stdio.h>
#include <stdlib.h>

struct Node;    // Структура, отвечающая за бинарное дерево
struct Node *CreateTree(struct Node *, struct Node *, int); // Создание и добавление элемента
void PrintTree(struct Node *, int); // Вывод дерева в консоль
void CheckRepeat(struct Node *, int);  // Проверка на совпадение элементов

int entry = 0;

int main()
{
    struct Node *root = NULL;
    int D;
    float cont = 1;

    printf("\t# Binary Tree #\n\n");
	while(1)
	{
		printf("Enter integer: ");
		scanf("%d", &D);
		CheckRepeat(root, D);
		if(entry == 0)
		{
            root = CreateTree(root, root, D);
            printf("Continue entering(any integer) or not(0): ");
            scanf("%f", &cont);
        }
        else printf("Element already exists!\n");
        entry = 0;
        if(cont == 0) break;
	}

	PrintTree(root,0);

    return 0;
}

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *CreateTree(struct Node *root, struct Node *pointer, int data)
{
    if (pointer == NULL)
	{
		pointer = (struct Node *)malloc(sizeof(struct Node));

		pointer->left = NULL;
		pointer->right = NULL;
		pointer->data = data;
		if (root == NULL) return pointer;

		if (data > root->data)	root->left = pointer;
		else root->right = pointer;
		return pointer;
	}

	if (data > pointer->data)
		CreateTree(pointer, pointer->left, data);
	else
		CreateTree(pointer, pointer->right, data);

	return root;
}

void PrintTree(struct Node *pointer, int l)
{
    if (pointer == NULL)
	{
		return;
	}

	PrintTree(pointer->right, l + 1);
	for(int i = 0; i < l; i++)
	{
		printf("   ");
	}

	printf("%d\n", pointer->data);
	PrintTree(pointer->left,  l+1);
}

void CheckRepeat(struct Node *pointer, int element)
{
    if (pointer == NULL)
	{
		return;
	}

	CheckRepeat(pointer->right, element);

	if(pointer -> data == element) entry++;

	CheckRepeat(pointer->left, element);
}

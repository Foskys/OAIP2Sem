#include <iostream>
#include <set>
using namespace std;

struct Tree
{
    int key;
    char text[15];
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
void insertElem(Tree*& Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* deleteElem(Tree* Root, int key); //Удаление элемента по ключу
int view(Tree* t, int level);     //Вывод дерева 
bool delAll(Tree* t);             //Очистка дерева
int sumOfValues(Tree* p);          //Сумма значений всех вершин
int countNodesWithValueK(Tree* p, int k); //Количество вершин со значением k
int countLeaves(Tree* p);          //Количество листьев в дереве
void printLevel(Tree* tree, int level);
Tree* Root = NULL;  //указатель на корень

Tree* findNodeWithMinSum(Tree* root, int& minSum) {
    if (root == NULL)
        return NULL;

    Tree* leftMinNode = findNodeWithMinSum(root->Left, minSum);
    Tree* rightMinNode = findNodeWithMinSum(root->Right, minSum);

    int sum = root->key;

    if (leftMinNode != NULL) {
        sum += leftMinNode->key;
    }

    if (rightMinNode != NULL) {
        sum += rightMinNode->key;
    }

    if (sum < minSum)
        minSum = sum;

    return root;
}

Tree* deleteNodeWithMinSum(Tree* root) {
    int minSum = INT_MAX;
    Tree* nodeToDelete = findNodeWithMinSum(root, minSum);

    if (nodeToDelete == NULL)
        return root;

    return deleteElem(root, nodeToDelete->key);
}

int main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    Tree* rc; char s[15];
    for (;;)
    {
        cout << "1 : Создание дерева\n";
        cout << "2 : Добавление элемента\n";
        cout << "3 : Поиск по ключу\n";
        cout << "4 : Удаление элемента\n";
        cout << "5 : Вывод дерева\n";
        cout << "6 : Очистка дерева\n";
        cout << "7 : Вывод n-го уровня дерева(3)\n";
        cout << "8 : Сумма значений всех вершин дерева(10)\n";
        cout << "9 : Количество листьев в дереве(7)\n";
        cout << "10: Количество вершин со значением t(9)\n";
        cout << "11: Удаление вершины с минимальной суммой трех целых значений узла\n";
        cout << "12: Выход\n";
        cout << "Введите: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            Root = makeTree(Root);
            break;

        case 2:
            cout << "\nВведите ключ: ";
            cin >> key;
            cout << "Введите слово: ";
            cin >> s;
            insertElem(Root, key, s);
            break;

        case 3:
            cout << "\nВведите ключ: ";
            cin >> key;
            rc = search(Root, key);
            if (rc)
                cout << "Найденное слово= " << rc->text << endl;
            break;
        case 4:
            cout << "\nВведите удаляемый ключ: ";
            cin >> key;
            Root = deleteElem(Root, key);
            break;
        case 5:
            if (Root)
            {
                view(Root, 0);
            }
            else cout << "Дерево пустое\n";
            break;

        case 6:
            delAll(Root);
            break;

        case 7:
            int level;
            cout << "Введите уровень для вывода: ";
            cin >> level;
            printLevel(Root, level);
            break;

        case 8:
            n = sumOfValues(Root);
            cout << "Сумма значений всех вершин дерева: " << n << endl;
            break;

        case 9:
            n = countLeaves(Root);
            cout << "Количество листьев в дереве: " << n << endl;
            break;

        case 10:
            int k;
            cout << "Введите значение k\n";
            cin >> k;
            cin.ignore();
            n = countNodesWithValueK(Root, k);
            cout << "Количество вершин со значением " << n << endl;
            break;

        case 11:
            Root = deleteNodeWithMinSum(Root);
            break;

        case 12:
            return 0;
        }
    }
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
    int key; char s[5];
    set<int> keys; // для хранения уникальных ключей

    cout << "Конец ввода - число 0\n\n";
    if (Root == NULL)    // если дерево не создано
    {
        cout << "Введите ключ корня: ";
        cin >> key;
        while (key == 0 || keys.count(key)) {
            cout << "Ключ должен быть не равен 0 и не повторяться. Введите ключ заново: ";
            cin >> key;
        }
        keys.insert(key);
        cout << "Введите слово корня: ";
        cin >> s;
        Root = list(key, s);    // установка указателя на корень
    }
    while (1)                //добавление элементов
    {
        cout << "\nВведите ключ: ";
        cin >> key;
        if (key == 0) break;
        while (keys.count(key)) {
            cout << "Ключ не должен повторяться. Введите ключ заново: ";
            cin >> key;
        }
        keys.insert(key);
        cout << "Введите слово: ";
        cin >> s;
        insertElem(Root, key, s);
    }
    return Root;
}

Tree* list(int key_value, char* word)     // Создание нового узла дерева
{
    Tree* newNode = new Tree;
    newNode->key = key_value;
    for (int idx = 0; idx < 5; idx++)
        newNode->text[idx] = word[idx];
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

void insertElem(Tree*& tree, int key_value, char* word)  // Добавление нового узла в дерево
{
    if (tree == NULL)
        tree = list(key_value, word);
    else if (key_value < tree->key)
        insertElem(tree->Left, key_value, word);
    else
        insertElem(tree->Right, key_value, word);
}

Tree* deleteElem(Tree* treeRoot, int key_value)  // Удаление узла из дерева по ключу
{
    if (treeRoot == NULL)
        return NULL;

    if (key_value < treeRoot->key)
        treeRoot->Left = deleteElem(treeRoot->Left, key_value);
    else if (key_value > treeRoot->key)
        treeRoot->Right = deleteElem(treeRoot->Right, key_value);
    else {
        // Узел с одним или без детей
        if (treeRoot->Left == NULL) {
            Tree* tempNode = treeRoot->Right;
            delete treeRoot;
            return tempNode;
        }
        else if (treeRoot->Right == NULL) {
            Tree* tempNode = treeRoot->Left;
            delete treeRoot;
            return tempNode;
        }
        // Узел с двумя детьми, получаем наименьший элемент в правом поддереве
        Tree* tempNode = treeRoot->Right;
        while (tempNode->Left != NULL)
            tempNode = tempNode->Left;
        // Копируем содержимое наименьшего элемента в текущий узел
        treeRoot->key = tempNode->key;
        // Удаляем наименьший элемент в правом поддереве
        treeRoot->Right = deleteElem(treeRoot->Right, tempNode->key);
    }
    return treeRoot;
}

Tree* search(Tree* node, int key_value)  // Поиск узла в дереве по ключу 
{
    if (node == NULL || node->key == key_value)
        return node;

    if (key_value < node->key)
        return search(node->Left, key_value);

    return search(node->Right, key_value);
}

int view(Tree* tree, int level) // Вывод дерева 
{
    if (tree != NULL)
    {
        view(tree->Right, level + 1);    // Вывод правого поддерева
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << tree->key << ' ' << tree->text << endl;
        view(tree->Left, level + 1);    // Вывод левого поддерева
    }
    return 0;
}

bool delAll(Tree* tree) // Очистка дерева
{
    if (tree != NULL)
    {
        delAll(tree->Left);
        delAll(tree->Right);
        delete tree;
        return true;
    }
    return false;
}

void printLevel(Tree* tree, int level) // Вывод узлов на определенном уровне
{
    if (tree == NULL)
        return;
    if (level == 0)
        cout << tree->key << ' ' << tree->text << endl;
    else
    {
        printLevel(tree->Left, level - 1);
        printLevel(tree->Right, level - 1);
    }
}

int sumOfValues(Tree* p) {
    if (p == NULL)
        return 0;

    int sum = p->key;


    sum += sumOfValues(p->Left);
    sum += sumOfValues(p->Right);

    return sum;
}

int countLeaves(Tree* p) {
    if (p == NULL)
        return 0;
    if (p->Left == NULL && p->Right == NULL)
        return 1;
    return countLeaves(p->Left) + countLeaves(p->Right);
}

int countNodesWithValueK(Tree* p, int k) {
    if (p == NULL)
        return 0;

    int count = 0;


    if (p->key == k)
        count++;


    count += countNodesWithValueK(p->Left, k);
    count += countNodesWithValueK(p->Right, k);

    return count;
}

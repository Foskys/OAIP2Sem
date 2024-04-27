#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printLevelSums(Node* root) {
    if (root == nullptr) {
        cout << "Дерево пусто!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSum = 0;
        int nodesAtCurrentLevel = q.size();

        for (int i = 0; i < nodesAtCurrentLevel; ++i) {
            Node* current = q.front();
            q.pop();
            levelSum += current->data;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        cout << "Сумма значений вершин на уровне " << level << ": " << levelSum << endl;
        ++level;
    }
}

void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    setlocale(LC_ALL,"rus");
    Node* root = nullptr;
    int choice, value, key;

    do {
        cout << "1 - Создание дерева\n";
        cout << "2 - Добавление элемента\n";
        cout << "3 - Поиск по ключу\n";
        cout << "4 - Удаление элемента\n";
        cout << "5 - Вывод дерева\n";
        cout << "6 - Подсчет сумм значений вершин на каждом уровне\n";
        cout << "7 - Очистка дерева\n";
        cout << "8 - Выход\n";
        cout << "Ваш выбор? ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            cout << "Введите значение корня дерева: ";
            cin >> value;
            root = createNode(value);
            break;
        case 2:
            cout << "Введите значение для добавления: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 3:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            if (search(root, key))
                cout << "Элемент найден.\n";
            else
                cout << "Элемент не найден.\n";
            break;
        case 4:
            cout << "Введите значение для удаления: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 5:
            cout << "Дерево: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        case 6:
            cout << "Суммы значений вершин на каждом уровне:" << endl;
            printLevelSums(root);
            break;
        case 7:
            deleteTree(root);
            root = nullptr;
            cout << "Дерево очищено.\n";
            break;
        case 8:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 8);

    return 0;
}
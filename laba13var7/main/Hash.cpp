#include "Hash.h" // Включаем заголовочный файл с объявлением класса Object
#include <iostream>

// Хеш-функция для вычисления индекса в хеш-таблице
int HashFunction(int key, int size, int p)
{
    // Используется простая хеш-функция, которая возвращает остаток от деления суммы ключа и коэффициента p на размер таблицы
    return (p + key) % size;
}

// Функция для вычисления следующего индекса в случае коллизии
int Next_hash(int hash, int size, int p)
{
    // Формула для вычисления следующего индекса в случае коллизии
    return (hash + 5 * p + 3 * p * p) % size;
}

// Функция для создания объекта хеш-таблицы заданного размера
Object create(int size, int(*getkey)(void*))
{
    // Создание нового объекта хеш-таблицы с заданным размером и функцией для получения ключа
    return *(new Object(size, getkey));
}

// Конструктор класса Object
Object::Object(int size, int(*getkey)(void*))
{
    N = 0; // Инициализация количества элементов
    this->size = size; // Установка размера таблицы
    this->getKey = getkey; // Установка функции получения ключа
    this->data = new void* [size]; // Выделение памяти под массив указателей
    for (int i = 0; i < size; ++i)
        data[i] = NULL; // Инициализация массива NULL
}

// Метод для вставки элемента в хеш-таблицу
bool Object::insert(void* d)
{
    bool b = false;
    if (N != size) // Проверка на заполненность таблицы
        for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
            i != size && !b;  j = Next_hash(j, size, ++i))
            if (data[j] == NULL || data[j] == DEL)
            {
                // Если ячейка пуста или удалена, помещаем элемент в эту ячейку
                data[j] = d;
                N++; // Увеличиваем количество элементов
                b = true;
            }
    return b;
}

// Метод для поиска индекса элемента по ключу
int Object::searchInd(int key)
{
    int t = -1; // Инициализация индекса элемента как -1 (не найден)
    bool b = false;
    if (N != 0) // Проверка наличия элементов в таблице
        for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
            if (data[j] != DEL)
                if (getKey(data[j]) == key)
                {
                    // Если ключ элемента совпадает с заданным, сохраняем индекс и завершаем поиск
                    t = j;
                    b = true;
                }
    return t;
}

// Метод для поиска элемента по ключу
void* Object::search(int key)
{
    int t = searchInd(key); // Получаем индекс элемента по ключу
    return (t >= 0) ? (data[t]) : (NULL); // Возвращаем указатель на элемент или NULL, если элемент не найден
}

// Метод для удаления элемента по ключу
void* Object::deleteByKey(int key)
{
    int i = searchInd(key); // Получаем индекс элемента по ключу
    void* t = data[i]; // Сохраняем указатель на удаляемый элемент
    if (t != NULL)
    {
        data[i] = DEL; // Помечаем ячейку как удаленную
        N--; // Уменьшаем количество элементов
    }
    return t; // Возвращаем удаленный элемент
}

// Метод для удаления элемента по значению
bool Object::deleteByValue(void* d)
{
    return(deleteByKey(getKey(d)) != NULL); // Удаляем элемент по ключу, полученному из значения
}

// Метод для сканирования элементов хеш-таблицы
void Object::scan(void(*f)(void*))
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << " Элемент" << i;
        if ((this->data)[i] == NULL)
            std::cout << "  пусто" << std::endl;
        else
            if ((this->data)[i] == DEL)
                std::cout << "  удален" << std::endl;
            else
                f((this->data)[i]);
    }
}

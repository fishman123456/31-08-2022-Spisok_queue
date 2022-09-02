// 31-08-2022-Spisok_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Создать базовый класс список. Реализовать на базе списка стек и очередь с виртуальными
// функциями вставки и вытаскивания.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
class list // класс список создаём 
{
	//Очередь
	int* Wait;
	//Максимальный размер очереди
	int MaxlistLength;
	//Текущий размер очереди
	int listLength;
public:
	//Конструктор
	list(int m);
	//Деструктор
	~list();
	//Добавление элемента
	void Add(int c);
	//Извлечение элемента
	int Extract();
	//Очистка очереди
	void Clear();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	//демонстрация очереди
	void Show();
};
void list::Show() {
	cout << "\n***********************************\n";
	//демонстрация очереди
	for (int i = 0; i < listLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n***********************************\n";
}
list::~list()
{
	//удаление очереди
	delete[]Wait;
}
list::list(int m)
{
	//получаем размер
	MaxlistLength = m;
	//создаем очередь
	Wait = new int[MaxlistLength];
	//Изначально очередь пуста
	listLength = 0;
}
void list::Clear()
{
	//Эффективная "очистка" очереди
	listLength = 0;
}
bool list::IsEmpty()
{
	//Пуст?
	return listLength == 0;
}
bool list::IsFull()
{
	//Полон?
	return listLength == MaxlistLength;
}
int list::GetCount()
{
	//Количество присутствующих в стеке элементов
	return listLength;
}
void list::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
		Wait[listLength++] = c;
}
int list::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < listLength; i++)
			Wait[i - 1] = Wait[i];
		//уменьшить количество
		listLength--;
		//вернуть первый(нулевой)
		return temp;
	}
	else //Если в стеке элементов нет
		return -1;
}
int main()
{
	srand(time(0));
	//создание очереди
	list QU(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QU.Add(rand() % 50);
	}
	//показ очереди
	QU.Show();
	//извлечение элемента
	QU.Extract();
	//показ очереди
	QU.Show();
	// добавление элемента
	QU.Add(22222);
	QU.Show();
}
#include <fstream> // для обеспечения файлового ввода-вывода
#include <iostream> //для консольного ввода-вывода
#include <cstring> //для строковой функции strcpy
#include <conio.h> // для функции getch()
#include <iomanip> //для функции setw()
 
using namespace std;
 
struct Worker // Объявление структуры worker
{
    char name[25]; // имя сотрудника
    int age; // возраст сотрудника
    char position[25]; // должность
    int experience; // стаж сотрудника
    double wages; // текущая заработная плата
};
 
void f1(const char* name_of_file, Worker* mas, int n);
void f2 (Worker* mas, int n);
void f3 (Worker* mas, int n);
void f4 (Worker* mas);
void f5 (Worker* mas, int n);
void f6 (Worker* mas, int n);
 
int main()
{
    setlocale(LC_ALL, "Russian");
 
    int D; //пункт меню
    char choise;
 
    const int n = 6;
    Worker mas[n]; // Объявление массива mas для хранения 6 структур Worker
 
    // В переменную name_of_file сохраняется месторасположение текстового файла project.txt
    const char *name_of_file = "C:\\Users\\Kseniya Melekh\\Desktop\\БГУ ИБМТ\\Основы алгоритмизациии и программирование\\Проект\\project.txt";
 
    while (true)
    {
        cout << "Выберите действие: " << endl;
        cout << "1 - Вввод данных из файла. " << endl;
        cout << "2 - Вывод данных на экран. " << endl;
        cout << "3 - Вывести сотрудников, у которых стаж работы более n лет " << endl;
        cout << "4 - Вывести заработную плату кажддого сотрудника за весь период работы. " << endl;
        cout << "5 - Рассчитать общую сумму заработной платы всех сотрудников за весь период работы" << endl;
        cout << "6 - Вывести возраст самого младшего и самого старшего сотрудника. " << endl;
        cout << endl;
        cin >> D;
        cout << endl;
        cout << endl;
 
        switch (D)
        {
        case 1:
        {
            f1(name_of_file, mas, n);
            break;
 
        }
 
        case 2:
        {
            f2(mas, n);
            break;
        }
 
        case 3:
        {
            f3 (mas, n);
            break;
        }
 
        case 4:
        {
            f4 (mas);
            break;
        }
 
 
        case 5:
        {
            f5 (mas, n);
            break;
        }
 
        case 6:
        {
            f6 (mas, n);
            break;
        }
 
 
        default:
        {
            cout << "Попробуйте еще раз!" << endl;
            break;
        }
        }
    }
 
 
    _getch();
    return 0;
}
 
void f1(const char* name_of_file, Worker* mas, int n)
{
 
    ifstream fin; // Создаем экземпляр потока с именем fin, используя специализацию ifstream
 
    fin.open(name_of_file); //  Открытие файла project.txt
 
 
    if (!fin.is_open())
    {
        cout << "Can't open file!!!" << endl; // Сообщение выдается, если файл не открылся
    }
    else //блок else работает, если файл успешно открылся
    {
 
        for (int i = 0; i< n; i++) //Присваивание значений,считываемых из файла полям объектов массива
        {
            fin >> mas[i].name;
            fin >> mas[i].position;
            fin >> mas[i].age;
            fin >> mas[i].experience;
            fin >> mas[i].wages;
 
        }
 
        if (!fin.good())
        {
            cout << "ERR of reading been done!!" << endl;
        }
 
        fin.close(); // закрытие текстового файла
 
    }
}
 
void f2(Worker* mas, int n)
{
    char zagl[5][15] = { "Name", "Position", "Age", "Experience", "Wages"};
 
    for (int i = 0; i<6; i++)
    {
        cout << setw(20) << zagl[i]; // Вывод заголовков столбцов таблицы
    }
    cout << endl;
 
    for (int i = 0; i<n; i++) // Вывод значений полей структур
    {
        cout << setw(20) << mas[i].name; //Вывод имени сотрудника
        cout << setw(20) << mas[i].position; //Вывод должности сотрудника
        cout << setw(20) << mas[i].age; // Возрвст сотрудника
        cout << setw(20) << mas[i].experience; //Вывод стажа сотрудника
        cout << setw(20) << mas[i].wages; //Вывод заработной платы сотрудника
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
 
void f3 (Worker* mas, int n)
{
    int e; //стаж (лет)
    cout << "Введите стаж работы: ";
    cin >> e;
    cout << endl;
    cout << "Cотрудники, у которых стаж работы более " << e << " лет: ";
 
    for (int i = 0; i < n; i ++)
    {
        if (mas[i].experience > e)
        {
            cout << mas[i].name << "; ";
        }
    }
    cout << endl;
    cout << endl;
    cout << endl;
}
 
void f4 (Worker* mas)
{
    char zagl[3][15] = { "Name", "Position", "Total wages"};
 
    for (int i = 0; i< 3; i++)
    {
        cout << setw(20) << zagl[i]; // Вывод заголовков столбцов таблицы
    }
    cout << endl;
    cout << endl;
 
    for (int i = 0; i< 3; i++) // Вывод значений полей структур
    {
        cout << setw(20) << mas[i].name; //Вывод имени сотрудника
        cout << setw(20) << mas[i].position; //Вывод должности сотрудника
        cout << setw(20) << mas[i].experience * mas[i].wages; // Вывод заработной платы сотрудника за весь период работы в компании
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
 
void f5 (Worker* mas, int n)
{
    double sum_total = 0;
    for (int i = 0; i < n; i++) // Вывод значений полей структур
    {
        sum_total += mas[i].experience * mas[i].wages; // Вывод заработной платы сотрудниов за весь период работы в компании
    }
    cout << "Общая сумма заработной платы всех сотрудников за весь период работы составляет: " << sum_total << " $" << endl;
    cout << endl;
    cout << endl;
}
 
void f6 (Worker* mas, int n)
{
    int s = 0;
 
    for(int i = 0; i< n-1; i++)
    {
        for (int j = 0; j< n - i - 1; j++)
        {
            if(mas[j].age > mas[j+1].age)
            {
                s = mas[j].age;
                mas[j].age = mas[j+1].age;
                mas[j+1].age = s;
            }
        }
    }
 
    cout << "Возраст самого младшего сотрудника " << mas[0].age << " лет" << " и самого старшего " << mas[5].age << " лет." <<endl;
    cout << endl;
    cout << endl;
}
 
 




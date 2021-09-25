#include <iostream>
#include "MyLib.h"
#include <fstream>




#define TRUEORFALSE(vvedenoe_chislo, konechnoe_chislo) ((vvedenoe_chislo >= 0 && vvedenoe_chislo < konechnoe_chislo)) //ко 2-рому заданию
#define ZADAEM_CHISLO(n, e_byte)

using namespace std;



void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}



#pragma pack(push, 1)
struct SOTRUDNIK //структура для 4-того задания.
{
    char SotFullName[255];   //ФИО сотрудника
    char SotStreet[255];     //Улица сотрудника
    short SotHouse;          //Номер дома сотрудника
    short SotFlat;           //Номер квартиры сотрудника
    char SotPhone;           //Телефон сотрудника
};
#pragma pack(pop)





int main()
{
    {
        /*HOMEWORK1
          Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
          mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
          для инициализации массива (типа float), печати его на экран и
          подсчета количества отрицательных и положительных
          элементов. Вызывайте эти 3-и функции из main для работы с
          массивом.
        */
        obzac();


        const int size = 4;
        float* ptr = 0;
        ptr = MyLib::f1(size);
        MyLib::f2(ptr, size);

        delete[]ptr;

    }

    {
        /*HOMEWORK2
          Описать макрокоманду (через директиву define), 
          проверяющую, входит ли переданное ей число (введенное с 
          клавиатуры) в диапазон от нуля (включительно) до переданного 
          ей второго аргумента (исключительно) и возвращает true или 
          false, вывести на экран «true» или «false».
        */
        obzac();

        int n_nnoe_chislo;
        const int MULTIOTREZOK = 666;
        cout << boolalpha; //стандартная команда, которая благодаря вызову bool выводит тебе тру, либо фалс.
        cout << "Введи число, которое хочешь проверить: " << endl;
        cin >> n_nnoe_chislo;
        bool proveryaemoe_chislo = TRUEORFALSE(n_nnoe_chislo, MULTIOTREZOK);
        cout << "Твой результат: " << proveryaemoe_chislo << endl;


    }
    
    {
        /*HOMEWORK3
          Задайте массив типа int. Пусть его размер задается через 
          директиву препроцессора #define. Инициализируйте его через 
          ввод с клавиатуры. Напишите для него свою функцию 
          сортировки (например Пузырьком). Реализуйте перестановку 
          элементов как макрокоманду SwapINT(a, b). Вызывайте ее из 
          цикла сортировки.
        */
        obzac();
        
        ZADAEM_CHISLO(n, e_byte)
        int* e_byte;  
        int n;
        cout << "лупани число своё: ";
        cin >> n;
        e_byte = new int[n];
        
        //выделение памяти под массив
        for (int i = 0; i < n; i++)
        {
            cout << "e_byte[" << i << "] = ";
            cin >> e_byte[i];
        }
        int temp; // временная переменная для обмена элементов местами

        // Сортировка массива пузырьком
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (e_byte[j] > e_byte[j + 1]) 
                {
                    // меняем элементы местами
                    temp = e_byte[j];
                    e_byte[j] = e_byte[j + 1];
                    e_byte[j + 1] = temp;
                }
            }
        }

        // Вывод отсортированного массива на экран
        for (int i = 0; i < n; i++) {
            cout << e_byte[i] << " ";
        }
        cout << endl;

        delete[] e_byte; // освобождение памяти;

    }
    
    {
        /*HOMEWORK4
          Объявить структуру Сотрудник с различными полями. 
          Сделайте для нее побайтовое выравнивание с помощью 
          директивы pragma pack. Выделите динамически переменную 
          этого типа. Инициализируйте ее. Выведите ее на экран и ее 
          размер с помощью sizeof. Сохраните эту структуру в текстовый 
          файл.
        */
        obzac();

        auto *kolejanka = new SOTRUDNIK; //"колежанка" это конкретная вещь(феррари допустим), а "Сотрудник" это общедостпуное понятие(машина допустим).
        cout << "Размер твоего файла: " << sizeof(SOTRUDNIK) << " bytes" << endl; //выводим размер "коленжанки"

        string path = "sotrudnik.txt";
        ofstream fout;
        fout.open(path);
        if (!fout.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }
        else
        {
            string SOTRUDNIK;
            fout << &kolejanka; 
        }
        fout.close();
        delete kolejanka;
        //есть общее понятие, допустим "машина", ей свойственны свойства и функции по общедоступному определению.
        //а есть конкретная марка машины, в данном случае, которую мы запихиваем в файл, чтобы что-либо получить в txt-документе.
    }
    return 0;
}

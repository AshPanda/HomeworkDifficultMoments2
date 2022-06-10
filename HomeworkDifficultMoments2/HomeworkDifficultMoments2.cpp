/*
1.Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает
местами значения, на которые указывают эти указатели (нужно обменивать именно сами
указатели, переменные должны оставаться в тех же адресах памяти).
2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
сортирует указатели по значениям, на которые они указывают.
3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4
способа:
○ count_if и find
○ count_if и цикл for
○ цикл for и find
○ 2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>
#include <string_view>

using namespace std;

//Task #1
template < typename T >
void Swap(T& first, T& second)
{
    T temp(first);
    first = second;
    second = temp;
}
//Task #2
template < typename T >
void SortPointers(T& first)
{
    sort(first.begin(), first.end());

}
//Task #3

class Book
{
public:
    Book(ifstream& file) {
        if (file.is_open())
        {
            cout << "Vowels in the book 'War_and_peace':" << endl;
            Timer timer("2 cycles FOR");
            value = 0;
            while (!file.eof())
            {
                getline(file, fullBook);
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < fullBook.length(); j++) {
                        if (tolower(fullBook[j]) == vowel[i]) value++;

                    }


                }
                
            }
            cout << value << endl;
            timer.print();
            file.close();
            cout << "\n" << endl;
        }
        else
        {
            cout << "Error. Can't open file!" << endl;
        }
    }
protected:
    int value;
    string fullBook;
    char vowel[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };
    int n = sizeof(vowel) / sizeof(vowel[0]);
};


int main()
{
    cout << "Task #1" << endl;
    int* ptr1;
    int* ptr2;
    int a = 100;
    int b = 400;
    ptr1 = &a;
    ptr2 = &b;
    cout << "Memory location of  A = " << &a << endl;
    cout << "Memory location of  B = " << &b << endl;
    cout <<"Memory location of pointer 1 = " << ptr1 << endl;
    cout <<"Memory location of pointer 2 = " << ptr2 << endl;
    Swap(ptr1, ptr2);
    cout << "=====Swap pointers=====" << endl;
    cout << "Memory location of  A = " << &a << endl;
    cout << "Memory location of  B = " << &b << endl;
    cout << "Memory location of pointer 1 after swap = " << ptr1 << endl;
    cout << "Memory location of pointer 2 after swap = " << ptr2 << endl;
    cout << "\n" << endl;
    cout << "Task #2" << endl;
    const int N = 5;
    vector<int> task2(N);
    srand(time(0));
    for (auto i = 0; i < N; i++) {
        task2[i] = rand() % 300;
        cout << task2[i] << " ";
    }
    cout << "\n" << endl;
    SortPointers(task2);
    for (auto i = 0; i < N; i++) {
        cout << task2[i] << " ";
    }
    cout << "\n" << endl;
    cout << "Task #3" << endl;
    ifstream file("D:\\GeekBrains\\Semester1\\Diff\\homework\\HomeworkDifficultMoments2\\HomeworkDifficultMoments2\\HomeworkDifficultMoments2\\War_and_peace.txt");
    Book book(file);

}



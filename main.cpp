//  Поиск подстрок с помощью конечных автоматов

// war-peace.txt             "the" 47327 1.396798 сек
// Master and Margarita.txt  "the" 7217 0.182398 сек
// text.txt                  "the" 26 0.00314 сек

#include <ctime>
#include "search_substring.h"

int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "ru");
    time_t start = clock();
    string p;
    cout<<"Введите подстроку: ";
    cin >> p;
    cout << "Количество вхождений \"" << p << "\": " << allcomputing("war-peace.txt", p) << endl;
    cout.precision(10);
    cout << double(clock() - start) / CLOCKS_PER_SEC << " сек" << endl;
    system("pause");
}

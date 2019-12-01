/**
 * Так как перехват нажатий специфичен для каждой платформы, то 
 * реализация универсального метода для выполнения этой задачи нет. 
 * Ранее в стандарт входила библиотека conio.h с функцией getch, 
 * который позволял перехватывать нажатия, но сейчас в стандарте ее 
 * нет и она не используется. 
 * 
 * Поэтому прошу принять упрощенный вариант задачи, в котором слова,
 * оканчивающиеся на гласные выделяются сразу. Для реализация
 * первоначальной задачи требуется аналог getch, а выделение 
 * выполняется с помощью esc-последовательностей перемещать курсор к 
 * нужным словам и выделять их заново выводя слово. Код в комментариях
 * это мои попытки выполнить эту задачу. В массив мы записывали 
 * индексы и в другой массив слова. При помощи этих массивов мы бы
 * перемещались к нужному слову и выделяли его.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    system("clear");
    ifstream file;
    file.open("lorem.dat");
    // int vowel_ind[1000];
    // string vowel[1000];

    if (!file.is_open())
    {
        cout << "Ошибка чтения файла\n";
        return 1;
    }

    string word;
    int count = 0;
    int index = 0;
    int it = 0;
    while (file >> word)
    {
        bool flag = false;
        char ch;
        if (word[word.length() - 1] == '.' || word[word.length() - 1] == ',')
        {
            ch = word[word.length() - 2];
        }
        else
        {
            ch = word[word.length() - 1];
        }
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            count++;
            // vowel_ind[it] = index;
            // vowel[it] = word;
            it++;
            flag = true;
        default:
            index += word.length();
            break;
        }
        if (flag)
        {
            cout << "\x1b[7m" << word << "\x1b[0m" << ' ';
        }
        else
        {
            cout << word << ' ';
        }
    }
    cout << "\nКол-во слов оканчивающихся гласной: " << count << endl;
    // for (int i = 0; i < it; ++i)
    // {
    //     cout << vowel_ind[i] << ' ' << vowel[i] << '\n';
    // }
    // cout << endl;
    // cout << "Нажмите любую клавишу для перемещения" << endl;
    // cout << "\x1b[H" << flush;
    // char a;
    // for (int i = 0; i < it; ++i)
    // {
    //     cout << "\x1b[7m" << vowel[i] << "\x1b[0m" << flush;
    // }

    return 0;
}

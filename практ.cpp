#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    //Задание 1. Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных 
    // со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.

    cout << "Задание 1:" << endl;
    cout << sizeof(int) << " байт(ов) занимает int" << endl;
    cout << sizeof(short int) << " байт(ов) занимает short int" << endl;
    cout << sizeof(long int) << " байт(ов) занимает long int" << endl;
    cout << sizeof(float) << " байт(ов) занимает float" << endl;
    cout << sizeof(double) << " байт(ов) занимает double" << endl;
    cout << sizeof(long double) << " байт(ов) занимает long double" << endl;
    cout << sizeof(char) << " байт(ов) занимает char" << endl;
    cout << sizeof(bool) << " байт(ов) занимает bool" << endl;

    //Задание 2. Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе 
    // необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
    
    cout << '\n';
    cout << "Задание 2:" << endl;
    cout << "Значение: ";
    int intValue;
    cin >> intValue;
    int order = sizeof(int) * 8;
    unsigned int mask = 1 << (order - 1);

    cout << "Вывод: ";
    for (int i = 0; i < order; i++) {
        if (intValue & (mask >> i)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        if ((i == 0) or (i == 7) or (i == 15) or (i == 23)) {
            cout << ' ';
        }
    }
    cout << endl;

    //Задание 3. Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе 
    // необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
    
    cout << '\n';
    cout << "Задание 3:" << endl;
    union {
        int intValue2;
        float floatValue2;
    };
    cout << "Значение: ";
    cin >> floatValue2;
    unsigned int order2 = sizeof(float) * 8;
    unsigned int mask2 = 1 << (order2 - 1);

    cout << "Вывод: ";
    for (int i = 0; i < order2; i++) {
        if (intValue2 & (mask2 >> i)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        if ((i == 0) or (i == 8)) {
            cout << ' ';
        }
    }
    cout << endl;

    // Задание 4. Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе 
    // необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
   
    cout << '\n';
    cout << "Задание 4:" << endl;
    union {
        double doubleValue3;
        unsigned int Val[2];
    };
    cout << "Значение: ";
    cin >> doubleValue3;
    unsigned int order3 = sizeof(double) * 8;
    unsigned int mask3 = 1 << (order3 - 1);

    cout << "Вывод: ";
    for (int i = 0; i < 32; i++) {
        if (Val[1] & (mask3 >> i)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        if ((i == 11) or (i == 0)) {
            cout << ' ';
        }
    }
    for (int i = 32; i < 64; i++) {
        if (Val[0] & (mask3 >> i)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << endl;

    // Номер 5.1 Реализовать возможность произвольного изменения любого бита в 
    // введенном числе (для int) с использованием логических операций.

    cout << '\n';
    cout << "Задание 5.1:" << endl;
    int intValue4, numBit1, newBit1, newValue1;
    cout << "Значение(int): ";
    cin >> intValue4;
    cout << "Номер бита для изменения: ";
    cin >> numBit1;
    cout << "Новое значения для бита ";
    cin >> newBit1;
    unsigned int mask4 = 1 << (numBit1 - 1);
    if (intValue4 & mask4) {
        newValue1 = intValue4 & ~mask4;
    }
    else {
        newValue1 = intValue4 | mask4;
    }
    cout << "Новое значение: " << newValue1 << endl;

    //Задание 11. Проверка на степень двойки. Установите все биты числа в 0, 
    //если оно не является степенью двойки (число n является степенью 
    //двойки, если (n & (n-1)) == 0 и n != 0). Если является — оставьте без изменения.
    
    cout << '\n';
    cout << "Задание 11:" << endl;
    int num;
    cout << "Значение: ";
    cin >> num;
    unsigned int order11 = sizeof(int) * 8;

    if (((num & (num - 1)) == 0) and (num != 0)) {
        cout << num << " является степенью двойки";
    }
    else {
        cout << num << " не является степенью двойки ";
        for (int i = 0; i < order11; i++) {
            if (num & (1 << i)) {
                num = num & ~(1 << i);
            }
        }
        cout << num;
    }
    cout << endl;
}

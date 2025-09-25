#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomNumbers(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 10 + 1; // Генерация числа от 1 до 10
        file << randomNumber;
        if (i < 9) {
            file << " "; // Добавляем пробел между числами, кроме последнего
        }
    }

    file.close();
}

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Создание трех файлов с случайными числами
    generateRandomNumbers("file1.txt");
    generateRandomNumbers("file2.txt");
    generateRandomNumbers("file3.txt");

    cout << "Файлы успешно созданы!" << endl;

    return 0;
}

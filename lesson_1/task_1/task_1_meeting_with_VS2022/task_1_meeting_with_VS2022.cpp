#include <iostream>
#include <fstream>
#include <string>


void shiftRight(int arr[], int size) {
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void shiftLeft(int arr[], int size) {
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

int main()
{
    std::string line;
    std::ifstream fin("in.txt");
    int size_n{}, size_m{};

    setlocale(LC_ALL, "Russian");

    if (!fin.is_open()) {
        std::cout << "Файл не найден!\n";
        return EXIT_FAILURE;
    }

    fin >> line;
    size_n = std::stoi(line);

    int* arr_n = new int[size_n];

    for (int i = 0; i < size_n; ++i) {
        fin >> line;
        arr_n[i] = std::stoi(line);
    }

    fin >> line;
    size_m = std::stoi(line);

    int* arr_m = new int[size_m];

    for (int i = 0; i < size_m; ++i) {
        fin >> line;
        arr_m[i] = std::stoi(line);
    }

    fin.close();

    shiftLeft(arr_n, size_n);
    shiftRight(arr_m, size_m);

    std::ofstream fout("out.txt");

    fout << size_m << '\n';

    for (int i = 0; i < size_m; ++i) {
        fout << arr_m[i] << " ";
    }

    fout << '\n';

    fout << size_n << '\n';

    for (int i = 0; i < size_n; ++i) {
        fout << arr_n[i] << " ";
    }

    fout.close();

    delete[] arr_n;
    delete[] arr_m;

    return EXIT_SUCCESS;
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

void disp(const std::vector<double>& arr) {
    for (double x : arr) {
        std::cout << std::fixed << std::setprecision(3) << x << " ";
    }
    std::cout << std::endl;
}

void add_element(std::vector<double>& arr) {
    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    arr.push_back(sum);
    arr.push_back(avg);
}

void min_multiply(std::vector<double>& arr) {
    double min = *std::min_element(arr.begin(), arr.end());
    for (double& x : arr) {
        x *= min;
    }
}

int menu(std::vector<double>& arr) {
    int choice;
    while (true) {
        std::cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1:
            double elem;
            std::cin >> elem;
            arr.push_back(elem);
            std::cout << "+: " << arr.size() << std::endl;
            disp(arr);
            add_element(arr);
            disp(arr);
            min_multiply(arr);
            disp(arr);
            break;
        case 2:
            if (!arr.empty()) {
                arr.pop_back();
                std::cout << "-: " << arr.size() << std::endl;
                disp(arr);
                add_element(arr);
                disp(arr);
                min_multiply(arr);
                disp(arr);
            }
            else {
                std::cout << "Массив пуст, удаление невозможно." << std::endl;
            }
            break;
        default:
            std::cout << "Неверный выбор действия. Попробуйте еще раз." << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cin >> n;
    std::vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << n << std::endl;
    disp(arr);
    add_element(arr);
    disp(arr);
    min_multiply(arr);
    disp(arr);
    menu(arr);
    return 0;
}

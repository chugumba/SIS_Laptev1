#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;

void disp(const vector<double>& arr) {
    for (double x : arr) {
        cout << fixed << setprecision(3) << x << " ";
    }
    cout << endl;
}

void add_element(vector<double>& arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    arr.push_back(sum);
    arr.push_back(avg);
}

void min_multiply(vector<double>& arr) {
    double min = *min_element(arr.begin(), arr.end());
    for (double& x : arr) {
        x *= min;
    }
}

int menu(vector<double>& arr) {
    int choice;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1:
            double elem;
            cin >> elem;
            arr.push_back(elem);
            cout << "+: " << arr.size() << endl;
            disp(arr);
            add_element(arr);
            disp(arr);
            min_multiply(arr);
            disp(arr);
            break;
        case 2:
            if (!arr.empty()) {
                arr.pop_back();
                cout << "-: " << arr.size() << endl;
                disp(arr);
                add_element(arr);
                disp(arr);
                min_multiply(arr);
                disp(arr);
            }
            else {
                cout << "Массив пуст, удаление невозможно." << endl;
            }
            break;
        default:
            cout << "Неверный выбор действия. Попробуйте еще раз." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << n << endl;
    disp(arr);
    add_element(arr);
    disp(arr);
    min_multiply(arr);
    disp(arr);
    menu(arr);
    return 0;
}

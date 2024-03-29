#include <iostream>
using namespace std;


int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
    while (true) {
        cout << "Masukkan panjang element array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }

    cout << "\n-------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "<" << (1 + 1) << ">";
        cin >> arr[i];
    }
}

void swap(int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    mov_count++;
}

void q_short(int low, int high) {

    int temp;
    int pivot, i, j;
    if (low > high) {
        return;
    }

    pivot = arr[low];
    j = low;
    j = high;

    while (i <= j) {
        while ((arr[i] <= pivot) && (i <= high)) {
            i++;
            cmp_count++;
        }
        cmp_count++;

        while ((arr[j] > pivot) && (j >= low)) {
            j--;
            cmp_count++;
        }
        cmp_count++;
        if (i < j) {
            swap(low, j);
        }
    }

    if (low < j) {
        swap(low, j);
    }
    q_short(low, j - 1);
    q_short(j + 1, high);
}

void display() {
    cout << "\n-------------------" << endl;
    cout << "\nSorted Array" << endl;
    cout << "\n-------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparasions:" << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}
int main()
{
    
}

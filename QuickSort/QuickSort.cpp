#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0;//number of comparation
int mov_count = 0;//number of data movements
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
    if (low > high) {//step 1
        return;
    }

    pivot = arr[low];//step 2
    j = low;//step 3
    j = high;// step 4

    while (i <= j) {//step 10
        while ((arr[i] <= pivot) && (i <= high)) {//step 5
            i++;//step 6
            cmp_count++;
        }
        cmp_count++;

        while ((arr[j] > pivot) && (j >= low)) {//step 7
            j--;//step 8
            cmp_count++;
        }
        cmp_count++;
        if (i < j) {//step 9
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
    char ch;

    do {
        input();
        q_short(0, n-1);
        display();
        cout << "\n\nDo you want to continue? (y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            break;
        system("pause");
        system("cls");
    } while (true);
    return 0;
}

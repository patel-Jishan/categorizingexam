#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


void printArray(vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}


int main() {
    int n, choice, key;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n), temp;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout <<  "---- MENU ----"<<endl;;
        cout << "1. Selection Sort"<<endl;
        cout << "2. Merge Sort"<<endl;;
        cout << "3. Linear Search"<<endl;
        cout << "4. Binary Search(sorted array)"<<endl;
        cout << "5. Exit";
        cout << "Enter choice: ";
        cin >> choice;

        temp = arr; 

        switch (choice) {
            case 1:
                selectionSort(temp);
                cout << "Sorted array (Selection Sort): ";
                printArray(temp);
                break;
            case 2:
                mergeSort(temp, 0, n - 1);
                cout << "Sorted array (Merge Sort): ";
                printArray(temp);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> key;
                int linIndex;
                linIndex = linearSearch(arr, key);
                if (linIndex != -1)
                    cout << "Element found at index: " << linIndex << endl;
                else
                    cout << "Element not found.\n";
                break;
            case 4:
                mergeSort(temp, 0, n - 1); 
                cout << "Sorted array: ";
                printArray(temp);
                cout << "Enter element to search: ";
                cin >> key;
                int binIndex;
                binIndex = binarySearch(temp, key);
                if (binIndex != -1)
                    cout << "Element found at index: " << binIndex << endl;
                else
                    cout << "Element not found."<<endl;
                break;
            case 5:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice."<<endl;
        }

    } while (choice != 5);

    
}
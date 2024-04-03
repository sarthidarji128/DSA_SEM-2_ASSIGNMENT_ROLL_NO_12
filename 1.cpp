#include <iostream>
using namespace std;


void display(int arr[], int n) {
    cout << "The array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void  insert_begin(int arr[], int &n, int x) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = x;
    n++;
}


void insert_end(int arr[], int &n, int x) {
    arr[n] = x;
    n++;
}

void insert_before(int arr[], int &n, int x, int y) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == y) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "The element " << y << " is not in the array.\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = x;
    n++;
}


void insert_after(int arr[], int &n, int x, int y) { 
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == y) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "The element " << y << " is not in the array.\n";
        return;
    }
    for (int i = n; i > pos+1; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos+1] = x;
    n++;
}

void delete_begin(int arr[], int &n) {
    if (n == 0) {
        cout << "The array is empty.\n";
        return;
    }
    int x = arr[0];
    for (int i = 0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "The element " << x << " is deleted from the beginning of the array.\n";
}
void delete_end(int arr[], int &n) {
    if (n == 0) {
        cout << "The array is empty.\n";
        return;
    }
    int x = arr[n-1];
    n--;
    cout << "The element " << x << " is deleted from the end of the array.\n";
}

void delete_before(int arr[], int &n, int y) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == y) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "The element " << y << " is not in the array.\n";
        return;
    }
    if (pos == 0) {
        cout << "There is no element before " << y << " in the array.\n";
        return;
    }
    int x = arr[pos-1];
    for (int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "The element " << x << " is deleted from before " << y << " in the array.\n";
}

void delete_after(int arr[], int &n, int y) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == y) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "The element " << y << " is not in the array.\n";
        return;
    }
    if (pos == n-1) {
        cout << "There is no element after " << y << " in the array.\n";
        return;
    }
    int x = arr[pos+1];
    for (int i = pos+2; i < n; i++) {
        arr[i] = arr[i-1];
    }
    n--;
    cout << "The element " << x << " is deleted from after " << y << " in the array.\n";
}
void search(int arr[], int n, int x) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "The element " << x << " is found at index " << i << " and position " << i+1 << ".\n";
            found = true;
        }
    }
    if (!found) {
        cout << "The element " << x << " is not found in the array.\n";
    }
}

void menu() {
    cout << "\n\t\tMENU :";
    cout << "\nPress 1 to display the array.";
    cout << "\nPress 2 to insert an element at the beginning of the array.";
    cout << "\nPress 3 to insert an element at the end of the array.";
    cout << "\nPress 4 to insert an element before a given element in the array.";
    cout << "\nPress 5 to insert an element after a given element in the array.";
    cout << "\nPress 6 to delete an element at the beginning of the array.";
    cout << "\nPress 7 to delete an element at the end of the array.";
    cout << "\nPress 8 to delete an element before a given element in the array.";
    cout << "\nPress 9 to delete an element after a given element in the array.";
    cout << "\nPress 10 to search an element in the array.";
    cout << "\nPress 11 to exit.\n";
}

int main() {
    
    int choice;
    int size;
    int element;
    int target;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    menu();
    cout << "Enter your choice: ";
    cin >> choice; 
    while (choice != 11) {
        switch (choice) {
            case 1:
                display(arr, size);
                break;
            case 2:
                cout << "Enter the element to be inserted at the beginning: ";
                cin >> element;
                insert_begin(arr, size, element);
                break;
            case 3:
                cout << "Enter the element to be inserted at the end: ";
                cin >> element;
                insert_end(arr, size, element);
                break;
            case 4:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                cout << "Enter the element before which the insertion is to be done: ";
                cin >> target;
                insert_before(arr, size, element, target);
                break;
            case 5:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                cout << "Enter the element after which the insertion is to be done: ";
                cin >> target;
                insert_after(arr, size, element, target);
                break;
            case 6:
                delete_begin(arr, size);
                break;
            case 7:
                delete_end(arr, size);
                break;
            case 8:
                cout << "Enter the element before which the deletion is to be done: ";
                cin >> target;
                delete_before(arr, size, target);
                break;
            case 9:
                cout << "Enter the element after which the deletion is to be done: ";
                cin >> target;
                delete_after(arr, size, target);
                break;
            case 10:
                cout << "Enter the element to be searched: ";
                cin >> element;
                search(arr, size, element);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
    }
}
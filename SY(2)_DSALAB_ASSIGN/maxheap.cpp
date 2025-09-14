#include <iostream>
using namespace std;

class Maxarr {
public:
    int arr[1000];
    int n = 1000;
    int size;

    Maxarr() {
        size = 0;
    }

    void heapifyDelete(int i) {
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int largest = i;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDelete(largest);
        }
    }

    void heapifyInsert(int i) {
        if (i == 0) return;

        int parent = (i - 1) / 2;

        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapifyInsert(parent);
        }
    }

    void insert(int val) {
        if (size == n) {
            cout << "Heap is full\n";
            return;
        }
        arr[size] = val;
        heapifyInsert(size);
        size++;
    }

    void remove(int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Element not found.\n";
            return;
        }

        arr[index] = arr[size - 1];
        size--;

        if (index > 0 && arr[index] > arr[(index - 1) / 2]) {
            heapifyInsert(index);
        } else {
            heapifyDelete(index);
        }

        cout << "removed.\n";
    }

    void display() {
        cout << "Elements: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Maxarr h;
    int choice,val,key;

    while(1){
        cout<<"1.Insert a node \n2.Display Elements \n3.Remove Elements \n4.Exit \nEnter Choice:";
        cin>>choice;

        switch(choice){
            case 1:cout<<"Enter element to insert: ";
                    cin>>val;
                    h.insert(val);
                    break;
            case 2:h.display();
                    break;
            case 3:cout<<"Enter Element to remove: ";
                    cin>>key;
                    h.remove(key);
                    break;
            case 4:return 0;
            default:cout<<"Invalid Choice";
        }
    }

    return 0;
}

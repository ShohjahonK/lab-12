#include <iostream>
using namespace std;

namespace Problem1 {
    void execute() {
        const int SIZE = 10;
        float *ptr, arr[SIZE];
        ptr = new float[SIZE];
        cout << "Enter the grades of 10 students for the Midterm exam:" << endl;
        for (int i = 0; i < SIZE; ++i) {
            cout << "Student " << i + 1 << ": ";
            cin >> ptr[i];
        }
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = ptr[i] * 0.3f;
        }
        cout << "Midterm grades (30% of original grades) in reverse order:" << endl;
        for (int i = SIZE - 1; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] ptr;

    }
}

namespace Problem2 {
    int evenCount (const int* a, int size) {
        int count = 0;
        int i = 0;

        while (i < size) {
            if (*(a + i) % 2 == 0) {
                count++;
            }
            ++i;
        }
        return count;
    }
    void execute () {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        int* arr = new int[size];

        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        int result = evenCount(arr, size);
        cout << "Number of even numbers: " << result << endl;

        delete[] arr;
    }
}

namespace Problem3 {
    bool isMirrored(const int* a, const int* b,int size) {
        const int* bTail = b + size - 1;
        for (int i = 0; i < size; i++) {
            if (*(a + i) != *(bTail - i)) {
                return false;
            }
        }
        return true;
    }

    void execute () {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        int* arr = new int[size];
        int* arr2 = new int[size];

        cout << "Enter " << size << " elements for first array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        cout << "Enter " << size << " elements for second array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr2[i];
        }

        int result = isMirrored(arr, arr2, size);
        cout << result << endl;

        delete[] arr;
        delete[] arr2;
    }

}

namespace Problem4 {
    void sumArrays(const double* arr1,const double* arr2, double* sum,int size) {
        for (int i = 0; i < size; i++) {
            //*(sum + i) = *(arr1 + i) + *(arr2 + i);
            sum[i] = arr1[i] + arr2[i];

        }

    }

    void execute () {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        double* arr = new double[size];
        double* arr2 = new double[size];
        double* sum = new double[size];

        cout << "Enter " << size << " elements for first array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        cout << "Enter " << size << " elements for second array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr2[i];
        }


        sumArrays(arr, arr2, sum, size);

        cout << "Element-wise sum of the arrays:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << sum[i] << " ";
        }
        cout << endl;

        delete[] arr;
        delete[] arr2;
        delete[] sum;
    }
}

namespace Problem5 {
    void swap(int* arr1,int* arr2,int size) {
        for (int i =0 ; i < size; i++) {
            int temp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = temp;
        }
    }
    void execute() {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        int* arr = new int[size];
        int* arr2 = new int[size];

        cout << "Enter " << size << " elements for first array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        cout << "Enter " << size << " elements for second array:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr2[i];
        }


        swap(arr, arr2, size);

        cout << "First array after swap:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;


        cout << "Second array after swap:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << arr2[i] << " ";
        }
        cout << endl;

        delete[] arr;
        delete[] arr2;

    }
}

namespace Problem6 {
    bool is_in(const int* arr1,const int* arr2, int size1,int size2){
        const int *p1=arr1;
        const int *p2=arr2;
        for (int i = 0; i < size1; i++) {
            bool found = false;
            p2 = arr2;
            for (int j = 0; j < size2; j++) {
                if (p1[i] == p2[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    void execute () {
        int size1;
        cout << "Enter the size of the first array: ";
        cin >> size1;

        int* arr = new int[size1];

        cout << "Enter " << size1 << " elements for first array:" << endl;
        for (int i = 0; i < size1; ++i) {
            cin >> arr[i];
        }
        int size2;
        cout << "Enter the size of the second array: ";
        cin >> size2;

        int* arr2 = new int[size2];



        cout << "Enter " << size2 << " elements for second array:" << endl;
        for (int i = 0; i < size2; ++i) {
            cin >> arr2[i];
        }


        if (is_in(arr, arr2, size1, size2)) {
            cout << "All elements of the first array are present in the second array." << endl;
        } else {
            cout << "Not all elements of the first array are present in the second array." << endl;
        }

        delete[] arr;
        delete[] arr2;
    }
}

namespace Problem7 {
    void power(double* n,const int* p) {
        double result = 1.0;
        int exponent = *p;
        double base = *n;

        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }

        *n = result;
    }
    void execute() {
        double base;
        int exponent;

        cout << "Enter the base number: ";
        cin >> base;

        cout << "Enter the exponent: ";
        cin >> exponent;

        power(&base, &exponent);

        cout << "The result is: " << base << endl;

    }
}

namespace Problem8 {
    vector < int > addOne(vector < int > &v) {
        int carry = 1;  // Start with the carry set to 1 because we are adding one

        for (int i = v.size() - 1; i >= 0; --i) {
            int newValue = v[i] + carry;
            v[i] = newValue % 10;  // Update the digit to the new value mod 10
            carry = newValue / 10;  // Calculate the carry for the next iteration

            // If there's no carry, we can exit the loop early
            if (carry == 0) {
                return v;
            }
        }

        // If there's still a carry after processing all digits, add a new digit
        if (carry) {
            v.insert(v.begin(), carry);
        }
    }

    void printVector(const vector<int> &v) {
        for (int i = 0; i <= v.size() - 1 ; i++) {
            cout << v[i];
        }
        cout << endl;
    }

    void execute() {
        vector<int> v;
        int digit;
        cout << "Enter the digits of the number from right to left (enter -1 to end): ";

        while (true) {
            cin >> digit;
            if (digit == -1) {
                break;
            }
            v.push_back(digit);
        }

        cout << "Original number: ";
        printVector(v);

        addOne(v);

        cout << "Number after adding one: ";
        printVector(v);

    }
}

int main() {
    Problem8::execute();
    return 0;
}

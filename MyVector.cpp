#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//默认为int型
class MyVector
{
private:
    int *arr;
    int len;
    int Maxlen;
public: 
    MyVector():arr(NULL) {
        len = 0;
        Maxlen = 0;
        cout << "MyVector construction" << endl;
    }

    MyVector(MyVector &v) {
        if(!v.arr) {
            arr = NULL;
            len = 0;
            return;
        }
        arr = new int[v.len];
        memcpy(arr, v.arr, sizeof(int)*v.len);
        len = v.len;
    }

    int length() {
        return len;
    }

    int & operator[](const int n) {
        if(n < len) { return arr[n];}
    }

    MyVector & operator=(const MyVector &v) {
        if(arr == v.arr) return *this;
        if(arr) {
            delete []arr;
            len = 0;
        }

        if(v.arr) {
            cout << *v.arr << endl;
            arr = new int [v.len];
            memcpy(arr, v.arr, sizeof(int)*len);
            len = v.len;
        }
        else {
            if(arr) delete []arr;
            arr = NULL;
            len = 0;
        }
        return *this;
    }

    MyVector &push_back(int n) {
        if(len < Maxlen) {
            len++;
            *(arr+len-1)=n;
        }
        else {
            if(Maxlen == 0)Maxlen=1;
            else {
                Maxlen *= 2;
            }
            int *temp = new int[Maxlen];
            if(len) {
                memcpy(temp, arr, sizeof(int)*len);
            }
            arr = temp;
            len++;
            *(arr+len-1)=n;
        }
        return *this;
    }

    ~MyVector() {
        if(arr) delete []arr;
    }
};

int main() {
    MyVector v;

    for(int i=2;i<9;i++) {
        v.push_back(i);
    }

    MyVector v2 = v;

    v[0] = 100;
     cout << "v =  ";
    for(int i=0; i< v.length(); i++)
        cout << v[i] << " ";
    cout << endl;

    cout << "v2 =  ";
    for(int i=0; i< v2.length(); i++)
        cout << v2[i] << " ";

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n=10, m=10, c = 0;

    

    int *a  = new int[n * m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i * n + j] = ++c;
int z=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << "\t" << a[z],z++;
        cout << endl;
    }
}
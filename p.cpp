#include <iostream>

using namespace std;

void nextij(long n,long m,long& i,long& j) {
    if (i==n-1) { //bottom row
        if (j<n-1) { //in the left square
            j = i+j+1;
            i = 0;
        }
        else { //out of the left square
            i = j-(n-1)+1;
            j = m-1;
        }
    }
    else { //other rows
        if (j==0) { //left most column
            j = i+1;
            i = 0;
        }
        else { //other columns
            i++;
            j--;
        }
    }
}

int main() {
    long n = 3;
    long m = 5;
    long a[3][5];  

    long i = 0;
    long j = 0;
    long c = 1;

    while (c<=n*m) {
        a[i][j] = c;        
        nextij(n,m,i,j);
        c++;        
    }

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++)
            cout <<a[i][j] <<" ";
        cout <<endl;
    }
}
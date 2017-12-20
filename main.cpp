#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,i,j,a,b;

    cout << "Enter 2D matrix size:"<< endl;
    cin >> a >> b;
    int **matrix = new int*[a];
    for (i = 0; i < a; i++){
        matrix[i] = new int [b];
    }
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix complete, enter number:" << endl;
    cin >> n;
    int t;
    for(int z = 0; z < n; z++) {
        i = j = t = 0;
        for (int k = 0; k < a * b ; k++) {
            swap(matrix[t][t], matrix[i][j]);
            if (i == t && j != b - 1 - t) {
                j++;
                continue;
            }
            if (i == t && j == b - 1 - t) {
                i++;
                continue;
            }
            if (j == b - 1 - t && i != a - 1 - t) {
                i++;
                continue;
            }
            if (j == b - 1 - t && i == a - 1 - t) {
                j--;
                continue;
            }
            if (i == a - 1 - t && j != t) {
                j--;
                continue;
            }
            if (i == a - 1 - t && j == t) {
                i--;
                continue;
            }
            if (j == t && i != t + 1) {
                i--;
                continue;
            }
            if (j == t && i == t + 1) {
                j++;
                t++;
                continue;
            }
        }
    }

    for( i = 0 ; i < a ; i++ )
    {
        for( j=0; j < b ; j++)
            cout << setw(5) <<matrix[i][j] ;
        cout << endl;
    }
    for (i = 0; i < a; i++)
        delete []matrix[i];


    return 0;
}

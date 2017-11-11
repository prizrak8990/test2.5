#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k, l, t, z, b, v;
    cout << "Enter 2D matrix size:" << endl;
    cin >> k >> l;
    int** a = new int*[k];
    for (int count = 0; count < k; count++) {
        a[count] = new int[l];
    }
    for (int row = 0; row < k; row++) {
        for (int col = 0; col < l; col++) {
            cin >> a[row][col];
        }
    }

    cout << "Matrix complete, enter number:" << endl;
    cin >> n;
    i = j = z = 0;
    cout << "calculating..." << endl;
    for (b = 0; b < k / 2; b++) {
        for (t = 0; t < n; t++) {
            for (v = 0; v < (k - z) * (k - z) - (k - z - 1) * (k - z - 1); v++) {
                swap(a[z][z], a[i][j]);
                if (i == z && j == l - 1 - z) {
                    i++;
                    continue;
                }
                else if (i == z) {
                    j++;
                    continue;
                }

                if (i == k - 1 - z && j == l - 1 - z) {
                    j--;
                    continue;
                }
                else if (j == l - 1 - z) {
                    i++;
                    continue;
                }

                if (i == k - 1 - z && j == z) {
                    i--;
                    continue;
                }
                else if (i == k - 1 - z) {
                    j--;
                    continue;
                }

                if (i == z + 1 && j == z) {
                    if (t == n - 1 && z < k / 2) {
                        z++;
                        t = -1;
                    }
               continue;
                }
                else if (j == z) {
                    i--;
                    continue;
                }
            }
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int count = 0; count < k; count++)
        delete[] a[count];

    cout << "end prog" << endl;

    return 0;
}

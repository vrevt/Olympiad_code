#include <iostream>
 
using namespace std;
 
void calc(int * a, int n, int &pr, int *kol) {
    pr = 1;
    for (int i = 0; i < n; i++) {
        pr *= a[i];
        if (a[i] < 0 && a[i] % 2 != 0) {
            ++(*kol);
        }
    }
}
 
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
 
    int kol = 0;
    int pr = 1;
 
    calc(a, n, pr, &kol);
 
    cout << pr << endl;
    cout << kol << endl;
 
    delete a;
}

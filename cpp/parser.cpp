#include <iostream>
#include <fstream>
#include <cstring>
 
using namespace std;
 
int main() {
    ifstream fin("1.txt");
    char* a = new char[30001];
    char* b = new char[30001];
    int n, res;
    fin >> n;
    fin.getline(a, 30001);
    int kol;
    while (n--) {
        fin.getline(a, 30001);
        kol = 0;
        res = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] == ':') {
                if (i < strlen(a)-1) {
                    if (a[i+1] == '(' || a[i+1] == '{' || a[i+1] == ')' || a[i+1] == '[' || a[i+1] == ']' || a[i+1] == '}')a[i+1] = '.';
                }
            }
            if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
                kol ++;
                b[kol] = a[i];
            }
 
            if (a[i] == ')') {
                if (kol == 0 && res == 0) {
                    res = 1;
                } else
                if (b[kol] == '(') {
                    kol --;
                } else {
                    if (res == 0) res = 2;
                }
            }
 
            if (a[i] == '}') {
                if (kol == 0 && res == 0) {
                    res = 1;
                } else
                if (b[kol] == '{') {
                    kol --;
                } else {
                    if (res == 0) res = 2;
                }
            }
 
            if (a[i] == ']') {
                if (kol == 0 && res == 0) {
                    res = 1;
                } else
                if (b[kol] == '[') {
                    kol --;
                } else {
                    if (res == 0) res = 2;
                }
            }
        }
        if (res!=0){
            cout << res << endl;
            continue;
        } else
        if (kol!=0) {
            cout << 3 << endl;
            continue;
        } else
        cout << 0 << endl;
 
    }
 
}

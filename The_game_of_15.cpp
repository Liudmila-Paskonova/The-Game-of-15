#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

void printl(int a[1000], int g) {
    cout << " Current field: " << endl;
    for (int i = 1; i < g; ++i){
        cout << a[i];
        if (i % 4 == 0) {
            cout << endl;
        }
        else {
            if (a[i] < 10) {
                cout << "  ";
            }
            else {
                cout << " ";
            }
        }
    }

    cout << "_";
    if (g % 4 == 0){
        cout << endl;
    }
    else {
        cout << "  ";
    }
    for (int i = g + 1; i <= 16; ++i) {
        cout << a[i];
        if (i % 4 == 0) {
            cout << endl;
        }
        else {
            if(a[i] < 10){
                cout << "  ";
            }
            else {
                cout << " ";
            }
        }
    }
}

int invariant(int a[100]){
    int k=0;
    for (int i = 1; i < 15; ++i) {
        for (int j = i + 1; j < 16; ++j) {
            if (a[i] > a[j]){
                ++k;
            }
        }
    }
    return k;
}

int winner(int a[1000]){
    int h=0;
    if ((a[1] == 1) && (a[2] == 2) && (a[3] == 3) && (a[4] == 4) && (a[5] == 5) && (a[6] == 6) && (a[7] == 7)
        && (a[8] == 8) && (a[9] == 9) && (a[10] == 10) && (a[11] == 11) && (a[12] == 12) && (a[13] == 13)
        &&(a[14] == 14) && (a[15] == 15) && (a[16] == 0)) {
        h=1;
    }
    return h;
}

int main(){
    srand(time(NULL));
    int c[1000];
    for(int i = 1; i <= 15; ++i){
        c[i]=0;
    }
    int a[1000];

    int pr = 0;
    for (int i = 15; i > 0; --i) {
        pr = (rand() % i) + 1;
        for (int j = 1; j <= 15; ++j) {
            if (c[j] == 0) {
                --pr;
                if (pr == 0) {
                    c[j] = 1;
                    a[16 - i] = j;
                    break;
                }
            }
        }
    }
    a[16] = 0;
    int g = 16;


    if ((invariant(a) % 2) == 1) {
        int t=0;
        t = a[1];
        a[1] = a[2];
        a[2] = t;
    }
    cout <<" The game of Fifteen. "<< endl;
    cout <<" Your goal is to arrange the numbers at the given field from 1 to 15 in ascending order like this: "<< endl;
    cout <<" 1  2  3  4  "<< endl;
    cout <<" 5  6  7  8  "<< endl;
    cout <<" 9  10 11 12 "<< endl;
    cout <<" 13 14 15 _  "<< endl;
    cout <<" At the end of the game the computer will print the number of your moves. Good luck! "<< endl;

    printl(a,g);

    int b[1000];

    for (int i = 1; i <= 16; ++i) {
        b[a[i]] = i;
    }

    int turn = 0;
    int x = 0;

    while (winner(a) == 0) {
        cout << " Enter the number your want to move: " << endl;
        cin >> x;

        if (b[x] % 4 == 0) {
            if (a[b[x] - 1] == 0) {
                a[b[x] - 1] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x] - 1;
                printl(a,g);
                ++turn;
                continue;
            }
            if ((b[x]-4 > 0) && (a[b[x] - 4] == 0)) {
                a[b[x] - 4] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x] - 4;
                printl(a,g);
                ++turn;
                continue;
            }
            if ((b[x] + 4< 17) && (a[b[x] + 4] == 0)) {
                a[b[x] + 4] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x] + 4;
                printl(a,g);
                ++turn;
                continue;
            }
        }


        if (b[x] % 4 == 1) {
            if (a[b[x] + 1] == 0) {
                a[b[x] + 1] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x]+1;
                printl(a,g);
                ++turn;
                continue;
            }
            if ((b[x] - 4 > 0) && (a[b[x] - 4] == 0)) {
                a[b[x] - 4] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x] - 4;
                printl(a,g);
                ++turn;
                continue;
            }
            if ((b[x] + 4 < 17) && (a[b[x] + 4] == 0)) {
                a[b[x] + 4] = x;
                a[b[x]] = 0;
                g = b[x];
                b[0] = b[x];
                b[x] = b[x] + 4;
                printl(a,g);
                ++turn;
                continue;
            }
        }

        if ((b[x] - 4 > 0) && (a[b[x] - 4] == 0)) {
            a[b[x] - 4] = x;
            a[b[x]] = 0;
            g = b[x];
            b[0] = b[x];
            b[x] = b[x] - 4;
            printl(a,g);
            ++turn;
            continue;
        }
        if ((b[x] + 4 < 17) && (a[b[x] + 4] == 0)) {
            a[b[x] + 4] = x;
            a[b[x]] = 0;
            g = b[x];
            b[0] = b[x];
            b[x] = b[x] + 4;
            printl(a,g);
            ++turn;
            continue;
        }
        if ((b[x] + 1 < 17) && (a[b[x] + 1] == 0)) {
            a[b[x] + 1] = x;
            a[b[x]] = 0;
            g = b[x];
            b[0] = b[x];
            b[x] = b[x] + 1;
            printl(a,g);
            ++turn;
            continue;
        }
        if ((b[x] - 1 > 0) && (a[b[x] - 1] == 0)) {
            a[b[x] - 1] = x;
            a[b[x]] = 0;
            g = b[x];
            b[0] = b[x];
            b[x] = b[x] - 1;
            printl(a,g);
            ++turn;
            continue;
        }
        printl(a,g);
        ++turn;
    }



    cout << " Congratulations! You have won! The total number of moves:  "<< turn;

    return 0;
}

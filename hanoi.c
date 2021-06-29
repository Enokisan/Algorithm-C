#include  <stdio.h>
#define SIZE 100

void hanoi(int n, int x, int y){
    int  nstk[SIZE], xstk[SIZE], ystk[SIZE];
    int  sp = 0;

    while (1) {
        if (n > 1) {
            nstk[sp] = n;
            xstk[sp] = x;
            ystk[sp] = y;
            sp += 1;

            n -= 1;
            y = 6  - x - y;
            continue;
        }

        printf("%d軸から%d軸へ円盤を移動\n", x, y);

        if (sp > 0) {
            sp -= 1;
            n = nstk[sp];
            x = xstk[sp];
            y = ystk[sp];
            printf("%d軸から%d軸へ円盤を移動\n", x, y);

            if (n > 1){
                n -= 1;
                x = 6 - x - y;
                continue;
            }
        }

        if (sp == 0){
            break;
        }
    }
}

int main(){
    int  n;

    printf("円盤の枚数：");
    scanf("%d", &n);

    hanoi(n, 1, 3);

    return 0;
}
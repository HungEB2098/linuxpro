#include <stdio.h>
#include "inc/add.h"
#include "inc/substract.h"

int main() {
    int a,b;
    printf("Nhap 2 gia tri a va b:\n");
    scanf("%d%d",&a,&b);
    printf("Gia tri cua bieu thuc a + b - (b - a) la: %d\n",substract(add(a,b),substract(b,a)));
    return 0;
}
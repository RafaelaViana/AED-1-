#include <stdio.h>
 
 int maior(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c, maior_ab, maior_abc;
    
    scanf("%d %d %d", &a, &b, &c);
    
    maior_ab = maior(a, b);
 
    maior_abc = maior(maior_ab, c);
    
    printf("%d eh o maior\n", maior_abc);
 
    return 0;
}

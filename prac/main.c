#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int answer = rand() % 100 + 1;
    int guess;
    int tries = 0;

    printf("1부터 100 사이의 숫자를 맞춰보세요!\n");

    while (1) {
        printf("숫자 입력: ");
        scanf("%d", &guess);
        tries++;

        if (guess < answer) {
            printf("더 큰 숫자예요!\n");
        } else if (guess > answer) {
            printf("더 작은 숫자예요!\n");
        } else {
            printf("정답! %d번 만에 맞췄어요!\n", tries);
            break;
        }
    }

    return 0;
}
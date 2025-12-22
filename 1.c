#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number;  
    int guess;         
    int attempts = 0;   
    int max_attempts = 10; 
    
    srand(time(NULL));
    secret_number = rand() % 100 + 1;
    
    
    do {
        attempts++;
        
        scanf("%d", &guess); 
        
        if (guess < secret_number) {
            printf("小了\n");
        } else if (guess > secret_number) {
            printf("大了\n");
        } else {
            printf("\n 恭喜你！猜对了！\n");
            printf("你用了%d次就猜中了数字%d！\n", attempts, secret_number);
            break;
        }
        
        printf("还剩%d次机会。\n", max_attempts - attempts);
        
    } while (attempts < max_attempts);
    
    if (attempts >= max_attempts && guess != secret_number) {
        printf("游戏结束\n");
    }
    
    return 0;
}

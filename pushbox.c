#include <stdio.h>
#include <conio.h> // 只包含conio.h头文件，用于输入函数_kbhit和_getch
#include <windows.h>

int zoom[12][12] = {
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 3, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int playerRow = 10;
int playerCol = 9;

void draw_zoom(void);

int main() {
    printf("\033[H\033[J");

    char ch;

    while (1) {
        
        draw_zoom();
        ch = _getch(); // 获取输入的键
        printf("\033[H\033[J");

        switch (ch) {
            case 'w'|'W':
                if (zoom[playerRow - 1][playerCol] == 0) {
                    zoom[playerRow - 1][playerCol] = 3;
                    zoom[playerRow][playerCol] = 0;
                    playerRow--;
                }
                break;
            case 'a':
            if (zoom[playerRow][playerCol-1] == 0) {
                zoom[playerRow][playerCol-1] = 3;
                zoom[playerRow][playerCol] = 0;
                playerCol--;
            }
            break;
            case 's':
            if (zoom[playerRow + 1][playerCol] == 0) {
                zoom[playerRow + 1][playerCol] = 3;
                zoom[playerRow][playerCol] = 0;
                playerRow++;
            }
            break;
            case 'd':
            if (zoom[playerRow][playerCol + 1] == 0) {
                zoom[playerRow][playerCol + 1] = 3;
                zoom[playerRow][playerCol] = 0;
                playerCol++;
            }
            break;

            // 添加其他移动方向的情况
        }
        if (playerRow == 0 && playerCol == 1){
            printf("\033[H\033[J");
            printf("恭喜你通关成功！！！");
            break;
        }
        
    }

    return 0;
}

void draw_zoom(void) {
    printf("\n\n");
    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 12; c++) {
            if (zoom[r][c] == 1) {
                printf("墙");
            } else if (zoom[r][c] == 0) {
                printf("  ");
            } else if (zoom[r][c] == 3) {
                printf("人");
            }
        }
        printf("\n");
    }
    
    printf("\n\n迷宫游戏V1.0.0，请输入wasd前后左右移动\n");
}

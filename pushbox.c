#include <stdio.h>
#include <conio.h> // 只包含conio.h头文件，用于输入函数_kbhit和_getch
#include <windows.h>

int check = 0;
int map[12][12] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,2,0,0,1,0,0,0,0,1,1,1,
        1,3,1,1,1,1,1,0,0,0,2,1,
        1,0,1,0,1,2,1,0,0,1,1,1,
        1,0,0,0,0,3,0,0,0,3,2,1,
        1,1,1,1,0,0,0,1,0,3,0,1,
        1,0,0,0,0,4,0,1,0,0,0,1,
        1,0,1,0,1,0,1,1,1,1,1,1,
        1,0,1,3,1,0,1,0,1,1,1,1,
        1,1,1,0,1,0,0,0,3,0,1,1,
        1,2,0,0,2,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1
    };
int main()
{
    void draw_map();
    char ch;
    int l = 6,r = 5; 
    draw_map();
    
    while(1){
        ch = _getch();//获取输入的键
        switch(ch){
            case 'W':
            case 'w':
                //运动方向是空
                if(map[l-1][r] == 0||map[l-1][r] == 2){
                    map[l-1][r] += 4,map[l][r] -= 4;
                    l--;
                }else if(map[l-1][r] == 3||map[l-1][r] == 5){
                    if (map[l-2][r] == 0||map[l-2][r] == 2){
                        map[l-2][r] += 3,map[l-1][r] += 1,map[l][r] -=4;
                        l--;
                    }
                }break;
            case 'A':
            case 'a':
                //运动方向是空
                if(map[l][r-1] == 0||map[l][r-1] == 2){
                    map[l][r-1] += 4,map[l][r] -= 4;
                    r--;
                }else if(map[l][r-1] == 3||map[l][r-1] == 5){
                    if (map[l][r-2] == 0||map[l][r-2] == 2){
                        map[l][r-2] += 3,map[l][r-1] += 1,map[l][r] -=4;
                        r--;
                       
                    }
                }break;
            case 'S':
            case 's':

                //运动方向是空
                if(map[l+1][r] == 0||map[l+1][r] == 2){
                    map[l+1][r] += 4,map[l][r] -= 4;
                    l++;
                }else if(map[l+1][r] == 3||map[l+1][r] == 5){
                    if (map[l+2][r] == 0||map[l+2][r] == 2){
                        map[l+2][r] += 3,map[l+1][r] += 1,map[l][r] -=4;
                        l++;
                    }
                }break;
            case 'D':
            case 'd':
                //运动方向是空
                if(map[l][r+1] == 0||map[l][r+1] == 2){
                    map[l][r+1] += 4,map[l][r] -= 4;
                    r++;
                }else if(map[l][r+1] == 3||map[l][r+1] == 5){
                    if (map[l][r+2] == 0||map[l][r+2] == 2){
                        map[l][r+2] += 3,map[l][r+1] += 1,map[l][r] -=4;
                        r++;
                    }
                }break;


        }
    int n,m;
    draw_map();
    for (int n=0;n<12;n++){
        for (m = 0;m<12;m++){
            if(map[n][m] == 3){
                check++;
                
            }
        }
    }
    printf("%d",check);
    if (check == 0){
        printf("\e[1;1H\e[2J");
        printf("恭喜你通关！游戏结束");
        break;
    }
    else{
        check = 0;
    }
    }
}
//绘制地图
void draw_map()
{
    printf("\e[1;1H\e[2J");
    int ml,mr;
    for(ml=0; ml<12; ml++)//基本地图
        {
                for(mr=0; mr<12; mr++)
                {
                    if(map[ml][mr]==0){
                        printf("  ");
                    }
                    else if(map[ml][mr]==1){
                        printf("墙");
                    }

                    else if(map[ml][mr]==2){
                        printf("目");
                    }
                    else if(map[ml][mr]==3){
                        printf("箱");
                    }
                    else if(map[ml][mr]==4 || map[ml][mr]==6){
                        printf("人");
                    }
                    else if(map[ml][mr]==5){
                        printf("好");
                    }
                    

                }
                printf("\n");
        }
    
    printf("\n推箱子游戏V1.0 , by2301B任义\n请使用WASD控制方向");
}

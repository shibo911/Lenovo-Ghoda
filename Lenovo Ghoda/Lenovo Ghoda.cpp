#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int randomGen(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void horseStats() {
    FILE* fp;
    fopen_s(&fp, "game.txt", "r");
    int a=0,b=0,c=0,d=0,e=0,brr[5];
    for (int i = 0; i < 5; ++i)
    {
        fscanf_s(fp, "%d", &brr[i]);
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (brr[i] > brr[j])
            {
                if (i == 0) ++a;
                if (i == 1) ++b;
                if (i == 2) ++c;
                if (i == 3) ++d;
                if (i == 4) ++e;
            }
        }
    }
    fclose(fp);
    if (a >= b && a >= c && a >= d && a >= e)
    {
        printf("Sir Gallop-a-lot is the most successful horse yet.\n");
    }
    else if (b >= a && b >= c && b >= d && b >= e)
    {
        printf("Chucklehooves is the most successful horse yet.\n");
    }
    else if (c >= b && c >= a && c >= d && c >= e)
    {
        printf("Speedy Carburetor is the most successful horse yet.\n");
    }
    else if (d >= b && d >= c && d >= a && d >= e)
    {
        printf("Frosted Flapjack is the most successful horse yet.\n");
    }
    else if (e >= b && e >= c && e >= d && e >= a)
    {
        printf("Disco Inferno is the most successful horse yet.\n");
    }
    if (a <= b && a <= c && a <= d && a <= e)
    {
        printf("Sir Gallop-a-lot is the least successful horse yet.\n");
    }
    else if (b <= a && b <= c && b <= d && b <= e)
    {
        printf("Chucklehooves is the least successful horse yet.\n");
    }
    else if (c <= b && c <= a && c <= d && c <= e)
    {
        printf("Speedy Carburetor is the least successful horse yet.\n");
    }
    else if (d <= b && d <= c && d <= a && d <= e)
    {
        printf("Frosted Flapjack is the least successful horse yet.\n");
    }
    else if (e <= b && e <= c && e <= d && e <= a)
    {
        printf("Disco Inferno is the least successful horse yet.\n");
    }
    printf("\n");
}


void displayMessage() {
    printf("Welcome to Lenovo Ghoda!\n");
    printf("Get ready for an exciting horse betting game.\n\n");
    printf("Rules of the Game:\n");
    printf("1. Choose one of our five magnificent horses to bet on.\n");
    printf("2. Each player starts with 100 credits, and the bet is 50 credits.\n");
    printf("3. You earn credits based on your horse's position:\n");
    printf("   - 1st place: 80 credits\n");
    printf("   - 2nd place: 60 credits\n");
    printf("   - 3rd place: 40 credits\n");
    printf("   - 4th place: 20 credits\n");
    printf("   - 5th place: 0 credits\n");
    printf("4. The game continues until a player's credits drop below 50, at which point they lose.\n\n");
    printf("That's it for the rules! Enjoy the game, and may the best horse win!\n\n");
}

void updateHorse(int arr[5])
{
    FILE* fp;
    fopen_s(&fp, "game.txt", "r");
    int a = 0, b = 0, c = 0, d = 0, e = 0, brr[5];
    for (int i = 0; i < 5; ++i)
    {
        brr[i] = arr[i];
    }
    fscanf_s(fp, "%d", &a);
    fscanf_s(fp, "%d", &b);
    fscanf_s(fp, "%d", &c);
    fscanf_s(fp, "%d", &d);
    fscanf_s(fp, "%d", &e);
    brr[0] += a;
    brr[1] += b;
    brr[2] += c;
    brr[3] += d;
    brr[4] += e;
    fclose(fp);
    fopen_s(&fp, "game.txt", "w");
    for (int i = 0; i < 5; ++i)
    {
        fprintf(fp, "%d ", brr[i]);
    }
    fclose(fp);
    

}

void horseInfo() {
    printf("Welcome to the stable! Players 1 and 2, choose your majestic steeds:\n\n");
    printf("1. Sir Gallop-a-Lot: The dashing dancer of the stable.\n");
    printf("2. Chucklehooves: Barn's jester, always horsing around.\n");
    printf("3. Speedy Carburetor: Once outran a cheetah, still boasting.\n");
    printf("4. Frosted Flapjack: Midnight pancake marauder.\n");
    printf("5. Disco Inferno: Stylish mane, hosts pasture dance parties.\n\n");
}

void raceDisplay(int arr[])
{
    for (int i = 0; i < 5; ++i)
    {
        if (i == 0)
        {
            printf("Sir Gallop-a-Lot:  ");
        }
        if (i == 1)
        {
            printf("Chucklehooves:     ");
        }
        if (i == 2)
        {
            printf("Speedy Carburetor: ");
        }
        if (i == 3)
        {
            printf("Frosted Flapjack:  ");
        }
        if (i == 4)
        {
            printf("Disco Inferno:     ");
        }
        int temp = arr[i];
        while (temp > 10)
        {
            printf("-");
            temp -= 10;
        }
        printf("H\n");
    }
    printf("\n");
}

void race(int arr[])
{
    while (arr[0] < 100 && arr[1] < 100 && arr[2] < 100 && arr[3] < 100 && arr[4] < 100)
    {
        for (int i = 0; i < 5; ++i)
        {
            arr[i] += randomGen(1, 10);
        }
        printf("Live Race: \n\n");
        srand((unsigned int)time(NULL));
        Sleep(500);
        raceDisplay(arr);
    }
    
}




void credInfo(int c1, int c2)
{
    printf("At this instance, Player 1 has %d credits and Player 2 has %d credits\n\n", c1, c2);
}

int main()
{
    
    
    displayMessage();
    horseStats();
    while (1)
    {
        int c1 = 100, c2 = 100;
        while (c1 >= 50 && c2 >= 50)
        {
            horseInfo();
            int p1, p2;
            scanf_s("%d", &p1);
            scanf_s("%d", &p2);

            c1 -= 50; c2 -= 50;
            int arr[5] = { 0,0,0,0,0 };
            race(arr);
            updateHorse(arr);
         
            int h1 = arr[p1 - 1];
            int h2 = arr[p2 - 1];
            int pos1 = 5, pos2 = 5;
            for (int i = 0; i < 5; ++i)
            {
                if (h1 > arr[i]) --pos1;
                if (h2 > arr[i]) --pos2;
            }
            int credits[] = { 80,60,40,20,0 };
            c1 = c1 + (credits[pos1 - 1]);
            c2 = c2 + (credits[pos2 - 1]);
            printf("Horse of Player 1 got rank %d.\n", pos1);
            printf("Horse of Player 2 got rank %d .\n\n", pos2);
            credInfo(c1, c2);
        }
        if (c1 < c2)
        {
            printf("Player 2 wins!\n\n");
        }
        else if (c2 < c1)
            printf("Player 1 wins!\n\n");
        else
        {
            printf("You both lost... \n\n");
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Press y to play again or press any key to quit:\n");
        char play;
        scanf_s("%c",&play, 1);
        if ( play == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
        
    }
    
    return 0;
}





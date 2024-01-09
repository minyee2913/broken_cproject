+ACM-define +AF8-CRT+AF8-SECURE+AF8-NO+AF8-WARNINGS
+ACM-include+ADw-stdio.h+AD4-
+ACM-include+ADw-Windows.h+AD4-
+ACM-include+ADw-conio.h+AD4-

+ACM-define +AF8AXw-BOTTOM+AF8-Y 12

+ACM-define BALL+AF8-BOTTOM+AF8-Y 20
+ACM-define BALL+AF8-BOTTOM+AF8-X 60

+ACM-define DD+AF8-Y 5
+ACM-define DD+AF8-X 25

static int g+AF8-nScreenIndex +AD0- 0+ADs-
static HANDLE g+AF8-hScreen+AFs-2+AF0AOw-
+ACM - include + ADw - stdio.h + AD4 -
void SetConsoleView()
+AHs-
    system(+ACI-mode con:cols+AD0-100 lines+AD0-25+ACI-)+ADs-
    system(+ACI-title +1sQxN7Nc1Vw- +zZWtbAAi-)+ADs-
+AH0-

void ScreenInit() +AHs-
    CONSOLE+AF8-CURSOR+AF8-INFO cci+ADs-

    g+AF8-hScreen+AFs-0+AF0- +AD0- CreateConsoleScreenBuffer(GENERIC+AF8-READ +AHw- GENERIC+AF8-WRITE, 0, NULL, CONSOLE+AF8-TEXTMODE+AF8-BUFFER, NULL)+ADs-
    g+AF8-hScreen+AFs-1+AF0- +AD0- CreateConsoleScreenBuffer(GENERIC+AF8-READ +AHw- GENERIC+AF8-WRITE, 0, NULL, CONSOLE+AF8-TEXTMODE+AF8-BUFFER, NULL)+ADs-

    cci.dwSize +AD0- 1+ADs-
    cci.bVisible +AD0- FALSE+ADs-
    SetConsoleCursorInfo(g+AF8-hScreen+AFs-0+AF0-, +ACY-cci)+ADs-
    SetConsoleCursorInfo(g+AF8-hScreen+AFs-1+AF0-, +ACY-cci)+ADs-
+AH0-

void ScreenFlipping()
+AHs-
    SetConsoleActiveScreenBuffer(g+AF8-hScreen+AFs-g+AF8-nScreenIndex+AF0-)+ADs-
    g+AF8-nScreenIndex +AD0- +ACE-g+AF8-nScreenIndex+ADs-
+AH0-

void ScreenClear()
+AHs-
    COORD Coor +AD0- +AHs- 0, 0 +AH0AOw-
    DWORD dw+ADs-
    FillConsoleOutputCharacter(g+AF8-hScreen+AFs-g+AF8-nScreenIndex+AF0-, ' ', 80 +ACo- 25, Coor, +ACY-dw)+ADs-
+AH0-

void ScreenRelease()
+AHs-
    CloseHandle(g+AF8-hScreen+AFs-0+AF0-)+ADs-
    CloseHandle(g+AF8-hScreen+AFs-1+AF0-)+ADs-
+AH0-

void ScreenPrint(int x, int y, char+ACo- string)
+AHs-
    DWORD dw+ADs-
    COORD CursorPosition +AD0- +AHs- x, y +AH0AOw-
    SetConsoleCursorPosition(g+AF8-hScreen+AFs-g+AF8-nScreenIndex+AF0-, CursorPosition)+ADs-
    WriteFile(g+AF8-hScreen+AFs-g+AF8-nScreenIndex+AF0-, string, strlen(string), +ACY-dw, NULL)+ADs-
+AH0-

void GotoXY(int x, int y)
+AHs-
    COORD pos+ADs-
    pos.X +AD0- 2 +ACo- x+ADs-
    pos.Y +AD0- y +- 2+ADs-
    SetConsoleCursorPosition(GetStdHandle(STD+AF8-OUTPUT+AF8-HANDLE), pos)+ADs-
+AH0-

int GetKeyDown()
+AHs-
    if (+AF8-kbhit() +ACEAPQ- 0)
    +AHs-
        return +AF8-getch()+ADs-
    +AH0-
    return 0+ADs-
+AH0-

//+st2skA-
void Draw+AF8-(int +AF8-Y, int kick)
+AHs-
    /+ACo-/GotoXY(0, +AF8-Y)+ADs-
    printf(+ACI-      +JaEloSWh- +AFw-n+ACI-)+ADs-
    printf(+ACI-      +JaEloSWh- +AFw-n+ACI-)+ADs-
    printf(+ACI-    +JaAloCWgJaAloCWgJaAAXA-n+ACI-)+ADs-
    printf(+ACI-    +JaEloSWgJaAloCWhJaEAXA-n+ACI-)+ADs-
    printf(+ACI-    +JaEloSWgJaAloCWhJaEAXA-n+ACI-)+ADs-
    if (kick +AD0APQ- 0) +AHs-
        printf(+ACI-      +JaA- +JaA- +AFw-n+ACI-)+ADs-
        printf(+ACI-      +JaE- +JaE- +AFw-n+ACI-)+ADs-
    +AH0-
    else +AHs-
        printf(+ACI-      +JaA-  +JaAloQBc-n+ACI-)+ADs-
        printf(+ACI-      +JaE-    +AFw-n+ACI-)+ADs-
    +AH0AKg-/
    ScreenPrint(0, +AF8-Y, +ACI-      +JaEloSWh- +AFw-n+ACI-)+ADs-
    ScreenPrint(0, +AF8-Y +- 1, +ACI-      +JaEloSWh- +AFw-n+ACI-)+ADs-
    ScreenPrint(0, +AF8-Y +- 2, +ACI-    +JaAloCWgJaAloCWgJaAAXA-n+ACI-)+ADs-
    ScreenPrint(0, +AF8-Y +- 3, +ACI-    +JaEloSWgJaAloCWhJaEAXA-n+ACI-)+ADs-
    ScreenPrint(0, +AF8-Y +- 4, +ACI-    +JaEloSWgJaAloCWhJaEAXA-n+ACI-)+ADs-
    if (kick +AD0APQ- 0) +AHs-
        ScreenPrint(0, +AF8-Y +- 5, +ACI-      +JaA- +JaA- +AFw-n+ACI-)+ADs-
        ScreenPrint(0, +AF8-Y +- 6, +ACI-      +JaE- +JaE- +AFw-n+ACI-)+ADs-
    +AH0-
    else +AHs-
        ScreenPrint(0, +AF8-Y +- 5, +ACI-      +JaA-  +JaAloQBc-n+ACI-)+ADs-
        ScreenPrint(0, +AF8-Y +- 6, +ACI-      +JaE-    +AFw-n+ACI-)+ADs-
    +AH0-
+AH0-

//+rPWs9Q-
void DrawBall(int ballX)
+AHs-
    /+ACo-GotoXY(ballX, BALL+AF8-BOTTOM+AF8-Y)+ADs-
    printf(+ACIloCWhJaEloAAi-)+ADs-
    GotoXY(ballX, BALL+AF8-BOTTOM+AF8-Y +- 1)+ADs-
    printf(+ACIloSWhJaEloQAi-)+ADs-
    GotoXY(ballX, BALL+AF8-BOTTOM+AF8-Y +- 2)+ADs-
    printf(+ACIloCWhJaEloAAi-)+ADsAKg-/

    ScreenPrint(ballX, BALL+AF8-BOTTOM+AF8-Y, +ACIloCWhJaEloAAi-)+ADs-
    ScreenPrint(ballX, BALL+AF8-BOTTOM+AF8-Y +- 1, +ACIloSWhJaEloQAi-)+ADs-
    ScreenPrint(ballX, BALL+AF8-BOTTOM+AF8-Y +- 2, +ACIloCWhJaEloAAi-)+ADs-
    ScreenPrint(ballX +- 4, BALL+AF8-BOTTOM+AF8-Y, +ACI-                 +ACI-)+ADs-
    ScreenPrint(ballX +- 4, BALL+AF8-BOTTOM+AF8-Y +- 1, +ACI-                 +ACI-)+ADs-
    ScreenPrint(ballX +- 4, BALL+AF8-BOTTOM+AF8-Y +- 2, +ACI-                 +ACI-)+ADs-
+AH0-

void ClearBall() +AHs-
    ScreenPrint(0, BALL+AF8-BOTTOM+AF8-Y, +ACI-                                                                    +ACI-)+ADs-
    ScreenPrint(0, BALL+AF8-BOTTOM+AF8-Y +- 1, +ACI-                                                                    +ACI-)+ADs-
    ScreenPrint(0, BALL+AF8-BOTTOM+AF8-Y +- 2, +ACI-                                                                    +ACI-)+ADs-
+AH0-

//+MTcxNw-
void DrawDD(int DX)
+AHs-
    /+ACo-
    GotoXY(DX, DD+AF8-Y)+ADs-
    printf(+ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 1)+ADs-
    printf(+ACIAfA-               +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 2)+ADs-
    printf(+ACIAfA-               +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 3)+ADs-
    printf(+ACIAfA-     +AF8AXwBfAF8AXwBfAF8AXwBfAF8AfAAi-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 4)+ADs-
    printf(+ACIAfA-    +AHw-           +ACI-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 5)+ADs-
    printf(+ACIAfA-    +AHwAXwBfAF8AXwBfAF8AXwBfAF8AXwAi-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 6)+ADs-
    printf(+ACIAfA-               +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 7)+ADs-
    printf(+ACIAfABfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwB8ACI-)+ADs- +ACo-/

    ScreenPrint(DX, DD+AF8-Y, +ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 1, +ACIAfA-               +AHwAIg-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 2, +ACIAfA-               +AHwAIg-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 3, +ACIAfA-     +AF8AXwBfAF8AXwBfAF8AXwBfAF8AfAAi-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 4, +ACIAfA-    +AHw-           +ACI-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 5, +ACIAfA-    +AHwAXwBfAF8AXwBfAF8AXwBfAF8AXwAi-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 6, +ACIAfA-               +AHwAIg-)+ADs-
    ScreenPrint(DX, DD+AF8-Y +- 7, +ACIAfABfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwB8ACI-)+ADs-
+AH0-

//+MUsxSw-
void DrawKK(int DX, int DY)
+AHs-
    /+ACo-
    GotoXY(DX, DD+AF8-Y)+ADs-
    printf(+ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 1)+ADs-
    printf(+ACIAfA-               +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 2)+ADs-
    printf(+ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 3)+ADs-
    printf(+ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAHw-     +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 4)+ADs-
    printf(+ACIAfA-               +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 5)+ADs-
    printf(+ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 6)+ADs-
    printf(+ACI-          +AHw-     +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 7)+ADs-
    printf(+ACI-          +AHw-     +AHwAIg-)+ADs-
    GotoXY(DX, DD+AF8-Y +- 8)+ADs-
    printf(+ACI-          +AHwAXwBfAF8AXwBfAHwAIg-)+ADs- +ACo-/

    ScreenPrint(DX, DY, +ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI-)+ADs-
    ScreenPrint(DX, DY +- 1, +ACIAfA-               +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 2, +ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 3, +ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAHw-     +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 4, +ACIAfA-               +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 5, +ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 6, +ACI-          +AHw-     +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 7, +ACI-          +AHw-     +AHwAIg-)+ADs-
    ScreenPrint(DX, DY +- 8, +ACI-          +AHwAXwBfAF8AXwBfAHwAIg-)+ADs-
+AH0-

int main(void)
+AHs-
    SetConsoleView()+ADs-

    int started +AD0- 0+ADs-

    int +AF8-Y +AD0- +AF8AXw-BOTTOM+AF8-Y+ADs-
    int ballX +AD0- BALL+AF8-BOTTOM+AF8-X+ADs-
    int delay +AD0- 0+ADs-
    int succeed +AD0- 0+ADs-
    int kicked +AD0- 0+ADs-
    int point +AD0- 0+ADs-

    int dec +AD0- 0+ADs-

    char score+AFs-50+AF0AOw-

    ScreenInit()+ADs-


    printf(+ACIAPQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQBc-n+ACI-)+ADs-
    printf(+ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAFw-n+ACI-)+ADs-
    printf(+ACIAfA-               +AHw-            +AF8AXwBfAF8AXw-   +AF8AXwBf-  +AF8AXwBf-  +AF8AXwBf- +AF8AXwBfAF8AXw-   +AF8AXwBfAF8AXw-  +AF8AXwBfAF8AXw-   +AF8AXwBf-  +AF8AXwBfAF8AXwBf-  +AF8AXwBfAF8AXw- +AFw-n+ACI-)+ADs-
    printf(+ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHw-           +AHw-  +AF8AXw- +AFwAXA- / +AF8- +AFwAXA- +AHw-  +AFwAXA-/  +AHwAfA-  +AF8AXwBfAHw- /  +AF8AXwBfAHwAfABf-   +AF8AfA- / +AF8- +AFwAXA- +AHw- +AF8AXwBf- +AFwAXAB8AF8-   +AF8AfABc-n+ACI-)+ADs-
    printf(+ACI- +AF8AXwBfAF8AXwBfAF8AXwBfAHw-     +AHw-           +AHw- +AHw-  +AFwAXA-// /+AF8AXABc- +AFwAXAB8- .  . +AHwAfA- +AHwAXwBf-   +AFwAXA- +AGA---.   +AHw- +AHw-  / /+AF8AXABc- +AFwAXAB8- +AHwAXw-/ /  +AHw- +AHw-  +AFw-n+ACI-)+ADs-
    printf(+ACIAfA-               +AHw-           +AHw- +AHw- +AF8AXw- +AHw-  +AF8-  +AHwAfA- +AHwAXABc-/+AHw- +AHwAfA-  +AF8AXwB8-   +AGA---. +AFwAXA-  +AHw- +AHw-  +AHw-  +AF8-  +AHwAfA-    /   +AHw- +AHw-  +AFw-n+ACI-)+ADs-
    printf(+ACIAfABfAF8AXwBfAF8AXwBfAF8AXw-      +AHw-           +AHw- +AHwAXwBcAFw- +AFwAXAB8- +AHw- +AHw- +AHwAfA- +AHw-  +AHw- +AHwAfA- +AHwAXwBfAF8-  /+AFwAXABfAF8-/ /  +AHw- +AHw-  +AHw- +AHw- +AHw- +AHwAfA- +AHwAXABc- +AFwAXA-   +AHw- +AHw-  +AFw-n+ACI-)+ADs-
    printf(+ACI-          +AHw-     +AHw-            +AFwAXABfAF8AXwBf-/+AFwAXABfAHw- +AHwAXw-/+AFwAXABfAHw-  +AHwAXw-/+AFwAXABfAF8AXwBf-/  +AFwAXABfAF8AXwBf-/   +AFwAXABf-/  +AFwAXABfAHw- +AHwAXw-/+AFwAXABfAHw- +AFwAXABfAHw-  +AFwAXABf-/  +AFw-n+ACI-)+ADs-
    printf(+ACI-          +AHw-     +AHwAXA-n+ACI-)+ADs-
    printf(+ACI-          +AHwAXwBfAF8AXwBfAHw- (Z) +uXw- +sgy37MEcAFw-n+ACI-)+ADs-
    printf(+ACIAPQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQA9AD0APQAi-)+ADs-

    int processing +AD0- 1+ADs-
    while (processing)
    +AHs-

        if (started) +AHs-
            sprintf(score, +ACI-   +yBDCGA-: +ACU-d              (Z)+uXw- +sgy37MEc- +rPXMKK4w-,   (Q)+uXw- +r7k- +sgy37A- +rIzHhA- +yIW4zAAi-, point)+ADs-

            ScreenClear()+ADs-
            ScreenPrint(0, 0, score)+ADs-
            ScreenPrint(0, 1, +ACI-S  C  O  R  E        +wTGs9cLc- +-20+yBA-, +wuTTKMLc- -69+yBAAIg-)+ADs-

            if (GetKeyDown() +AD0APQ- 'z')
            +AHs-
                kicked +AD0- 1+ADs-
                if (ballX +ADw- 14 +ACYAJg- ballX +AD4- 3) +AHs-
                    succeed +AD0- 1+ADs-
                    point +-+AD0- 20+ADs-
                +AH0-
                else +AHs-
                    succeed +AD0- 0+ADs-
                    point -+AD0- 69+ADs-
                +AH0-
                delay +AD0- 10+ADs-
                ballX +AD0- BALL+AF8-BOTTOM+AF8-X+ADs-

            +AH0-

            if (GetKeyDown() +AD0APQ- 'q') +AHs-
                processing +AD0- 0+ADs-

                break+ADs-
            +AH0-

            dec +AD0- (ballX +ACU- 3 +AD0APQ- 0) ? (2 +- point / 50) : 2+ADs-
            if (dec +ADw- 2) dec +AD0- 2+ADs-

            if (delay +ADwAPQ- 0) ballX -+AD0- dec+ADs-

            if (ballX +ADwAPQ- 0 +ACYAJg- delay +ADwAPQ- 0)
            +AHs-
                ballX +AD0- BALL+AF8-BOTTOM+AF8-X+ADs-
                succeed +AD0- 0+ADs-
                delay +AD0- 10+ADs-
                kicked +AD0- 0+ADs-
                point -+AD0- 99+ADs-


            +AH0-

            if (delay +AD4- 0) +AHs-
                if (succeed +AD0APQ- 1) +AHs-
                    DrawDD(DD+AF8-X)+ADs-
                    DrawDD(DD+AF8-X +- 20)+ADs-
                +AH0-
                else +AHs-
                    DrawKK(DD+AF8-X, DD+AF8-Y)+ADs-
                    DrawKK(DD+AF8-X +- 20, DD+AF8-Y - 5)+ADs-
                    DrawKK(DD+AF8-X +- 25, DD+AF8-Y +- 5)+ADs-
                +AH0-

                delay--+ADs-
            +AH0-

            if (delay +AD4- 0) Draw+AF8-(+AF8-Y, kicked)+ADs-
            else Draw+AF8-(+AF8-Y, 0)+ADs-

            ClearBall()+ADs-
            DrawBall(ballX)+ADs-

            Sleep(25)+ADs-
            ScreenFlipping()+ADs-
        +AH0-
        else +AHs- 
            if (GetKeyDown() +AD0APQ- 'z') +AHs-
                started +AD0- 1+ADs-
            +AH0-
        +AH0-
    +AH0-
+AH0-
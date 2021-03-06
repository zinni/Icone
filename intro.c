#include "intro.h"

void intro(void){
	HANDLE  hConsole;
    	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	srand(time(NULL));

	for(int i = 0; i < 10; i++){

    	int r = (rand() % 14) + 1;
		SetConsoleTextAttribute(hConsole, r);

		system("cls");
		printf("\n\n");
		printf("\t$$$$  $$$$  $$$$$  $$$$   $   $  $$$$$  $   $   $$$$    $$$\n");
		printf("\t$     $       $    $   $  $   $    $    $   $   $   $  $   $\n");
		printf("\t$$$   $$$$    $    $$$$   $   $    $    $   $   $$$$   $$$$$\n");
		printf("\t$        $    $    $  $   $   $    $    $   $   $  $   $   $\n");
		printf("\t$$$$  $$$$    $    $   $   $$$     $     $$$    $   $  $   $\n\n");
		printf("\t    $$$$    $$$$       $$$$    $$$   $$$$    $$$   $$$$\n");
		printf("\t    $   $   $          $   $  $   $  $   $  $   $  $\n");
		printf("\t    $   $   $$$        $   $  $$$$$  $   $  $   $  $$$$\n");
		printf("\t    $   $   $          $   $  $   $  $   $  $   $     $\n");
		printf("\t    $$$$    $$$$       $$$$   $   $  $$$$    $$$   $$$$\n\n\n");
		SetConsoleTextAttribute(hConsole, 13);
		printf("\t       TURMA 2021.2 - Prof. Dilza de Mattos Szwarcman\n");

		int x = (rand() % 14) + 1;
		SetConsoleTextAttribute(hConsole, x);

		printf("\n\t          __    ___    ___       ___               ____\n");
		printf("\t|   | |  /  \\  /   \\  |   \\     |        |\\    /| |    |  \\  /\n");
		printf("\t|___| | |     |     | |    |    |__      | \\  / | |____|   \\/\n");
		printf("\t|   | | |   _ |     | |___/     |        |  \\/  | |    |   /\\\n");
		printf("\t|   | |  \\__/  \\___/  |   \\     |___     |      | |    |  /  \\\n");
		printf("\n");
		printf("\n");
		Sleep(200);
		SetConsoleTextAttribute(hConsole, 7);
	}
	printf("\n\tInicializando o programa");
	for(int i = 0; i < 8; i++){
        printf(".");
        Sleep(500);
	}
    system("cls");
}

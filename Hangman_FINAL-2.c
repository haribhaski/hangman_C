#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Word 100
#define Descrp 200
char tempWord[100];
char Hangman_Output[100];
int trials = 6, matchFound = 0, temp_var, position = 0, win_var, lengthOfHangmanWord, i, fillBlanks, AlreadyGuessed;
char AlphabetFromPlayer_2;
void ShowRules(void);
void StartHangman(void);
void HangmanDisplay(int error_count);
// Single-Player System.
char* Description_Generator(int Player_choice, int Generate_Random_Line);
char* Word_Generator(int Player_choice, int Generate_Random_Line);
int Player_choice;
char Generated_Word[100];
char Generated_Description[100];
int main(){    
    int menu_choice;
    printf("    WELCOME TO THE HANGMAN GAME!!   \n");
    printf("  Please press 'ENTER' to continue.    ");
    getchar();
    printf("\t*****MAIN MENU*****\n\tStart Game -----> Press 1\n\tRules for the Game -----> Press 2");
    printf("\nEnter your choice: ");
    scanf("%i", &menu_choice);
    getchar();
    if (menu_choice == 1) {
        printf("PRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
        scanf("%i", &Player_choice);
        getchar();
        StartHangman();            
    } 
    else if (menu_choice == 2){
        ShowRules();
    }
    else{
        printf("ENTER A VALID CHOICE!! ");
        return main();
}}
void StartHangman(void)
{
    srand(time(NULL));
    int Generate_Random_Line = rand() % (100);
    char* input_1_player = Word_Generator(Player_choice, Generate_Random_Line);
    char* desc = Description_Generator(Player_choice, Generate_Random_Line);
    lengthOfHangmanWord = strlen(input_1_player);
    printf("\n\nENTER A CHARACTER TO GUESS THE WORD.\n");
    for (i = 0; i < lengthOfHangmanWord; i++) 
    {
        Hangman_Output[i] = '_';
        Hangman_Output[lengthOfHangmanWord] = '\0';
        
    }
    printf("\n");
    for (i = 0; i < lengthOfHangmanWord; i++) 
    {
        printf(" ");
        printf("%c", Hangman_Output[i]);
    }
    int k = 0;
    char disp_entered_alphabet[100] = "";
    while (trials != 0) 
    {   
        matchFound = 0;
        printf("\n\nNumber of Words: %i", lengthOfHangmanWord);
        printf("\n");
        printf("\nThe Description for the word is %s", desc);
        printf("\n");
        printf("\n\nALREADY ENTERED CHARACTERS: %s ",disp_entered_alphabet);
        printf("\n\n   Enter any alphabet of your choice:  ");
        scanf(" %c", &AlphabetFromPlayer_2);
        int temp_len = strlen(disp_entered_alphabet);
        for (i = 0; i < temp_len; ++i)
        {
            if (disp_entered_alphabet[i] == AlphabetFromPlayer_2)
            {
                printf("\n\nYou have already enterd this character please try another one.");
                break;
            }
        }
        if (AlphabetFromPlayer_2 < 'a' || AlphabetFromPlayer_2 > 'z') 
        {   
            printf("\n\n\t Wrong input TRY AGAIN!! We only accept Alphabets. ");
            matchFound = 2;
        } 
        else 
        {
            if (matchFound != 2) 
            {
                for (temp_var = 0; temp_var < lengthOfHangmanWord; temp_var++) 
                {
                    if (AlphabetFromPlayer_2 == input_1_player[temp_var]) 
                    {
                        matchFound = 1;
                    }
                }
                if (matchFound == 0) 
                {
                    AlreadyGuessed = 0;
                    for (i = 0; i < temp_len; ++i) 
                    {
                        if (disp_entered_alphabet[i] == AlphabetFromPlayer_2) 
                        {
                            AlreadyGuessed = 1;
                            HangmanDisplay(trials);
                            printf("\n\n\tYou have already entered this character.");
                        }
                    }
                    if (!AlreadyGuessed) 
                    {
                        --trials;
                        HangmanDisplay(trials);
                        getchar();
                        printf("\n\nYou have %i tries remaining.", trials);
                    }
                }
                else 
                {
                    for (temp_var = 0; temp_var < lengthOfHangmanWord; temp_var++) 
                    {
                        fillBlanks = 0;
                        if (AlphabetFromPlayer_2 == input_1_player[temp_var]) 
                        {
                            position = temp_var;
                            fillBlanks = 1;
                        }
                        if (fillBlanks == 1) 
                        {
                            for (i = 0; i < lengthOfHangmanWord; i++) 
                            {
                                if (i == position) 
                                {
                                    Hangman_Output[i] = AlphabetFromPlayer_2;
                                }                
                                else if (Hangman_Output[i] >= 'a' && Hangman_Output[i] <= 'z') 
                                {
                                    continue;
                                } 
                                else 
                                {
                                    Hangman_Output[i] = '_';
                                }
                            }
                            tempWord[position] = AlphabetFromPlayer_2;
                            tempWord[lengthOfHangmanWord] = '\0';
                            win_var = strcmp(tempWord, input_1_player);
                            if (win_var == 0) 
                            {
                                printf("\n\n\t\t The Word was %s", input_1_player);
                                printf("\n\n\t\t That's Brilliant!! You must be smart.");
                                printf("\n\n\t\t Congratualation!! For winning the game and saving our guy.\n\n");
                                getchar();
                                int choice;
                                printf("\n\nIf you would like to play again PRESS 1.\nIf you want to check the rules PRESS 2.\nIf you would like EXIT the game PRESS 0.\nEnter your Choice: ");
                                scanf("%i", &choice);
                                if (choice == 1)
                                {
                                    printf("\nPRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
                                    scanf("%i", &Player_choice);
                                    
                                    StartHangman();
                                }
                                else if (choice == 2)
                                {
                                    ShowRules();
                                }
                                else
                                {
                                    printf("\n\nEXITED. THANK YOU FOR PLAYING!! \n\n");
                                    exit(0);
                                }
                            }
}}}}}
        if (win_var != 0)
        {
            printf("\n\n\t");
            for (i = 0; i < lengthOfHangmanWord; i++) 
            {
                printf(" ");
                printf("%c", Hangman_Output[i]);
            }
        }      
        
        if (trials <= 0) 
        {
            printf("\n\n\t Sorry!! You lost the game.");
            printf("\n\n\t You Better Save him Next time.!!!");
            printf("\n\n\t The Word was %s", input_1_player);
            int choice;
            printf("\n\nIf you would like to play again PRESS 1.\nIf you want to check the rules PRESS 2.\nIf you would like EXIT the game PRESS 0.\nEnter your Choice: ");
            scanf("%i", &choice);
            if (choice == 1)
            {
                printf("\nPRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
                scanf("%i", &Player_choice);   
                StartHangman();
            }
            else if (choice == 2)
            {
                ShowRules();
            }
            else
            {
                printf("\n\nEXITED.\nTHANK YOU FOR PLAYING!! \n\n");
                exit(0);
            }
        }
        disp_entered_alphabet[k] = AlphabetFromPlayer_2;
        ++k;
    }  
    getchar();           
}
void ShowRules(void)
{
    printf("RULES FOR MULTI-PLAYER: \n\n");
    printf("1. PLAYER 1 HAS TO GIVE A WORD IN LOWER CASE WITH A DESCRIPTION ABOUT IT.\n2. PLAYER 2 HAS TO GUESS THE WORD FROM THE DESCRIPTION GIVEN AND BLANKED SPACES (TO GUESS THE NUMBER OF WORDS).\n3. PLAYER 2 GETS 6 INCORRECT TRIES AND HAS TO GUESS THE RIGHT WORD BEFORE YOUR TRIES GETS OVER.\n4. EACH TIME YOU GUESS THE WRONG LETTER A BODY PART WILL BE DRAWN TO COMPLETE THE HANGMAN.\n5. EACH TIME YOU GUESS THE RIGHT LETTER THAT LETTER WOULD BE PLAYED AT ITS POSITION AS THE ACTUAL WORD, BY THIS YOU WILL BE ABLE TO GUESS OTHER LETTERS TO COMPLETE THE WORD.\n6. GUESS THE RIGHT WORD BEFORE THE HANGMAN VISUAL IS COMPLETED ORELSE IT WOULD BE A **GAME-OVER**.");
    printf("\n");
    printf("\n\nRULES FOR SINGLE-PLAYER: \n\n");
    printf("A RANDOM WORD AND DESCRIPTION WILL BE GENERATED FROM OUR DATABASE. THE OTHER RULES ARE AS SAME AS MULTI-PLAYER");
    printf("\n\n \t BEWARE!!");
    int choice;
    printf("\n\nIf you want to start the game now please enter 1 or if you want to exit enter 0: ");
    scanf("%i", &choice);
    if (choice == 1){
        printf("PRESS-1 for Multi-Player\nPRESS-2 for Single-Player\n");
        scanf("%i", &Player_choice);       
        StartHangman();
    }
    else if (choice == 0){
        printf("\n\nExited. Thank you!");
        exit(0);
    }
}
char* Word_Generator(int Player_choice, int Generate_Random_Line) 
{
    if (Player_choice == 1)
    {
        char* WORD = (char*)malloc(Word * sizeof(char));
        if (WORD == NULL) 
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter your Word: ");
        scanf("%99s", WORD);
        return WORD;
    }
    else if (Player_choice == 2){
        int Dataset_Length;
        FILE* access_database = fopen("database.csv","r");
        if (access_database == NULL){
            printf("Error Opening File");
            exit(1);}
        char Line_dataset[1000];
        int Cursor_Line = 0;
        while (fgets(Line_dataset, sizeof(Line_dataset), access_database) != NULL){
            if (Cursor_Line == Generate_Random_Line){
                char *token = strtok(Line_dataset, "-");
                strcpy(Generated_Word, token);
                break;}
            ++Cursor_Line;}
        return Generated_Word;}
    else{
        printf("Enter a Valid choice between 1 and 2");
    }}
char* Description_Generator(int Player_choice, int Generate_Random_Line){
    if (Player_choice == 1){
        char* DESCRIPTION = (char*)malloc(Descrp * sizeof(char));
        if (DESCRIPTION == NULL){
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);}
        printf("Enter a description about the word (use '_' for spaces): \n");
        scanf("%199s", DESCRIPTION);
        return DESCRIPTION;}
    else if (Player_choice == 2){
        FILE* access_database = fopen("database.csv","r");
        if (access_database == NULL){
            printf("Error Opening File");
            exit(1);}
        char Line_dataset[200];
        int Cursor_Line = 0;
        while (fgets(Line_dataset, sizeof(Line_dataset), access_database) != NULL){
            if (Cursor_Line == Generate_Random_Line){
                char *token = strtok(Line_dataset, "-");
                token = strtok(NULL, "-");
                strcpy(Generated_Description, token);
                break;}
            ++Cursor_Line;
        }
        return Generated_Description;
        fclose(access_database);
}}
void HangmanDisplay(int error_count){
    switch(error_count){
        case 0:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||        / \\");
            printf("\n\t||       /   \\");
            printf("\n\t||=================");
            break;
        case 1:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||        /");
            printf("\n\t||       /");
            printf("\n\t||=================");
            break;
        case 2:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||        /|\\");
            printf("\n\t||       / | \\");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;
        case 3:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||         |\\");
            printf("\n\t||         | \\");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;
        case 4:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;
        case 5:
            printf("\n\t||==========");
            printf("\n\t||         |");
            printf("\n\t||         |");
            printf("\n\t||        ( )");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||");
            printf("\n\t||=================");
            break;
}}
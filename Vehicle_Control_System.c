#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned char Traffic_Light_Data(unsigned char *Data_Light,unsigned char *Ret_2);
unsigned int Room_Temperature_Data(unsigned int *Room_Temperature,unsigned int *Ret_1);
unsigned int Engine_Temperature_Data(unsigned int *Engine_Temperature,unsigned int *Ret_3);
void Vehicle_Speed();

int main()
{
    unsigned int Ret_1 = 0;
    unsigned char Ret_2 = 0;
    unsigned int Ret_3 = 0;
    unsigned int *Ret_4 = NULL;
    unsigned char *Ret_5 = NULL;
    unsigned int *Ret_6 = NULL;
    unsigned int *Room_Temperature = NULL;
    unsigned char *Data_Light = NULL;
    unsigned int *Engine_Temperature = NULL ;
    unsigned int Choice = 0;
    unsigned char Ch = 0;
    while(1)
    {
    Jumb:
        printf(" ********** This is Vehicle Control System ********** \n");
        printf("1. Turn on the vehicle engine \n2. Turn off the vehicle engine \n3. Quit the system\n");
        printf("Please, type the Choice you want : ");
        fflush(stdin);
        scanf("%i", &Choice);
        switch (Choice)
        {
            case 1:
                printf("\nThe vehicle has been turn on\n\n");
                printf("Sensors set menu\n\n");
                while(1)
                {
                    printf("a. Turn off the engine \nb. Set the traffic light color \nc. Set the room temperature\nd. Engine Temperature Data\ne. If vehicle speed is 30 km/hr\nf. Display the current vehicle state \n");
                    printf("Please, type the Choice you want : ");
                    fflush(stdin);
                    scanf("%c", &Ch);
                    switch (Ch)
                    {
                    case 'a':
                        printf("\nThe vehicle has been turn off\n\n");
                        goto Jumb;
                        break;
                    case 'b':
                        printf("\nData Light Value (G , O , R): ");
                        fflush(stdin);
                        scanf("%c",&Data_Light);
                        Ret_2 = Traffic_Light_Data(&Data_Light,&Ret_5);
                        break;
                    case 'c':
                        printf("Room Temperature Data : ");
                        fflush(stdin);
                        scanf("%i",&Room_Temperature);
                        Ret_1 = Room_Temperature_Data(&Room_Temperature,&Ret_4);
                        break;
                    case 'd':
                        printf("Engine Temperature Data : ");
                        fflush(stdin);
                        scanf("%i",&Engine_Temperature);
                        Ret_3 = Engine_Temperature_Data(&Engine_Temperature,&Ret_6);
                        break;
                    case 'e':
                        if((Ret_2 == 'O' || Ret_2 == 'o') && (Ret_1 < 31 && Ret_1 > 9))
                        {
                            printf("\nTurn ON AC\n\n");
                            printf("Set room temperature to : %i \n\n", (Ret_1 * (5/4) + 1));
                        }
                        else if((Ret_2 == 'O' || Ret_2 == 'o') && (Ret_3 < 99 && Ret_3 <151))
                        {
                            printf("\nTurn ON 'Engine Temperature Controller'\n\n");
                            printf("\nSet engine temperature to : %i \n\n", (Ret_3 * (5/4) + 1));
                        }
                        break;
                    case 'f':
                        if(Choice == 1)
                        {
                            printf("\nThe Engine state: ON\n\n");
                        }
                        else
                        {
                            printf("\nThe Engine state: OFF\n\n");
                        }
                        Ret_1 = Room_Temperature_Data(&Room_Temperature,&Ret_4);
                        if((Ret_2 == 'O' || Ret_2 == 'o') && (Ret_1 < 31 && Ret_1 > 9))
                        {
                            printf("\nRoom temperature to : %i \n\n", Ret_1);
                        }
                        else if((Ret_2 == 'O' || Ret_2 == 'o') && (Ret_3 < 99 && Ret_3 <151))
                        {

                            printf("\nEngine temperature to : %i \n\n", Ret_3);
                        }
                        Ret_3 = Engine_Temperature_Data(&Engine_Temperature,&Ret_6);
                        break;

                    default:
                        printf("\nYou put the wrong Choice. Please try again.\n");
                        break;
                    }
                }
                break;
        case 2:
            printf("\nThe vehicle has been turn off\n\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nYou put the wrong Choice. Please try again.\n");
        }
    }
    return 0;
}
/* ----------------------------------------------------------------- */

unsigned char Traffic_Light_Data(unsigned char *Data_Light,unsigned char *Ret_2)
{
     *Ret_2 = *Data_Light ;
    if(*Data_Light == 'G' || *Data_Light == 'O' || *Data_Light == 'R' || *Data_Light == 'g' || *Data_Light == 'o' || *Data_Light == 'r')
    {
        switch(*Data_Light)
        {
            case 'G':
                printf("\nVehicle speed is 100 km/hr\n\n");
                break;
            case 'O':
                printf("\nVehicle speed is 30 km/hr\n\n");
                break;
            case 'R':
                printf("\nVehicle speed is 0 km/hr\n\n");
                break;
            case 'g':
                printf("\nVehicle speed is 100 km/hr\n\n");
                break;
            case 'o':
                printf("\nVehicle speed is 30 km/hr\n\n");
                break;
            case 'r':
                printf("\nVehicle speed is 0 km/hr\n\n");
                break;
            default :
                break;
        }
    }
    else{ printf("Invalid input !!, Please enter right choice...\n\n"); }
    return *Ret_2;
}

unsigned int Room_Temperature_Data(unsigned int *Room_Temperature,unsigned int *Ret_1)
{
    *Ret_1 = *Room_Temperature;
    if(*Room_Temperature < 10)
    {
        printf("\nRoom Temperature Data = %i < 10 \n", *Room_Temperature);
        printf("\nTurn AC ON and set temperature to 27 \n\n");
    }
    else if(*Room_Temperature > 30)
    {
        printf("\nRoom Temperature Data = %i > 30 \n", *Room_Temperature);
        printf("\nTurn AC ON and set temperature to 20 \n\n");
    }
    else
    {
        printf("\nRoom Temperature Data = %i Between 10 and 30 \n", *Room_Temperature);
        printf("\nTurn AC OFF \n\n");
    }
    return *Ret_1;
}

unsigned int Engine_Temperature_Data(unsigned int *Engine_Temperature,unsigned int *Ret_3)
{
    *Ret_3 = *Engine_Temperature;

    if(*Engine_Temperature < 100)
    {
        printf("\nEngine Temperature = %i ==> Engine Temperature < 100\n", *Engine_Temperature);
        printf("Turn 'Engine Temperature Controller' ON \nAnd set temperature to 125\n\n");
    }
    else if(*Engine_Temperature > 150)
    {
        printf("\nEngine Temperature = %i ==> Engine Temperature > 150\n", *Engine_Temperature);
        printf("\nTurn 'Engine Temperature Controller' ON \nAnd set temperature to 125\n\n");
    }
    else
    {
        printf("Engine Temperature is Good\n");
        printf("\nTurn 'Engine Temperature Controller' OFF\n\n");
    }
    return *Ret_3 ;
}

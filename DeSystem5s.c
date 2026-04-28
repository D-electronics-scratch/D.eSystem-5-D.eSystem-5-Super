#define _WIN32_WINNT 0x0600   

#ifdef _WIN32
#include <windows.h>
#include <sysinfoapi.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//sysinfo

// CPU cores (Linux + Windows)
int get_cpu_count() {
#ifdef _WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
#else
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}

// CPU model (Linux only)
void show_cpu_model() {
#ifdef __linux__
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    char line[256];

    if (!cpuinfo) {
        printf("| CPU model: Unknown\n");
        return;
    }

    while (fgets(line, sizeof(line), cpuinfo)) {
        if (strncmp(line, "model name", 10) == 0) {
            char *model = strchr(line, ':');
            if (model) {
                model++;
                printf("| CPU model:%s", model);
            }
            break;
        }
    }
    fclose(cpuinfo);
#else
    printf("| CPU model: Unsupported on Windows\n");
#endif
}

// RAM info (Windows + Linux)
void show_ram_info() {
#ifdef _WIN32
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    printf("| RAM total: %llu MB\n", statex.ullTotalPhys / (1024 * 1024));
    printf("| RAM free:  %llu MB\n", statex.ullAvailPhys / (1024 * 1024));

#else
    FILE *meminfo = fopen("/proc/meminfo", "r");
    char line[256];

    long total = 0, free = 0;

    while (fgets(line, sizeof(line), meminfo)) {
        if (sscanf(line, "MemTotal: %ld kB", &total) == 1) {}
        if (sscanf(line, "MemAvailable: %ld kB", &free) == 1) {}
    }
    fclose(meminfo);

    printf("| RAM total: %ld MB\n", total / 1024);
    printf("| RAM free:  %ld MB\n", free / 1024);
#endif
}

// GPU info (Linux only)
void show_gpu_info() {
#ifdef __linux__
    FILE *gpu = popen("lspci | grep -i vga", "r");
    char line[256];

    if (gpu && fgets(line, sizeof(line), gpu)) {
        printf("| GPU: %s", line);
    } else {
        printf("| GPU: Unknown\n");
    }
    pclose(gpu);
#else
    printf("| GPU info: Unsupported on Windows\n");
#endif
}

// OS info
void show_os_info() {
#ifdef _WIN32
    printf("| OS: Windows\n");
#else
    printf("| OS: Linux\n");
#endif
}

// CPU info wrapper
void show_cpu_info() {
    printf("-------------------------------------\n");
    printf("| CPU info:\n");
    printf("| CPU cores: %d\n", get_cpu_count());
    show_cpu_model();
    printf("-------------------------------------\n");
}




int main() {
    char notes[100];
    //define D.Note
    char wall1[50];
    char wall2[50];
    char wall3[50];
    char wall4[50];
    char wall5[50];
    char wall6[50];
    char wall7[50];
    char wall8[50];
    char wall9[50];
    char wall10[50];
    char wall11[50];
    //define system variables
    // Write C code here
    printf("------------\n|  welcome |\n------------\n\n---");
    
    printf("------------\n| D.eSystem 5 |\n---------------\n");
    
    
    printf("---------------------\n| Type 2 to cotinue |\n---------------------\n");
    int setup;
    scanf("%d", &setup);
    if (setup == 2) {
        printf("---------------\n| Welcome in  |\n| D.eSystem 5 |\n---------------\n");
    } else { printf("---------------\n|Unknown input|\n---------------\n");
    }
    int a = 1;
    //printf( "%d \n", a );
    printf("----------------------------------\n| Type a name for your account!! |\n----------------------------------\n");
    char account[50];
    scanf("%49s", account);
    printf("------------------------\n");
    printf("|   Your account is    |\n");
    printf("| %-21s|\n", account);
    printf("|                      |\n");
    printf("------------------------\n");
    //create account/*
    printf("-----------------------------------\n");
    printf("|Do you want to create a password?|\n");
    printf("|   If yes type 1, else type 2    |\n");
    printf("-----------------------------------\n");
    // Password sellection
    int option_setup;
    scanf("%d", &option_setup);
    int cmd = 0; 
    int mode = 0;
    if (option_setup == 1) {
        printf("---------------------\n");
        printf("| Create a password |\n");
        printf("---------------------\n");
        char password[50];

        scanf("%49s", password);
        strcpy(wall1, password);
        strcpy(wall2, password);
        strcpy(wall3, password);
        strcpy(wall4, password);
        strcpy(wall5, password);
        strcpy(wall6, password);
        strcpy(wall7, password);
        strcpy(wall8, password);
        strcpy(wall9, password);
        strcpy(wall10, password);
        strcpy(wall11, password);
        //int mode = 0;
        
    //Create password
        
    }else { printf("---------------------------\n| You created no password |\n---------------------------\n\n");
    //Setup (D.eSystem)
    
    //Kernel(D.Core 3)/*
    }
    while(1) {
        if (mode == 0) {
            //int cmd = 0;
            printf("----------------------------------------\n");
            printf("| 1: shutdown                          |\n");
            printf("| 2: calculator                        |\n");
            printf("| 3: news                              |\n");
            printf("| 4: max                               |\n");
            printf("| 5: clock                             |\n");
            printf("| 6: calendar                          |\n");
            printf("| 7: D.eSystem version                 |\n");
            printf("| 8: D.Note                            |\n");
            printf("| 9: lockscreen                        |\n");
            printf("| 10: sports                           |\n");
            printf("| 11: About this PC                    |\n");
            printf("| 12:thundercalculator                 |\n");
            printf("----------------------------------------\n");
            scanf("%d", &cmd);

            if (cmd == 1) {
                 mode = 1;

            
            }

            if (cmd == 2) {
                mode = 2;
            }

            if (cmd == 3) {
                mode = 3;
            }
            if (cmd == 4) {
                mode = 4;
            }
            if (cmd == 5) {
                mode = 5;
            }
            if (cmd == 6) {
                mode = 6;
            }

            if (cmd == 7) {
                mode = 7;
            }

            if (cmd == 8) {
                mode = 8;
            }
            if (cmd == 9) 
            {
                mode = 9;
            }
            if (cmd == 10) {
                mode = 10;
            }
            if (cmd == 11) {
                mode = 11;
            }
            if (cmd == 12) {
                mode = 12;
            }
            if (cmd == 13) {
                mode = 13;
            }
            


            {
                /* code */
            }
            
            
            
        }

        if (mode == 1) {

            printf("-----------------------------------------\n");
            printf("|                                       |\n");
            printf("|                                       |\n");
            printf("|            Shutting down...           |\n");
            printf("|                                       |\n");
            printf("|                                       |\n");
            printf("-----------------------------------------\n");

            break;
            // shutdown


            


        }

        if (mode == 12) {

            int seccond;
            int calculation;
            char contine = 'g';
            printf("----------------------------------------------------------\n");
            printf("|                   Thundercalculator                    |\n");
            printf("|                                                        |\n");
            printf("| How many seconds are between the flash and the thunder?|\n");
            printf("|                                                        |\n");
            printf("| Type 999 to close this app!!                           |\n");
            printf("----------------------------------------------------------\n");

            scanf( "%d", &seccond);

            if (seccond == 999) {
                mode = 0;

            } else {

                calculation = seccond / 3;

                if (calculation < 1) {

                    printf("------------------------------------------------------------\n");
                    printf("| Go fast to a safe place, the thunderstorm is super near!!|\n");
                    printf("|                                                          |\n");
                    printf("------------------------------------------------------------\n");
                    scanf( "%c", &contine);


                } else if (calculation < 3) {

                    printf("------------------------------------------------------------\n");
                    printf("| Thunderstorm is nearly, stay inside a building!!         |\n");
                    printf("|                                                          |\n");
                    printf("------------------------------------------------------------\n");
                    scanf( "%c", &contine);

                } else {
                    printf("------------------------------------------------------------\n");
                    printf("| The thunderstorm isn't near.                             |\n");
                    printf("|                                                          |\n");
                    printf("------------------------------------------------------------\n");
                }

                 
            }

            

        }

        if (mode == 11) {

            int cmd1sys1info = 0;

            printf("--------------------------\n");
            printf("|What do you want to see?|\n");
            printf("| 1: CPU info            |\n");
            printf("| 2: RAM info            |\n");
            printf("| 3: GPU info            |\n");
            printf("| 4: OS info             |\n");
            printf("| 5: home                |\n");
            printf("--------------------------\n");

            scanf( "%d", &cmd1sys1info);

            if (cmd1sys1info == 1) {

                show_cpu_info();

            } else if (cmd1sys1info == 2) {

                printf("-------------------------------------\n");
                printf("| RAM info:\n");
                show_ram_info();
                printf("-------------------------------------\n");


            } else if (cmd1sys1info == 3) {

                printf("-------------------------------------\n");
                printf("| GPU info:\n");
                show_gpu_info();
                printf("-------------------------------------\n");

            } else if (cmd1sys1info == 4) {

                printf("-------------------------------------\n");
                printf("| OS info: D.eSystem 5\n");
                printf("-------------------------------------\n");

            } else if (cmd1sys1info == 5) {
                mode = 0;
            }

        }

        if (mode == 10) {

            int cmd1sports = 0; 
            printf("--------------------------------------------\n");
            printf("|                  Sports                  |\n");
            printf("|                                          |\n");
            printf("| 1: hiking                                |\n");
            printf("| 2: cycling                               |\n");
            printf("| 3: walking                               |\n");
            printf("| 4: soccer                                |\n");
            printf("| 5: home                                  |\n");
            printf("--------------------------------------------\n");

            scanf("%d", &cmd1sports);
            if (cmd1sports == 5) {

                mode = 0;
            } else if (cmd1sports == 1) {

                printf("------------------------------------------------------\n");
                printf("|                     hiking                         |\n");
                printf("| Walk a long time and enjoy the nature and have fun.|\n");
                printf("------------------------------------------------------\n");
            } else if (cmd1sports == 2) {

                printf("-------------------------------------------------\n");
                printf("|                  cycling                      |\n");
                printf("| Go to your bikecycle and go out and ride it.  |\n");
                printf("-------------------------------------------------\n");

            } else if (cmd1sports == 3) {

                printf("---------------------------------------------------------\n");
                printf("|                        walking                        |\n");
                printf("| Go out and walk fast for 10-15 min to make good sport.|\n");
                printf("---------------------------------------------------------\n");
            } else if (cmd1sports == 4) {

                printf("-------------------------------------------------\n");
                printf("|                  soccer                       |\n");
                printf("| Go to an soccer place and train and have fun. |\n");
                printf("-------------------------------------------------\n");

            }

            char contine = 'g';
            scanf( "%c", &contine);
            printf("-----------------------------------------\n");
            printf("|       Type 1 thing to continue        |\n");
            printf("-----------------------------------------\n");
        }

        if (mode == 9) {
            char unlock[50];

            printf("--------------------------------------------\n");
            printf("|                Lockscreen                |\n");
            printf("|                                          |\n");
            printf("| Type your code to unlock                 |\n");
            printf("--------------------------------------------\n");

            scanf("%49s", unlock);

            if (strcmp(unlock, wall1) == 0) {

                 if (strcmp(unlock, wall1) == 0) {

                    if (strcmp(wall1, wall2) == 0) {

                        if (strcmp(unlock, wall3) == 0) {

                            if (strcmp(wall3, wall4) == 0) {

                                if (strcmp(unlock, wall4) == 0) {

                                    if (strcmp(wall4, wall5) == 0) {

                                        if (strcmp(unlock, wall5) == 0) {

                                            if (strcmp(wall5, wall6) == 0) {

                                                if (strcmp(unlock,wall6) == 0) {

                                                    if (strcmp(wall6,wall7) == 0) {

                                                        if (strcmp(unlock, wall7) == 0) {

                                                            if (strcmp(wall7, wall8) == 0) {

                                                                if (strcmp(unlock, wall8) == 0) {

                                                                    if (strcmp(wall8, wall9) == 0){

                                                                        if (strcmp(unlock, wall9) == 0) {
                                                                            if (strcmp(wall9, wall10) == 0) {

                                                                                if (strcmp(unlock, wall10)== 0) {


                                                                                    if (strcmp(wall10,wall11) == 0) {
                                                                                        mode = 0;
                                                                                        printf("--------------------------------------------\n");
                                                                                        printf("|                 Unlocked                 |\n");
                                                                                        printf("--------------------------------------------\n");

                                                                                        


                                                                                    } else {
                                                                                        strcpy(wall10, wall11);
                                                                                        printf("-----------------------------------------------------\n");
                                                                                        printf("|A hack was detected,the lockscreen code was reseted|\n");
                                                                                        printf("-----------------------------------------------------\n");
                                                                                    }
                                                                                } 
                                                                            } else {
                                                                                strcpy(wall9, wall11);
                                                                                printf("-----------------------------------------------------\n");
                                                                                printf("|A hack was detected,the lockscreen code was reseted|\n"); 
                                                                                printf("-----------------------------------------------------\n");
                                                                            } 
                                                                        }
                                                                    } else {
                                                                        strcpy(wall9, wall8);
                                                                        printf("-----------------------------------------------------\n");  
                                                                        printf("|A hack was detected,the lockscreen code was reseted|\n"); 
                                                                        printf("-----------------------------------------------------\n");                                                                    
                                                                    }
                                                                }
                                                            } else {

                                                                strcpy(wall7, wall8);
                                                                printf("-----------------------------------------------------\n");
                                                                printf("|A hack was detected,the lockscreen code was reseted|\n");
                                                                printf("-----------------------------------------------------\n");

                                                            }
                                                        }
                                                    } else {
                                                       strcpy (wall6,wall7);
                                                       printf("-----------------------------------------------------\n"); 
                                                       printf("|A hack was detected,the lockscreen code was reseted|\n");
                                                       printf("-----------------------------------------------------\n");
                                                    }
                                                }
                                            } else {
                                                strcpy (wall5,wall11);
                                                printf("-----------------------------------------------------\n");
                                                printf("|A hack was detected,the lockscreen code was reseted|\n");
                                                printf("-----------------------------------------------------\n");
                                            }
                                        }

                                    } else {
                                        printf("-----------------------------------------------------\n");
                                        printf("|A hack was detected,the lockscreen code was reseted|\n");
                                        printf("-----------------------------------------------------\n");
                                        strcpy (wall4,wall6);
                                    }                                   
                                }

                            } else {
                              printf("-----------------------------------------------------\n");
                              printf("|A hack was detected,the lockscreen code was reseted|\n");
                              printf("-----------------------------------------------------\n");
                              
                              strcpy (wall3, wall4);
                            }
                        }

                    } else {

                        printf("-----------------------------------------------------\n");
                        printf("|A hack was detected,the lockscreen code was reseted|\n");
                        printf("-----------------------------------------------------\n");

                        strcpy (wall1, wall2);

                    }

                 } else {
                    printf("--------------------------------------------\n");
                    printf("|               Wrong code!!               |\n");
                    printf("--------------------------------------------\n");
                 }

            } else {
                printf("--------------------------------------------\n");
                printf("|               Wrong code!!               |\n");
                printf("--------------------------------------------\n");
            }

        } // Lockscreen with password


        if (mode == 8) {
            int cmd1note = 0;
            printf("--------------------------------------------\n");
            printf("|                  Notes                   |\n");
            printf("|                                          |\n");
            printf("| 1: create note                           |\n");
            printf("| 2: show notes                            |\n");
            printf("| 3: home                                  |\n");
            printf("--------------------------------------------\n");

            scanf("%d", &cmd1note);

            if (cmd1note == 1) {

                printf("--------------------------------------------\n");
                printf("|             Create a note!               |\n");
                printf("--------------------------------------------\n");

                
                scanf("%99s", notes);

            } else if (cmd1note == 3) {
                mode = 0;

            } else if (cmd1note == 2) {
                

                printf("--------------------------------------------\n");
                printf("|                  Notes                   |\n");
                printf("|                                          |\n");
                printf("|%-42s|\n", notes);
                printf("--------------------------------------------\n");

                char contine = 'g';

                scanf( "%c", &contine);

            }


        }



        if (mode == 7) {
            float kernelversion = 3.5;
            float ui1version = 3.0;
            char brand[15] = "D.electronics";
            char codename[12] = "Watermount";
            float ux1version = 5.2;
            float os1version = 5.0;
            int cmd1info = 0;

            printf("--------------------\n");
            printf("| 1: OS version    |\n");
            printf("| 2: UI version    |\n");
            printf("| 3: UX version    |\n");
            printf("| 4: kernel version|\n");
            printf("| 5: brand         |\n");
            printf("| 6: codename      |\n");
            printf("| 7: home          |\n");
            printf("--------------------\n");

            scanf("%d", &cmd1info);


            if (cmd1info == 1) {

                printf("--------------------\n");
                printf("|    OS version    |\n");
                printf("|                  |\n");
                printf("|  D.eSystem   %f  |\n", os1version);
                printf("--------------------\n");

                // OS info

            } else if (cmd1info == 2) {

                printf("--------------------\n");
                printf("|    UI version    |\n");
                printf("|                  |\n");
                printf("| D.Touch UI m  %f|\n", ui1version);
                printf("--------------------\n");

            } else if (cmd1info == 3) {

                printf("--------------------\n");
                printf("|    UX version    |\n");
                printf("|                  |\n");
                printf("|   String UX %f   |\n", ux1version);
                printf("--------------------\n");

            } else if (cmd1info == 4) {


                printf("--------------------\n");
                printf("|  kernel version  |\n");
                printf("|                  |\n");
                printf("|       v.%f       |\n", kernelversion);
                printf("--------------------\n");

            } else if (cmd1info == 5) {

                printf("--------------------\n");
                printf("|      brand:      |\n");
                printf("|                  |\n");
                printf("|  %s              |\n", brand);
                printf("--------------------\n");

            } else if (cmd1info == 6) {

                printf("--------------------\n");
                printf("|     codename     |\n");
                printf("|                  |\n");
                printf("|  %s              |\n", codename);
                printf("--------------------\n");


            } else if (cmd1info == 7) {
                mode = 0;
            } else {

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");

            }
        }



        if (mode == 6) {

            int cmd1calendar = 0;

            printf("--------------------------------------------\n");
            printf("|                 Calendar                 |\n");
            printf("|                                          |\n");
            printf("| 1: date                                  |\n");
            printf("| 2: home                                  |\n");
            printf("--------------------------------------------\n");

            scanf("%d", &cmd1calendar);



            if (cmd1calendar == 2) {
                mode = 0;
            } else if (cmd1calendar == 1) {

                time_t date;
                struct tm * info;
                time(&date);
                info = localtime(&date);
                printf("--------------------------------------------\n");
                printf("|                Date today                |\n");
                printf("|                                          |\n");
                printf("| %02d.%02d.%04d                               |\n",
                       info->tm_mday,
                       info->tm_mon + 1,
                       info->tm_year + 1900);
                printf("--------------------------------------------\n"); 
                
                char contine = 'g';

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");

                scanf( " %c", &contine);

                {
                    /* data */
                };
                
                


            } else {
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
            }

        }



        if (mode == 5) {

            int cmd1clock = 0;

            printf("--------------------------------------------\n");
            printf("|                  Clock                   |\n");
            printf("|                                          |\n");
            printf("| 1: time                                  |\n");
            printf("| 2: home                                  |\n");
            printf("--------------------------------------------\n");

            scanf("%d", &cmd1clock);

            if (cmd1clock == 2) {

                mode = 0;

            } else if (cmd1clock == 1) {

                time_t now;
                struct  tm * info;

                time(&now);
                info = localtime(&now);

                printf("--------------------------------------------\n");
                printf("|                  Clock                   |\n");
                printf("|                                          |\n");
                printf("| time: %02d:%02d:%02d                           |\n",
                        info->tm_hour, info->tm_min, info->tm_sec);
                printf("--------------------------------------------\n");

                char contine = 'g';

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");

                scanf( "%c", &contine);


                {
                    /* data */
                }
                
            } else {

                 printf("-------------------------------------\n");
                 printf("|         Unknown command!!         |\n");
                 printf("-------------------------------------\n");
            }

        }



        if (mode == 4) {
            int cmdmax1 = 0;
            printf("---------------------------------------------\n");
            printf("|                    Max                    |\n");
            printf("|Choose an option with one of these numbers!|\n");
            printf("|                                           |\n");
            printf("| 1: Chat with Max                          |\n");
            printf("| 2: help                                   |\n");
            printf("| 3: home                                   |\n");
            printf("---------------------------------------------\n");
            scanf("%d", &cmdmax1);

            if (cmdmax1 == 1) {
                char maxchatcmd[50];

                printf("-------------------------------------\n");
                printf("|                Max                |\n");
                printf("|                                   |\n");
                printf("|       What can I do for you       |\n");
                printf("|                                   |\n");
                printf("|   Type home to close this app!!   |\n");
                printf("-------------------------------------\n");

                getchar();
                fgets(maxchatcmd, 50, stdin);

                maxchatcmd[strcspn(maxchatcmd, "\n")] = 0;

                if (strcmp(maxchatcmd, "hi") == 0) {
                    printf("--------------------\n");
                    printf("|  hello friend    |\n");
                    printf("--------------------\n");

                    


                } else if (strcmp(maxchatcmd, "Who are you") == 0) {

                    printf("--------------------------\n");
                    printf("| I am Max, the chatbot  |\n");
                    printf("| from D.eSystem 5.      |\n");
                    printf("--------------------------\n");

                } else if (strcmp(maxchatcmd, "How old are you") == 0) {

                    printf("------------------------------------\n");
                    printf("| I was introduced in december 2024|\n");
                    printf("------------------------------------\n");
                } else if (strcmp(maxchatcmd, "What is this") == 0) {

                    printf("-----------------------\n");
                    printf("| This is D.eSystem 5 |\n");
                    printf("-----------------------\n");

                } else if (strcmp(maxchatcmd, "What is the best OS") == 0) {

                    printf("------------------------\n");
                    printf("| Its D.eSystem 5      |\n");
                    printf("------------------------\n");

                } else if (strcmp(maxchatcmd, "be funny") == 0) {

                    printf("------------------------\n");
                    printf("| hahahahahahahahahaha |\n");
                    printf("------------------------\n");
                }
                {
                    /* code */
                }
                

                char contine = 'g';

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");

                scanf( "%c", &contine);



            
                
            } else if (cmdmax1 == 3) {


                mode = 0;

            } else if (cmdmax1 == 2) {

                printf("----------------------------------------------------------\n");
                printf("| You can type: hi, Who are you, How old are you,        |\n");
                printf("| What is this, What is the best OS, be funny            |\n");
                printf("----------------------------------------------------------\n");

            } else {

                printf("-------------------------------------\n");
                printf("|         Unknown command!!         |\n");
                printf("-------------------------------------\n");

                char contine = 'g';
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");

                scanf ( "%c", contine);

            }


            if (cmdmax1 == 2) {

                printf("---------------------------------------------\n");
                printf("|                                           |\n");
                printf("| You can chat to max:                      |\n");
                printf("| I write it later\n");
                printf("---------------------------------------------\n");

                char contine = 'g';

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
                scanf (" %c", &contine);



            }

            if (cmdmax1 == 3)
            {
                mode = 0;
            }        // Max chatbot
            
        }


        if (mode == 3) {

            int cmdnews = 0;

            printf("--------------------------------------\n");
            printf("|               D.News               |\n");
            printf("| 1: news                            |\n");
            printf("| 2: home                            |\n");
            printf("--------------------------------------\n");

            scanf("%d", &cmdnews);

            if (cmdnews == 1) {
                printf("--------------------------------------\n");
                printf("|               D.News               |\n");
                printf("| D.eSystem 4 came out and it is     |\n");
                printf("| the first D.eSystem which uses C.  |\n");
                printf("|                                    |\n");
                printf("| There is a big leak that           |\n");
                printf("| D.eSystem 4 was the last Python    |\n");
                printf("| based D.eSystem.                   |\n");
                printf("--------------------------------------\n");

                char contine = 'g';
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
                scanf (" %c", &contine);




                




            } else if (cmdnews == 2) {
                mode = 0;
            } else {
                printf("-------------------------------------\n");
                printf("|         Unknown command!!         |\n");
                printf("-------------------------------------\n");

                char contine = 'g';

                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
                scanf (" %c", contine);

            }





            if(cmdnews == 2){
                mode = 0;
            } // D.News

            

        }

        if (mode == 2) {
            int cmdcalculator = 0;
            printf("-----------------------------------------------\n");
            printf("|Choose an operator with one of these numbers!|\n");
            printf("| 1: +                                        |\n");
            printf("| 2: -                                        |\n");
            printf("| 3: *                                        |\n");
            printf("| 4: /                                        |\n");
            printf("| 5: home                                     |\n");
            printf("-----------------------------------------------\n");
            scanf("%d", &cmdcalculator);
            //Launch App (Calculator)

            if (cmdcalculator == 4) {
                double num1calculator = 0.0;
                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|      Type  your first number!!      |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num1calculator);
                double num2calculator = 0.0;

                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|     Type  your second number!!      |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num2calculator);

                double sum = num1calculator / num2calculator;

                printf("-----------------------------------------\n");
                printf("| sum:                                \n");
                printf("| %lf                                 \n", sum);
                printf("-----------------------------------------\n");

                char continue1calculator = 'g';
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n"); 
                scanf(" %c", &continue1calculator);

                //divide

            }

            if (cmdcalculator == 3) {
                double num1calculator = 0.0;
                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|      Type  your first number!!      |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num1calculator);
                double num2calculator = 0.0;

                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|     Type  your second number!!      |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num2calculator);

                double sum = num1calculator * num2calculator;

                printf("-----------------------------------------\n");
                printf("| sum:                                \n");
                printf("| %lf                                 \n", sum);
                printf("-----------------------------------------\n");

                char continue1calculator = 'g';
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
                scanf(" %c", &continue1calculator);

                //multiply


                
            }
            if (cmdcalculator == 2){
                double num1calculator = 0.0;
                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|      Type  your first number!!      |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num1calculator);
                double num2calculator = 0.0;

                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|      Type your second number!!!     |\n");
                printf("|                                     |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num2calculator);

                double sum = num1calculator - num2calculator;
                printf("---------------------------------------\n");
                printf("| sum:                                \n");
                printf("| %lf                                 \n", sum);
                printf("---------------------------------------\n");

                char continue1calculator = 'g';
                printf("-----------------------------------------\n");
                printf("|       Type 1 thing to continue        |\n");
                printf("-----------------------------------------\n");
                scanf(" %c", &continue1calculator);

                //minus



            } 
            if (cmdcalculator == 1) {
                double num1calculator = 0.0;//Plus              

                printf("---------------------------------------\n");
                printf("|                                     |\n");
                printf("|      Type  your first number!!      |\n");
                printf("|                                     |\n");
                printf("|                                     |\n");
                printf("---------------------------------------\n");
                scanf("%lf", &num1calculator);

                if (num1calculator == -143.123456789) {
                    mode = 0;
                } else {

                    double num2calculator = 0.0;

                    printf("---------------------------------------\n");
                    printf("|                                     |\n");
                    printf("|      Type your seccond number!!     |\n");
                    printf("|                                     |\n");
                    printf("|                                     |\n");
                    printf("---------------------------------------\n");

                    scanf("%lf", &num2calculator);

                    double sum = num1calculator + num2calculator;
                    cmdcalculator = 0;

                    printf("---------------------------------------\n");
                    printf("| sum:                                \n");
                    printf("| %lf                                 \n", sum);
                    printf("---------------------------------------\n");

                    char continue1calculator = 'g';

                    printf("-----------------------------------------\n");
                    printf("|       Type 1 thing to continue        |\n");
                    printf("-----------------------------------------\n");
                    scanf(" %c", &continue1calculator);

                    //plus




                }
            



            }

            if (cmdcalculator == 5) {

                mode = 0;
            }
            //Calculator
            
        }


        


        
        
    }
    
    
    

    return 0;
}
//D.eSystem 5 (C)/*
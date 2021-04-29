#define superestring 10

typedef struct estringnodal {
        char username[superestring];
        char password[superestring];       //Credits to Marcela Montserrat
        struct estringnodal *zurdo;
        struct estringnodal *diestro;
}       chavo;

chavo *nvonodal(char username[superestring], char password[superestring])
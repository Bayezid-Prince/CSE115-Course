#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define set_value for(int i=0; i<var;i++)
#ifndef NULL
#define NULL 0
#endif
//customer structure
typedef struct{
    char name[100];
    int packages[10];
    char number[20];
    int price;
}customers;
//dynamic array structure which name is vector
typedef struct dynamic_array{
    customers *data;
    size_t size;
    size_t capacity;
}vector;

int vector_init(vector* v, size_t init_capacity);
void resize(vector* v, size_t new_size);
void push_back(vector* v,customers element);
void mainMenu();
void registerCustomer(vector *v);
void choosePackage(customers *customer);
void showCustomers(vector *v);
void printReceipt(customers data);
void totalIncome(vector *v);
int fileHandler(vector *v, char src[100]);
void fileOpen(vector *v, char src[100]);
void saveCustomerList(vector *v, char location[100]);
void loadCustomerList(vector *v, char location[100]);

int main(){
    int option, is_true=1;
    char location[100]="customer_list.bin";
    vector customer_list;
    if(vector_init(&customer_list, 0)!=0){
        return 0;
    };
    if(access(location,F_OK)!=-1){
    fileOpen(&customer_list, location);
    }
    do{
        mainMenu();
        scanf("%d",&option);
        if(option==1){
            registerCustomer(&customer_list);
        }else if(option==2){
            showCustomers(&customer_list);
        }else if(option==3){
            totalIncome(&customer_list);
        }else if(option==4){
            loadCustomerList(&customer_list, location);
        }
        else if(option==5){
            saveCustomerList(&customer_list, location);
        }else if(option==6){
            fileHandler(&customer_list,location);
            is_true=0;
        }
    }while(is_true);

} //vector initialize
int vector_init(vector* v, size_t init_capacity)

{
  v->data = malloc(init_capacity * sizeof(customers));
  if (!v->data) return -1;

  v->size = 0;
  v->capacity = init_capacity;

  return 0; /* success */
} //*adding new customer which will place in new pointer
void resize(vector* v, size_t new_size){
    customers *new_ptr=(customers*)realloc(v->data,new_size*sizeof(customers));
    v->capacity=new_size;
    v->data=new_ptr;
} //function to add new customer to the array
void push_back(vector* v,customers element){
    if(v->size==v->capacity){
        resize(v,v->size+1);
    }
    v->data[v->size]=element;
    v->size++;
} //print main menu
void mainMenu(){
    system("CLS");
    printf("\tWoman Parlor\n\nChoose an option\n1->Register a customer\n2->Show todays customers\n3->Total Earning\n4->Load Customer List\n5->Save Customer List\n6->Exit\n");
} //function to register a new customer
void registerCustomer(vector *v){
    int var=10;
    system("CLS");
    customers temp;
    set_value temp.packages[i]=0;
    printf("Enter customers first name: ");
    scanf("%s", &temp.name);
    printf("\nEnter mobile no: ");
    scanf("%s", &temp.number);
    choosePackage(&temp);
    temp.price=0;
    for(int i=0; i<10;i++){
        temp.price+=temp.packages[i]==1?1500:0;
        temp.price+=temp.packages[i]==2?1000:0;
        temp.price+=temp.packages[i]==3?5000:0;
        temp.price+=temp.packages[i]==4?500:0;
        temp.price+=temp.packages[i]==5?1000:0;
        temp.price+=temp.packages[i]==6?300:0;
        temp.price+=temp.packages[i]==7?300:0;
        temp.price+=temp.packages[i]==8?600:0;
        temp.price+=temp.packages[i]==9?2000:0;
        temp.price+=temp.packages[i]==10?1500:0;
    }
    push_back(v,temp);
}
//selected items
void choosePackage(customers *customer){
    int is_selected=0;
    int option=0, index=0;
    while (!is_selected){
        system ("CLS");
        printf("1. Hair Treatment Package\n2. Skin Care Treatment Package\n3. Makeover Package\n4. Any Hair Cut-500TK \n5. Any Hair Color-1000TK\n6. Pedicure-300TK\n7. Manicure-300TK\n8. Herbal Facial-600TK\n");
        printf("9. Body Spa-2000TK\n10. Hair Spa-1500TK\n");

        scanf("%d",&option);
        switch (option)
            {
            case 1:
                system ("CLS");
                printf("a.Any Hair Cut\nb.Any Hair color\nc.Hair Wash\nCost=1500TK\n");
                break;
            case 2:
                system ("CLS");
                printf("a.Gold Facial\nb.Pedicure\nc.Manicure\nCost=1000TK\n");
                break;
            case 3:
                system ("CLS");
                printf("a.Full Face Makeover\nb.Sharee Draping\nc.Hair Setup\nCost=5000TK\n");
                break;

            default:
                break;
            }
        if(option>10){
            continue;
        }
        char truth[90];
        printf("PRESS YES FOR SELECTING THIS ITEM ELSE PRESS NO\n");
        scanf("%s",truth);
        if (!strcmp(truth, "YES")||!strcmp(truth,"yes"))
        {
            char con[10];
            customer->packages[index]=option;
            index++;
            printf("Do you want to select more items? Press YES to continue\n");
            scanf("%s", con);
            if(!strcmp(con, "YES")||!strcmp(con,"yes")){
                is_selected=0;
            }else
            {
                is_selected=1;
            }
        }
    }
} //show registered customers and return back to the main menu
void showCustomers(vector *v){
    system("CLS");
    int option;
    if(v->size!=0){
    for(int i=0; i<v->size; i++){
        printf("%d. %s\n", i+1, v->data[i].name);
    }
    printf("%d. Back\nChoose a number: ",v->size+1);
    scanf("%d", &option);
        if(option<=v->size){
            printReceipt(v->data[option-1]);
        }else if(option==v->size+1){
        }
        else{
            printf("\nInvalid Choice\n");

        }getch();
    }else{
        printf("No one has registered yet\n");
        getch();
    }

}
//print customer's receipt
void printReceipt(customers data){
    system("CLS");
    printf("\t\tWoman Parlor\n");
    printf("Name: %s\n", data.name);
    printf("Phone number: %s\n\n", data.number);
    printf("Item list: \n");
    int index=1;
    for(int i=0; i<10; i++){
        if(data.packages[i]!=0){
            char temp[100];
            if(data.packages[i]==1){
                strcpy(temp, "Hair Treatment Package\t\tPrice:1500TK\n");
            }else if(data.packages[i]==2){
                strcpy(temp, "Skin Care Treatment Package\t\tPrice:1000TK\n");
            }else if(data.packages[i]==3){
                strcpy(temp, "Makeover Package\t\t\tPrice:5000TK\n");
            }else if(data.packages[i]==4){
                strcpy(temp, "Any Hair Cut\t\t\t\tPrice:500TK\n");
            }else if(data.packages[i]==5){
                strcpy(temp, "Any Hair Color\t\t\tPrice:1000TK\n");
            }else if(data.packages[i]==6){
                strcpy(temp, "Pedicure\t\t\t\tPrice:300TK\n");
            }else if(data.packages[i]==7){
                strcpy(temp, "Manicure\t\t\t\tPrice:300TK\n");
            }else if(data.packages[i]==8){
                strcpy(temp, "Herbal facial\t\t\tPrice:600TK\n");
            }else if(data.packages[i]==9){
                strcpy(temp, "Body Spa\t\t\t\tPrice:2000TK\n");
            }else if(data.packages[i]==10){
                strcpy(temp, "Hair spa\t\t\t\tPrice:1500TK\n");
            }
            printf("%d. %s",index++, temp);

        }
    }
    printf("\n\t\t\t\t\tTotal:%dTK",data.price);
    getch();
} //to calculate the total income
void totalIncome(vector *v){
    int total=0;
    for(int i=0;i<v->size;i++){
        total+=v->data[i].price;
    }
    printf("Total income: %dTK\n", total);
    getch();
}
//file save
int fileHandler(vector *v, char src[100]){
    FILE *list;
    list=fopen(src,"wb");//*file open to write in binary
    if(list==NULL){
        fprintf(stderr, "\nError opened file\n");
        getch();
        exit(1);
    }
    for(int i=0;i<v->size;i++){
        fwrite(&v->data[i],sizeof(customers),1, list);
    }
    if(fwrite!=0){
        fclose(list);
        return 0;
    }else{
        fclose(list);
        return -1;
    }
}
//file open
void fileOpen(vector *v, char src[100]){
    FILE *customer;
    customer=fopen(src, "r");//*file open to only read
    if(customer==NULL){
        fprintf(stderr, "\nError Opening file\n");
        getch();
        exit(1);
    }else{
        printf("\nFile is successfully loaded\n");
    }
    customers temp;
     vector_init(v,0);
    while(fread(&temp,sizeof(customers),1,customer)==1){
       push_back(v,temp);
    }
    fclose(customer);
} //loaded customer list
void loadCustomerList(vector *v, char location[100]){
    printf("Do you want to load %s? Press yes to continue. Press no to load a different file. Press exit to leave.\n", location);
    char option[4];
    scanf("%s", option);
    if(!strcmp(option,"yes")||!strcmp(option, "YES")){
            fileOpen(v, location);
            getch();
    }
    else if(!strcmp(option,"no")||!strcmp(option, "NO")){
        printf("Type the name of the file: ");
        char src[100];
        scanf("%s", src);
        fileOpen(v,src);
        strcpy(location,src);
        getch();
    }
    else {};
}
//saved customer list
void saveCustomerList(vector *v, char location[100]){
    printf("Do you want to save in %s? Press yes to continue. Press no to select a new name. Press exit to leave.\n", location);
    char option[4];
    scanf("%s", option);
    if(!strcmp(option,"yes")||!strcmp(option, "YES")){
            if(fileHandler(v, location)==0){
                printf("\nSaving successful.\n");
                getch();
            }else{
                printf("\nError saving file.\n");
                getch();
            }
    }else if(!strcmp(option,"no")||!strcmp(option, "NO")){
        printf("Type the name of the file: ");
        char src[100];
        scanf("%s", src);
        fileHandler(v,src);

    }else if(!strcmp(option,"exit")||!strcmp(option, "EXIT")){
    }
}

// phone directory application using doubly link list
// limitations: name only be saved without blank spaces for example: Abdul Rehman can be written as Abdulrehman
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonedirectory
{
    char contactname[20];
    char contactphone[11];
    struct phonedirectory *nextcontact;
    struct phonedirectory *prevcontact;
};

struct phonedirectory *startcontact = NULL;

void addcontact()
{
    struct phonedirectory *total;
    struct phonedirectory *tmp = (struct phonedirectory *)malloc(sizeof(struct phonedirectory));
    int flag = 0;
    char phone[11];
    char contact[20];

    printf("Add Contact Name: ");
    scanf("%s", contact);
    printf("Add Contact Number: ");
    scanf("%s", phone);

    // printf("%d\n", strlen(contact));
    int i = 0, j = 0, k, l;
    for (i = 0; i < strlen(contact); i++)
    {
        tmp->contactname[i] = contact[i];
    }
    tmp->contactname[i] = '\0'; // initialize last string as null

    for (j = 0; j < strlen(phone); j++)
    {
        tmp->contactphone[j] = phone[j];
    }
    tmp->contactphone[j] = '\0';

    tmp->nextcontact = NULL;

    if (startcontact == NULL)
    {
        startcontact = tmp;
        startcontact->prevcontact = NULL;
    }

    else
    {
        struct phonedirectory *currcontact = startcontact;
        //    struct phonedirectory *currcontact2=startcontact->nextcontact;
        struct phonedirectory *currcontact2;
        while (currcontact->nextcontact != NULL) //  this while loop will run when list have more than one contacts and will not run for lastnode
        {
            k = 0, l = 0;
            //  printf("ok %s next %s \n",currcontact->contactname,currcontact->nextcontact->contactname);
            while (l != -1 && k < strlen(tmp->contactname) && currcontact->contactname[k] != '\0' )
            {
                if (strcmp(tmp->contactname, currcontact->contactname) == 0)
                {
                    printf("Name Already Present In Contact List Try Another! :( \n");
                    flag = 1;
                    break;
                }

                else if (tmp->contactname[k] < currcontact->contactname[k])
                {
                    if (currcontact->prevcontact == NULL) // this indicating that contact list is starting
                    {
                        // printf("Hello1\n");
                        flag = 1;
                        // printf("%s ; %s",currcontact->contactname[k],tmp->contactname[k]);
                        //  printf("%c %c",tmp->contactname[k],currcontact->contactname[k]);
                        struct phonedirectory *tmp2 = startcontact;
                        startcontact = tmp;
                        startcontact->nextcontact = tmp2;
                        startcontact->prevcontact = NULL;
                        tmp2->prevcontact = startcontact;
                        break;
                    }

                    else
                    {
                        // printf("hello2\n");
                        flag = 1;
                        struct phonedirectory *tmp2 = currcontact;
                        currcontact = tmp;
                        tmp2->prevcontact = currcontact;
                        currcontact->nextcontact = tmp2;
                        currcontact->prevcontact = currcontact2;
                        currcontact2->nextcontact = currcontact;
                        break;
                    }
                }

                else if (tmp->contactname[k] > currcontact->contactname[k])
                {
                    l = -1;
                    // currcontact = currcontact->nextcontact;
                }

                else
                {
                    k++;
                    // flag = -1;
                }
            }

            if(flag==0 && currcontact->contactname[k] != '\0' && k==strlen(tmp->contactname)){
                if (currcontact->prevcontact == NULL) // this indicating that contact list is starting
                    {
                        // printf("Hello1\n");
                        flag = 1;
                        // printf("%s ; %s",currcontact->contactname[k],tmp->contactname[k]);
                        //  printf("%c %c",tmp->contactname[k],currcontact->contactname[k]);
                        struct phonedirectory *tmp2 = startcontact;
                        startcontact = tmp;
                        startcontact->nextcontact = tmp2;
                        startcontact->prevcontact = NULL;
                        tmp2->prevcontact = startcontact;
                        break;
                    }

                    else
                    {
                        // printf("hello2\n");
                        flag = 1;
                        struct phonedirectory *tmp2 = currcontact;
                        currcontact = tmp;
                        tmp2->prevcontact = currcontact;
                        currcontact->nextcontact = tmp2;
                        currcontact->prevcontact = currcontact2;
                        currcontact2->nextcontact = currcontact;
                        break;
                    }
            }

            else if (flag == 0)
            {
                //  printf("Flag");
                currcontact2 = currcontact;
                currcontact = currcontact->nextcontact;
            }

            else
            {
                break;
            }
        }

        k = 0, l = 0;
        if (currcontact->prevcontact == NULL && currcontact->nextcontact == NULL && flag == 0) // this will run when contact list have only one contact info and flag=0 means the contact have not been added yet in while loop(not neccesary)
        {
            while (l != -1 && k < strlen(tmp->contactname))
            {
                if (strcmp(tmp->contactname, currcontact->contactname) == 0)
                {
                    printf("Name Already Present In Contact List Try Another! :( \n");
                    break;
                }

                else if (tmp->contactname[k] < currcontact->contactname[k])
                {
                    flag = 1;

                    struct phonedirectory *tmp2 = startcontact;
                    startcontact = tmp;
                    startcontact->nextcontact = tmp2;
                    startcontact->prevcontact = NULL;
                    tmp2->prevcontact = startcontact;
                    break;
                }

                else if (tmp->contactname[k] > currcontact->contactname[k])
                {
                    l = -1;
                }

                else
                {
                    k++;
                }
            }

            if (l == -1)
            { // not inserted before start
                // printf("total1\n");
                currcontact->nextcontact = tmp;
                tmp->prevcontact = currcontact;
                flag = 1;
            }
        }
        else if (currcontact->prevcontact != NULL && currcontact->nextcontact == NULL && flag == 0)
        { // this will run for last contact and flag=0 means the contact have not been added yet in while loop(neccesary)
            while (l != -1 && k < strlen(tmp->contactname))
            {
                if (strcmp(tmp->contactname, currcontact->contactname) == 0)
                {
                    printf("Name Already Present In Contact List Try Another! :( \n");
                    break;
                }

                else if (tmp->contactname[k] < currcontact->contactname[k])
                {
                    flag = 1;
                    struct phonedirectory *tmp2 = currcontact;
                    currcontact = tmp;
                    tmp2->prevcontact = currcontact;
                    currcontact->nextcontact = tmp2;
                    currcontact->prevcontact = currcontact2;
                    currcontact2->nextcontact = currcontact;
                    break;
                }

                else if (tmp->contactname[k] > currcontact->contactname[k])
                {
                    l = -1;
                }

                else
                {
                    k++;
                }
            }
                
            if (l == -1)
            { // not inserted before last
                currcontact->nextcontact = tmp;
                tmp->prevcontact = currcontact;
                flag = 1;
            }
        }
    }
}
void showcontact()
{
    struct phonedirectory *currcontact = startcontact;
    struct phonedirectory *prev;
    int n = 0;
    if (startcontact == NULL)
    {
        printf("Empty Phone Directory!! :( \n");
    }

    else
    {
        printf("In Ascending Order:\n");
        while (currcontact != NULL)
        {

            n++;
            printf("Contact No : %d Contact : %s --- PhoneNumber : %s\n", n, currcontact->contactname, currcontact->contactphone);
            prev = currcontact;
            currcontact = currcontact->nextcontact;
        }

        printf("In Descending Order:\n");
        while (prev != NULL)
        {
            printf("Contact No : %d Contact : %s --- PhoneNumber : %s\n", n, prev->contactname, prev->contactphone);
            prev = prev->prevcontact;
            n--;
        }
    }
}

void deleteall()
{
    struct phonedirectory *tmp;
    int confirm;
    printf("Are You Sure For Deleting All The Contacts?\n1.Yes 2.No:\n");
    scanf("%d", &confirm);

    

    if (confirm == 1)
    {
        if (startcontact == NULL)
    {
        printf("Empty PhoneDirectory List!!\n");
    }
    else{
        while (startcontact != NULL)
        {
            tmp = startcontact;
            startcontact = startcontact->nextcontact;
            tmp = NULL;
            free(tmp);
        }
    }
        printf("All Contacts Deleted Successfully :) \n");
    }

    else if (confirm == 2)
    {
        printf("Contacts Not Deleting :) \n");
    }
}

void deletecontact()
{
    char contact[20];
    int flag = 0;

    printf("Add Contact Name For Delete:  ");
    scanf("%s", contact);

    struct phonedirectory *currcontact = startcontact, *prev = startcontact->nextcontact;
    if (startcontact == NULL)
    {
        printf("Empty Phone Directory!! :( \n");
        flag = 1;
    }

    else if (strcmp(startcontact->contactname, contact) == 0)
    {
        flag = 1;
        if (startcontact->nextcontact == NULL)
        { // if contacts list have only one contact
            startcontact = NULL;
            free(startcontact);
        }

        else
        {
            prev->prevcontact = startcontact->prevcontact;
            startcontact = startcontact->nextcontact;
            free(currcontact);
        }
    }

    else
    {
        while (prev != NULL)
        {

            if ((strcmp(prev->contactname, contact) == 0))
            {
                flag = 1;

                if (prev->nextcontact == NULL)
                { // if contact is last in list
                    prev = NULL;
                    currcontact->nextcontact = prev;
                    free(prev);
                    break;
                }

                else
                {
                    prev->nextcontact->prevcontact = currcontact;
                    currcontact->nextcontact = prev->nextcontact;
                    free(prev);
                    break;
                }
            }
            prev = prev->nextcontact;
            currcontact = currcontact->nextcontact;
        }
    }

    if (flag == 0)
    {
        printf("Contact Not Founded!!\n");
    }
}

void  searchcontact()
{
    struct phonedirectory *currcontact = startcontact;
    int n=1,flag = 0;
    char contact[20];

    printf("Add Contact Name For Search:  ");
    scanf("%s", contact);
    if (startcontact == NULL)
    {
        printf("Empty PhoneDirectory List!!\n");
        flag = 1;
    }

    else
    {
        while (currcontact != NULL)
        {
            if (strcmp(currcontact->contactname,contact)==0)
            {
                printf("Contact Founded At No %d !!\n", n);
                flag = 1;
            }

            currcontact = currcontact->nextcontact;
                n++;
        }
    }

    if (flag == 0)
    {
        printf("Contact Not Found!! :( \n");
    }
}

void updatecontact()
{
    char search[20],update[20],temp1[20],temp2[11];
    printf("Search The Word You Want To Update: ");
    scanf("%s",search);
    printf("Update The Word: ");
    scanf("%s",update);
    int flag=0,k,l;
  struct phonedirectory *currcontact = startcontact;
  struct phonedirectory *curr1,*curr2,*curr3=startcontact;

  while(curr3!=NULL){
    if (strcmp(curr3->contactname,update)==0)
    {
        flag=2;
         printf("Name Already Present In Contact List Try Another! :( \n");
    }
    curr3=curr3->nextcontact;
  }
    int n = 1;
    if (startcontact==NULL)
    {
        printf("Empty contact list :( \n");
    }

    else if(flag!=2){
    while (currcontact != NULL)
    {
        if (strcmp(search,currcontact->contactname)==0)
        {
           strcpy(currcontact->contactname, update);
            printf("Value is found in node no: %d and replaced with %s\n", n, update);
            flag = 1;
            break;
        }
        currcontact = currcontact->nextcontact;
        n++;
    }

        // sorting the contact list by bubble sort algo
        for(curr1 = startcontact; curr1->nextcontact != NULL; curr1 = curr1->nextcontact) {  
            for(curr2 = curr1->nextcontact; curr2 != NULL; curr2 = curr2->nextcontact) {   
                l=0,k=0;
               while (l != -1 && k < strlen(curr1->contactname) && curr2->contactname[k] != '\0' )
                {
                    if(curr1->contactname[k]>curr2->contactname[k]){
                    strcpy(temp1,curr1->contactname);
                    strcpy(temp2,curr1->contactphone);
                    strcpy(curr1->contactname,curr2->contactname);
                    strcpy(curr1->contactphone,curr2->contactphone);
                    strcpy(curr2->contactname,temp1);
                    strcpy(curr2->contactphone,temp2);
                    break;
                }

                else if (curr2->contactname[k] > curr1->contactname[k]){
                    l= -1;
                }

                else{
                    k++;
                }
                }
                }
            }  
    }  

    if (flag == 0)
    {
        printf("Update Failed :( \n");
    }
}



void main()
{

    printf("Phone Directory Application !!\n");
    int choice = -1;
    while (choice != 0) // press 0 for exit
    {
        printf("Press From Menu :\n1 For Add Contact\n2 For Remove Contact\n3 For Remove All\n4 For Search Contact\n5 For Show Contacts\n6 For Update Contact\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addcontact();
        }

        else if (choice == 2)
        {
            deletecontact();
        }

        else if (choice == 3)
        {
            deleteall();
        }

        else if (choice == 4)
        {
            searchcontact();
        }

        else if (choice == 5)
        {
            showcontact();
        }

        else if (choice == 6)
        {
            updatecontact();
        }
    }
}
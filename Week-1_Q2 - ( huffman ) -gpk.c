#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
        char ch;
        int freq;
        int we;
        struct node *left;
        struct node *right;
}node;

node * arr[100];
node *head=NULL;
int size=0,start=0;


void insert_node(node * temp){
    arr[size]=temp;
    size++;
}

// sort
void sort_arr(){
    int i,j;
    int n=size;
    node *swap;
    int min_inx;
    for(i=start;i<n-1;i++){
            min_inx=i;
        for(j=i+1;j<n;j++){
          if (arr[j]->freq < arr[min_inx]->freq)
          { min_inx=j;
          }
          else if(arr[j]->freq == arr[min_inx]->freq){
                if(arr[j]->we > arr[min_inx]->we){
                    min_inx=j;
                }
            }
        }
           swap = arr[min_inx];
            arr[min_inx]= arr[i];
            arr[i]= swap;
    }
}

/*void print_arr(){
    for(int i=0;i<size;i++){
        printf("%c :: %d\n",arr[i]->ch,arr[i]->freq);
    }
}
*/
node * get_min(){
    node * temp=arr[start];
    start++;
    return temp;
}
/*
void preOrder(node *root){
    if(root){
        printf("%d ", root->freq);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root){
    if(root){
        inOrder(root->left);
        printf("%d ", root->freq);
        inOrder(root->right);
    }
}*/
void print(node *temp,char *code)
{
        if(temp->left==NULL && temp->right==NULL)
        {
                printf(" %c :: %s\n",temp->ch,code);
                return;
        }
        int length = strlen(code);
        char leftcode[10],rightcode[10];
        strcpy(leftcode,code);
        strcpy(rightcode,code);
        leftcode[length] = '0';
        leftcode[length+1] = '\0';
        rightcode[length] = '1';
        rightcode[length+1] = '\0';
        print(temp->left,leftcode);
        print(temp->right,rightcode);
}
int main(){
        int n ;
        printf("Enter the no of characters: ");
        scanf("%d",&n);
        printf("Enter the characters and their frequencies: \n");
        char ch;
        int freq,i;
        for(i=0;i<n;i++)
        {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;
                insert_node(temp);
        }
        if(n==1)
        {
                printf("char \"%c\" code : 0\n",ch);
                return 0;
        }
        sort_arr();
        //printf("--------\nsorted \n------------------------------------\n");
        //print_arr();
        for(i=0;i<n-1 ;i++)
        {
                node * left = get_min();
                left->we=0;
                node * right = get_min();
                right->we=1;
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                temp->we=INT_MAX;
                insert_node(temp);
                sort_arr();
               // print_arr();
                //printf("-------------------\n");
        }

        //printf("%d====%d\n\n",arr[size-1]->freq,arr[size-1]->we);
        head=arr[size-1];
        printf("------------------------------------\n");
        char code[10];
        code[0] = '\0';
        print(head,code);

    /*
        printf("PreOrder: \n");
        preOrder(arr[size-1]);
        printf("\n");
        printf("InOrder: \n");
        inOrder(arr[size-1]);
        */
}
/*
5
A 3
B 5
C 6
D 4
E 2

output:
D :: 00
 E :: 010
 A :: 011
 B :: 10
 C :: 11
*/


/*
 
 Implementing Mealy Machine !!
 
 ----------------------------------------------------------------------------------------------------------
    INPUT FILE FORMAT:
 
    (Initial state is assumed to start with 0)
     
    State_Number1 [space separated] o/p1 [space separated] State_Number2 [space separated] o/p1 ..... 

 ----------------------------------------------------------------------------------------------------------
    Console: Input the STRING
 ----------------------------------------------------------------------------------------------------------
    OUTPUT FORMAT: Output String by the Machine
 ----------------------------------------------------------------------------------------------------------
 */
 

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    
    
    
    fstream file;
    file.open("mealy.txt");

    int f[50];
    int x=0;
    int state[50][50],output[50][50];

    int r=0,col;
    char line[50];
    int len;
    int mat[100][50];
    while(file)
    {
        file.getline(line,50);
               
       puts(line);
        //cout<<line[0];
        int c=0;
        len=strlen(line);
        int i=0;
        while(i<len)
        {
            if(line[i]=='-')
                state[r][c]=-1;
            else state[r][c]= line[i]-'0';
            i+=2;
            
            if(line[i]=='-')
                output[r][c]=-1;
            else output[r][c]= line[i]-'0';
            i+=2;
            c++;
            col=c;
        }
        
        //cout<<"col"<<col<<endl;
        r++;
    }
    r--;
    /*
    cout<<"\n\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<col;j++)
            cout<<output[i][j]<<"\t";
        cout<<endl;
    }
     */
    
    int  choice;
    
    do
    {

    cout<<"\nENTER STRING: ";
    char str[100];
    cin>>str; 
        
    int len=strlen(str);
    int i=0;
    int row=0;
    while(i<len)
    {
        int input=str[i]-'a';
        
        if(output[row][input]==-1)
        {
            cout<<" --error--";
            break;
        }
        
        else cout<<output[row][input];
        row=state[row][input];
        //cout<<"row"<<row<<endl;
        
        i++;
        
    }              
              
    cout<<"\nPress 1 to Continue...\n\n";
        
        cin>>choice;    
    }while(choice);


    
    return 0;
}
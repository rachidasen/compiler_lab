
/*
 
    Implementing Moore Machine !!
 ----------------------------------------------------------------------------------------------------------
    INPUT FILE FORMAT:
 
    (Initial state is assumed to start with 0)
 
    output of each state [space separated] State_number [space separated] State_number ...
 
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
    file.open("moore.txt");

    int f[50];
    int x=0;
    int state[50][50],output[50];

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
        
        if(line[0]=='-')
            output[r]=-1;
        else output[r]= line[0]-'0';
        
        i+=2;
    
        
        
        while(i<len)
        {
            if(line[i]=='-')
                state[r][c]=-1;
            else state[r][c]= line[i]-'0';
            i+=2;
            
            c++;
            col=c;
        }
        
        
        r++;
    }
    r--;
/*
    cout<<"\n\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<col;j++)
            cout<<state[i][j]<<"\t";
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
        
    cout<<output[row];
    while(i<len)
    {
        int input=str[i]-'a'; 
        
        if(state[row][input]==-1)
        {
            cout<<" --error--";
            break;
        }
        else
        {
           row=state[row][input];
            cout<<output[row];
        }
      
        
        i++;
        
    }
        
   
              
              
    cout<<"\nPress 1 to Continue...\n\n";
        
        cin>>choice;    
    }while(choice);


    
    return 0;
}
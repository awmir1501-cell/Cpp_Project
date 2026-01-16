#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
int scoreboard(int n,string nam)
{
    ofstream board("scoreboard.txt",ios::app);
    board<<n<<"\t"<<nam<<"\n";
    board.close();
}
int main()
{
    srand( time(0) );
    string text[100];
    string text2[100];
    char text3[100];
    string line;
    int i=0;
    string name;
    cout<<"================================================\n";
    cout<<"\tWelcome to general knowledge test\n";
    cout<<"================================================\n";
    cout<<"Enter your Full Name  ";
    getline(cin,name);
    ifstream file("filecheck.txt");
    while(getline(file,line))
    {
        text[i]=line;
        i++;
    }
    file.close();
    string line2;
    ifstream file2("fileoptions.txt");
    int k=0;
    while(getline(file2,line2))
    {
        text2[k]=line2;
        k++;
    }
    file2.close();
    ifstream file3("fileAns.txt");
    for(int i=0;i<100;i++)
    {
        file3>>text3[i];
    }
    file3.close();
    char key;
    bool check[100]={false};
    int correct=0,wrong=0;
    for (int i=0;i<20;i++)
    {
        int j;
        do{
            j=rand() %100;
        }while(check[j]);
        check[j]=true;
        cout<<text[j]<<endl;
        cout<<text2[j]<<endl;
        for(int k=10;k>0;k--)
        {
            Beep(1500,10);
            Sleep(1000);
            cout<<"Time Left "<<k<<" "<<"\r\r";
            if(kbhit())
            {
                key=getch();
                key=toupper(key);
                if(key=='A'||key=='B'||key=='C')
                {
                if(key==text3[j])
                {
                    cout<<"\nCorrect\n";
                    correct=correct+10;
                    Beep(1500,300);
                    break;
                }
                else{
                    cout<<"\nWrong\n";
                    wrong++;
                    Beep(1000,300);
                    break;
                }
            }
            else
            {
                continue;
            }

            }
        }
    }
    cout<<"Your name is = "<<name;
    cout<<"\nYor Total Score is = "<<correct;
    cout<<"\nTotal Wrong answers are = "<<wrong;
    scoreboard(correct,name);
    return 0;
}   

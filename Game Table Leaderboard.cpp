
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Aufgabe: H1
Nachname: MAHFOUZ
Vorname: KAREEM
Matrikelnummer: 3085597
Uni-Email: kareem.mahfouz@stud.uni-due.de
Studiengang: ISE CE
*/

struct Team
{
    string name;
    int collectedPoints;
    int doneMatches;

};
void Aufgabe2(int number ,struct Team teams[])
{
    cout<<"input of teams"<<endl<<"=============="<<endl;
    for(int i=0;i<number;i++)
    {
    cout<<"Team "<<i+1<<": ";
    cin>>teams[i].name;

    teams[i].collectedPoints=0;
    teams[i].doneMatches=0;

    }
    cout<<endl;
};

void Aufgabe3(int number,struct Team teams[])
   {
       cout<<"initial ranking"<<endl;
       cout<<"==============="<<endl;
       cout<<"Points"<<'\t'<<"done matches"<<'\t'<<"Name"<<endl;
       for(int i=0;i<number;i++)
       {
           cout<<teams[i].collectedPoints<<'\t'<<teams[i].doneMatches<<'\t'<<'\t'<<teams[i].name<<endl;

       }
       cout<<endl;
   };

   int Aufgabe4(int number,struct Team teams[])
   {
     int index;
     cout<<"Please choose team 1?"<<endl;
     cout<<"teams"<<endl<<"====="<<endl;
     for(int i=0;i<number;i++)
       {
           cout<<i+1<<'\t'<<teams[i].name<<endl;
       }
     cout<<"Choose Team by number:";
     cin>>index;
     cout<<endl;
     return index-1;

   }


      int Aufgabe42(int number,struct Team teams[])
   {
       int index;
       cout<<"Please choose team 2?"<<endl;
       cout<<"teams"<<endl<<"=================="<<endl;
       for(int i=0;i<number;i++)
       {
           cout<<i+1<<'\t'<<teams[i].name<<endl;
       }
     cout<<"Choose Team by number:";
     cin>>index;
     cout<<endl;
     return index-1;

   }

 void Aufgabe5(int number,struct Team teams[],int index,int points )
 {
    Team temp;

    teams[index].collectedPoints=points;
    teams[index].doneMatches++;
    for(int i=0;i<number;i++)
    {
        for(int j=0;j<number-i-1;j++)
        {
            if(teams[j].collectedPoints<teams[j+1].collectedPoints)
            {

                temp=teams[j];
                teams[j]=teams[j+1];
                teams[j+1]=temp;
            }
        }
    }

 }
 void Aufgabe6(int number,struct Team teams[])
 {
     for(int i=0; i<number;i++)
     {
        teams[i].collectedPoints=0;
        teams[i].doneMatches=0;
     }


 }

int main()
{
    int choice;
    int points;
    int point1,point2;
    char c;
    int TeamNr;
    int index1,index2;



    cout<<"number of teams : ";
    cin>>TeamNr;
    cout<<endl;
    Team teams[TeamNr];
    Aufgabe2(TeamNr,teams);
    Aufgabe3(TeamNr,teams);

    do
    {
        cout<<"0 end"<<endl;
        cout<<"1 add result of a match"<<endl;
        cout<<"2 show ranking"<<endl;
        cout<<"9 reset points"<<endl;
        cout<<"your choice : ";
        cin>>choice;
        switch(choice)
        {


            case 0:break;
            case 1:
            {


                index1 = Aufgabe4(TeamNr,teams);
                index2 = Aufgabe42(TeamNr,teams);
                  if(index1 != index2)
                {

                cout<<"input as [Points of "<<teams[index1].name<<"] : [Points of "<<teams[index2].name<<"]? ";

                cin>>point1>>c>>point2;
                Aufgabe5(TeamNr,teams,index1,point1);
                Aufgabe5(TeamNr,teams,index2,point2);

                }
                else
                  cout<<"*** sorry teams need to be different ***"<<endl ;

                break;
            }
                case 2:
                {
                    Aufgabe3(TeamNr,teams);
                    break;
                }

                case 9:
                {

                Aufgabe6(TeamNr,teams);
                break;

                }
        default: cerr<<"Wrong choice, please enter a correct choice"<<endl;


        }


    }
    while(choice !=0);


return 0;
}

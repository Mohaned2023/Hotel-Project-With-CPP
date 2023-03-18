//! ------------ Programmed By Mohaned Mohammed Sherhan ---------------------
#include <iostream>
#include <string>
using namespace std ;

struct Object
{
    string name ;
    int daye;
    string room;
}*p,x;

string list_name[13] , list_rooms[13] ,id, inp , rooms_out[] = {"1","2","3","4","5","6","7","8","9","a","b","c","d"};
int list_days[13] , i=0 ,id_int=-1,  counter=0 , number_find=0 , n=-1 ;

// def to find the room in room_out ....
int find(string liter ,string where = "false")
{
    if (where == "false"){
        for (string x : rooms_out){
        if (x == liter ){n = number_find;break;}
        else{n = -1;}
        number_find++;}
    }
    else if (where == "true"){
        for (string x : list_rooms){
        if (x == liter ){n = number_find;break;}
        else{n = -1;}
        number_find++;}
    }
    number_find = 0; 
    return n ;
}

// def to search in list and print the list .....
void search(int num_index , string all="f",string no_one="f")
{
    if (all == "f" && no_one == "f"){
        cout <<">> The room { "<< list_rooms[num_index] <<" } <<"<<endl;
        cout << "1- Name: "<<list_name[num_index]<<endl;
        cout << "2- Days: "<<list_days[num_index]<<endl;
        cout << "3- Room: "<<list_rooms[num_index] <<endl;
    }
    else if (all == "t" && no_one == "f"){
        for (int x = 0 ; x < counter; x++){
            cout <<">> The room { "<< list_rooms[x]<<" } <<"<<endl;
            cout << "1- Name: "<<list_name[x]<<endl;
            cout << "2- Days: "<<list_days[x]<<endl;
            cout << "3- Room: "<<list_rooms[x]<<endl; cout <<endl;
        }
    }
    else if (all =="t" && no_one =="t" ){
        cout <<">> The room { "<< id <<" } <<"<<endl;
        cout << "1- Name: None"<<endl;
        cout << "2- Days: "<<0<<endl;
        cout << "3- Room: "<<id<<endl;
    }
}

// search in room if is true ....
void room_error()
{
    while (true){
        cout <<"Please enter another room : ";
        cin >>p->room ;
        if (find(p->room) == -1 || p->room == "*"){cout <<"There is no room or has been booked ."<<endl;continue;}
        else if (find(p->room) != -1){rooms_out[n] = "*";break;}
    }
}

int main ()
{
    p =& x ;
    while (true)
    {
        cout <<"The Number of people is "<<counter<<endl;
        cout <<endl; cout <<"Enter { sall } to search all adds , { seach } to search whith id , { n } to stop."<<endl;
        cout <<"----> ";
        cin >> inp; cout <<endl;
        if (inp == "n") {cout<<"See you ....! "<<endl; break;}
        else if (inp == "sall" || inp == "Sall")
        {
            search(1,"t","f");continue;  
        }
        if (inp == "search" || inp == "Search")
        {
            cout <<"Enter the room : ";
            cin >> id ; cout <<endl;
            if (find(id,"false") != -1){
                for(int a=0 ;a < 13 ; a++ ){
                    if (id == list_rooms[a]){id_int = a;search(id_int,"f","f");id_int=-1;break;}
                    else if (a == 12 && id_int == -1 ){search(10,"t","t");}
                }
                continue;
            } 
            else if (find(id,"true")!=-1) {
                for(int a=0 ;a < 13 ; a++ ){
                    if (id == list_rooms[a]){id_int = a;search(id_int,"f","f");id_int=-1;break;}
                    else if (a == 12 && id_int == -1 ){search(10,"t","t");}
                }
                continue;
            } 
            else {cout <<"Room not fond ."<<endl;continue;}
        }
        else {
            cout <<"The rooms are { ";
            for (string x : rooms_out){cout <<x <<"-";} cout <<" } "<<endl;
            cin.get();
            cout <<"Customer name : ";
            getline(cin,p->name);
            cout <<"How many days : ";
            cin >>p->daye;
            cout <<"Enter The room : ";
            cin >>p->room;
            if (find(p->room) == -1 || p->room == "*" || p->room.length()>1){room_error();}
            else{rooms_out[n] = "*";}
            list_name[i] = p->name ; list_days[i] = p->daye ; list_rooms[i] = p->room;
            counter++; i++;
        }
    }
}

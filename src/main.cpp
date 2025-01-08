#include <iostream>
#include<vector>
#include<fstream>
#include"movie.hpp"
#include"admin.hpp"
#include"client.hpp"

using std::cout;
using std::cin;
using std::endl;


void admin();
void client();


std::vector<std::vector<int>>matrix1(5,std::vector<int>(5,0));
std::vector<std::vector<int>>matrix2(5,std::vector<int>(5,0));
std::vector<Movie>movies;
jl::Admin admin1;
jl::Client client1;

int c1,c2,row,column;
int choice{};
bool p1 =true;
bool p2=true;
bool pause=true;
int main(){

    cout<<"1 - Admin"<<endl<<"2 - Client"<<endl<<"3 - End"<<endl;
    cin>>c1;
    switch (c1)
    {
    case 1:
        admin();
        break;
    case 2:
        client();
        break;
    default:
            break;
        }
}

void admin(){
    while(p1){
        cout<<"1 - Login"<<endl<< "2 - Registration"<<endl<<"0 - End"<<endl;
        cin>>c1;
        switch (c1)
        {
        case 1:
            admin1.login(p2);
            while(p2){
            cout<<endl<<"Choose what you want to do:"<<endl;
            cout<<endl<<"1 - Add movie"<<endl<<"2 - Show movies"<<endl<<"3 - Delete movie"<<endl<<"4 - Show seat"<<endl<<"5 - Reset seat"<<endl<<"0 - End"<<endl;
            cin>>c2;
                switch (c2)
                {
                case 1:
                    admin1.addMovie(movies);
                    break;
                case 2:
                    admin1.showMovies();
                    break;
                case 3:
                    admin1.showMovies();
                    admin1.deleteMovie();
                    break;
                case 4:
                    int r;
                    cout<<"Enter the room you want to see"<<endl;
                    cin>>r;
                    admin1.showSeat(r,matrix1,matrix2);
                    break;
                case 5:
                    int res;
                    cout<<"Enter the room you want to reset"<<endl;
                    cin>>res;
                    switch (res)
                    {
                    case 1:
                        admin1.reset(matrix1,"Places_1.txt");    
                        break;
                    
                    case 2:
                        admin1.reset(matrix2,"Places_2.txt");
                        break;
                    }
                    
                    break;
                case 0:
                    p1=0;
                    p2=0;
                    break;
                default:
                    cout<<"Wrong number"<<endl;
                    p1=0;
                    p2=0;
                    break;
                }
            }
            break;
        case 2:
            admin1.registration();
            break;
        case 0:
            p1=false;
            break;
        
        default:
            break;
        }
    }
}
void client(){
 while(p1){
        cout<<"1 - Login"<<endl<< "2 - Registration"<<endl<<"0 - End"<<endl;
        cin>>c1;
        switch (c1)
        {
        case 1:
            client1.login(p2);
            while(p2){
            cout<<endl<<"Choose what you want to do:"<<endl;
            cout<<endl<<"1 - Show movies"<<endl<<"2 - Show seat"<<endl<<"3 - Buy ticket"<<endl<<"0 - End"<<endl;
            cin>>c2;
                switch (c2)
                {
                case 1:
                    client1.showMovies();
                    break;
                case 2:
                    int r;
                    cout<<"Enter the room you want to see"<<endl;
                    cin>>r;
                    client1.showSeat(r,matrix1,matrix2);
                    break;
                case 3:
                    client1.buyTicket(movies,row,column,matrix1,matrix2);
                    break;
                case 0:
                    p1=0;
                    p2=0;
                    break;
                default:
                    cout<<"Wrong number"<<endl;
                    p1=0;
                    p2=0;
                    break;
                }
            }
            break;
        case 2:
            client1.registration();
            break;
        case 0:
            p1=false;
            break;
        
        default:
            break;
        }
    }
}

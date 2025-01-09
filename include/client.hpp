#pragma once 
#include<iostream>
#include"user.hpp"
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

namespace jl{
    class Client : public User{
    std::string m_name;
    std::string m_password;
    bool m_check=true;
    public:
    Client():User(){};
    Client(std::string name,std::string password) : User(name,password){};
    void setName(std::string name)override{
        if(name.empty()){
            m_name="UNKNOWN";
        }else{
            m_name=name;
        }  
    }
    void setPassword(std::string password)override{
        if(password.empty()){
            m_password="UNKNOWN";
        }else{
            m_password=password;
        }
    }
    std::string getName()const override{
        return m_name;
    }
    std::string getPassword()const override{
        return m_password;
    }
   
    void login (bool &p2)override{
    bool found=false;
    std::string l, line;
    cout<<"### Welcome in login ###"<<endl<<"Enter your name: ";
    cin>>m_name;
    cout<<"Enter your password: ";
    cin>>m_password;
    l=m_name + " : " + m_password;
    std::ifstream file("Client.txt");
    if(!file.is_open()){
        cout<<"Error"<<endl;
    }
    while(std::getline(file,line)){
        if(l==line){
            p2=true;
            found=true;
            break;
        }
    }
    if(found){
        cout<<endl<<"Welcome "<<m_name<<endl;
    }else{
        p2=false;
         cout<<endl<<"Didn't find"<<endl;
    }
    file.close();

    }
    
    void loadS(std::vector<std::vector<int>>&matrix,std::string f)override{
    std::ifstream file(f);
    if (!file.is_open()) {
        cout << "Error" <<endl;
        return;
    }

    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            file>>matrix[i][j];
        }
    }
    file.close();
    }    
    void showMovies()override{
    std::string line;
    int i=1;
    std::ifstream file("Movies.txt");
    if(!file.is_open()){
        cout<<"Error"<<endl;
        return;
    }
     if(file.peek() == std::ifstream::traits_type::eof()){
        cout<<"File is empty"<<endl;
    }else{
        cout<<"Movie: title, author, genre, time, room"<<endl;
        cout<<"---------------------------------------"<<endl;
        while(std::getline(file,line)){
            cout<<"Movie #"<<i<<":  "<<line<<endl;
            i++;
        }
    }

    file.close();
    
    }    
    void showSeat(int c,std::vector<std::vector<int>>&matrix1,std::vector<std::vector<int>>&matrix2)override{
    loadS(matrix1,"Places_1.txt");
    loadS(matrix2,"Places_2.txt");
    if (c==1){
        cout<<"--Screen--"<<endl;
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
        }
    }else if (c==2){
        cout<<"--Screen--"<<endl;
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
        }
    }else{
        cout<<"We dont have this room"<<endl;
    }
    }    
    void registration()override{
    bool found=false;
    std::string l, line;
    cout<<"#### Welcome in registration  ###"<<endl<<"Enter name: ";
    cin>>m_name;
    cout<<"Enter password: ";
    cin>>m_password;
    l=m_name+" : "+m_password;
    std::ifstream file("Client.txt");
    if(!file.is_open()){
        cout<<"Error"<<endl;
    }
    while(std::getline(file,line)){
        if(l==line){
            found=true;
            break;
        }
    }
    file.close();
    if(found){
        cout<<endl<<"It already exists "<<endl;
    }else{
    std::ofstream file("Client.txt",std::ios::app);
    if(!file.is_open()){
        cout<<"Error"<<endl;
    }else{
        file<<l<<endl;
        cout<<"Added"<<endl;
    }
    file.close();
    }
}   
    void loadM(std::vector<Movie>&movies){
     std::ifstream file("Movies.txt");
    if (!file.is_open()) {
        std::cout << "Error" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string title, author, genre, time;
        int room;

        std::getline(stream, title, ',');
        std::getline(stream, author, ',');
        std::getline(stream, genre, ',');
        std::getline(stream, time, ',');
        stream >> room;

        movies.emplace_back(title, author, genre, time, room);
    }

    file.close();
}
    void pickSeat(std::vector<std::vector<int>>matrix,std::string f,int &row,int &column){
    cout<<"Choose row: ";
    cin>>row;
    cout<<"Choose column:" ;
    cin>>column;
    if(row>0&&row<6&&column>0&&column<6){
          if(matrix[row-1][column-1]==0){
            cout<<endl<<"This seat is busy"<<endl;
            m_check=false;
        }else{
            matrix[row-1][column-1]=0;
        }
    }else{
        cout<<"Wrong row or column"<<endl;
    }
    std::ofstream file(f);
    if (!file.is_open()) {
        cout << "Error" <<endl;
        return;
    }

    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            file<<matrix[i][j]<<" ";
        }
        file<<endl;
    }

    file.close();
    
}
    void buyTicket(std::vector<Movie>movies,int &row,int &column,std::vector<std::vector<int>>&matrix1,std::vector<std::vector<int>>&matrix2){
    loadM(movies);
    showMovies();
    int pick;
    cout<<endl<<"Enter the movie you want to see"<<endl;
    cin>>pick;
    for(int i =0;i<movies.size();i++){
        if(pick==0 || pick>movies.size()){
            cout<<"Wrong number"<<endl;
            break;

        }else if(i==(pick-1)){
            movies[i].getTitle();
                    if(movies[i].getRoom()==1){
                        showSeat(1,matrix1,matrix2);
                        pickSeat(matrix1,"Places_1.txt",row,column);
                    }else if (movies[i].getRoom()==2){
                        showSeat(2,matrix1,matrix2);
                        pickSeat(matrix2,"Places_2.txt",row,column);
                    }
                    if(m_check){
                        cout<<endl<<"#### Cinema ticket ####"<<endl;
                        cout<<"Owner: " <<getName()<<" Title: "<<movies[i].getTitle()<<endl;
                        cout<<"Row: "<<row<<" Seat: "<<column<<" Room: "<<movies[i].getRoom()<<endl;
                        break;
                    }
                    
        }
    }
    }
    ~Client(){};
};
}

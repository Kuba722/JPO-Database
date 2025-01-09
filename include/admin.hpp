#pragma once 
#include<iostream>
#include<fstream>
#include"user.hpp"
#include <vector>

using std::cout;
using std::cin;
using std::endl;

namespace jl{
    class Admin : public User{
    std::string m_name;
    std::string m_password;
    public:
    Admin():User(){};
    Admin(std::string name,std::string password) : User(name,password){};
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
    void login(bool &p2)override{
    bool found=false;
    std::string l, line;
    cout<<"### Welcome in login ###"<<endl<<"Enter your name: ";
    cin>>m_name;
    cout<<"Enter your password: ";
    cin>>m_password;
    l=m_name + " : " + m_password;
    std::ifstream file("Admin.txt");
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
        cout<<"Welcome "<<m_name<<endl;
    }else{
        p2=false;
         cout<<"Didn't find"<<endl;
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
    /**
     * \brief pozwala dodać film administartorowi 
     * 
     * Pobiera od administratora potrzebne dane 
     * następnie wrzuca obiekt na koniec wektora 
     * klasy Movie. Otwiera plik i zapisuje dane po 
     * przecinku 
     * \param movies jest to wektor klasy Movie która 
     * zapisuje dane o filmach 
     */
    void addMovie(std::vector<Movie>movies){
    std::string title,author,film_genre,time;
    int room{};
    cout<<"Entry title: ";
    cin.ignore();
    std::getline(cin,title);
    cout<<"Entry author: ";
    std::getline(cin,author);
    cout<<"Entry film_genre: ";
    std::getline(cin,film_genre);
    cout<<"Entry time: ";
    std::getline(cin,time);
    cout<<"Entry room: ";
    cin>>room;
    movies.emplace_back(title,author,film_genre,time,room);
    std::ofstream file("Movies.txt",std::ios::app);
    if (!file.is_open()) {
        cout << "Error" <<endl;
        return;
    }
    for (int i=0;i<movies.size();i++) {
        file << movies[i].getTitle() << "," 
             << movies[i].getAuthor() << "," 
             << movies[i].getFilm_genre() << "," 
             << movies[i].getTime() << "," 
             << movies[i].getRoom() << std::endl;
    }
    file.close();
    cout<<"### Movie added ###"<<endl;
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
    /**
     * \brief Pozawa usunąć film administratorowi
     * 
     * Otwiera plik i zapisuje linie do wektora lines
     * prosi użytkownika o podanie filmu który chce usunąć
     * następnie usuwa wybraną linie oraz zapisuje plik na
     * nowo 
     */
    void deleteMovie(){
    int lineNumber;
    std::vector<std::string> lines;
    std::string line;
    std::ifstream inputFile("Movies.txt");
    if (!inputFile.is_open()) {
        cout << "Error" << std::endl;
        return;
    }
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    cout<<"Enter movie"<<endl;
    cin>>lineNumber;
    if (lineNumber < 1 || lineNumber > lines.size()) {
        std::cerr << "Wrong number " << lineNumber << std::endl;
        return;
    }
     lines.erase(lines.begin() + (lineNumber - 1));// co robi erase 

    std::ofstream outputFile("Movies.txt");
    if (!outputFile.is_open()) {
        cout<< "Error" << std::endl;
        return;
    }

    for (int i=0;i<size(lines);i++) {
        outputFile << lines[i] << endl;
    }

    outputFile.close();
    }   
    /**
     * \brief Pozwala zresetować salę danego filmu
     * 
     * Robi tak że cała sala jest znów dostępna i 
     * wszystkie miejsca są wolne 
     * 
     * \param matrix jest to macierz w której zapisane są 
     * miejsca siedzące 
     * \param f jest to nazwa pliku w którym zapisane 
     * są miejsca siedziące 
     */
    void reset(std::vector<std::vector<int>>&matrix,std::string f){
    for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
         matrix[i][j]=1;
    }
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
    std::ifstream file("Admin.txt");
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
    std::ofstream file("Admin.txt",std::ios::app);
    if(!file.is_open()){
        cout<<"Error"<<endl;
    }else{
        file<<l<<endl;
        cout<<"Added"<<endl;
    }
    file.close();
    }
    }
    ~Admin(){};

    };
}


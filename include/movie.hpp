#pragma once
#include<string> 
#include<iostream>
class Movie {
    std::string m_title;
    std::string m_author;
    std::string m_film_genre;
    std::string m_time;
    int m_room;
public:
    Movie(){
        m_title="none";
        m_author="none";
        m_film_genre="none";
        m_time="0:00";
        m_room=0;
    }
    Movie(std::string title,std::string author,std::string film_genre,std::string time,int room){
        m_title=title;
        m_author=author;
        m_film_genre=film_genre;
        m_time=time;
        m_room=room;
    }
    void setTitle(std::string title){
        m_title=title;
    }
    void setAuthor(std::string author){
        m_author=author;
    }
    void setFilm_genre(std::string film_genre){
        m_film_genre=film_genre;
    }
    void setTime(std::string time){
        m_time=time;
    }
    void setRoom(int room){
        m_room=room;
    }
    std::string getTitle()const{
        return m_title;
    }
    std::string getAuthor()const{
        return m_author;
    }
    std::string getFilm_genre()const{
        return m_film_genre;
    }
    std::string getTime()const{
        return m_time;
    }
    int getRoom()const{
        return m_room;
    }
    void display(){
        std::cout<<"Movie titled: "<<m_title<<" by: "<<m_author<<" film genre: "<<m_film_genre<<" about time: "<<m_time<<" in: "<<m_room<<" room "<<std::endl;
    }
};
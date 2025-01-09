#pragma once
#include<string>

namespace jl{
    class User{
    protected:
    std::string m_name;
    std::string m_password;

    public:
    User(){
        m_name="nobody";
        m_password="none";
    };
    User(std::string name,std::string password);
    virtual ~User(){};
    
    virtual std::string getName()const=0;
    virtual std::string getPassword()const=0;
    virtual void setName(std::string name)=0;
    virtual void setPassword(std::string password)=0;
    virtual void login(bool &p2)=0;
    virtual void loadS(std::vector<std::vector<int>>&matrix,std::string f)=0;
    virtual void showMovies()=0;
    virtual void showSeat(int c,std::vector<std::vector<int>>&matrix1,std::vector<std::vector<int>>&matrix2)=0;
    virtual void registration()=0;
    };
}

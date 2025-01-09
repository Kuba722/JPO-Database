#pragma once 
#include<iostream>
#include"user.hpp"
#include <sstream>
#include <vector>
#include"movie.hpp"

using std::cout;
using std::cin;
using std::endl;

namespace jl{
    class Client : public User{
    std::string m_name; /**client name */
    std::string m_password; /**client password */
    bool m_check=true; /**needed to check if a place is free */
    public:
    /**
     * \brief Default constructor
     * 
     * Creates a object with the default name and password.
     */
    Client():User(){};
     /**
      * \brief Parametric constructor.
      * 
      * Creates a object using the given name and password.
      * \param name variable that stores the name
      * \param password variable that stores the password
      */
    Client(std::string name,std::string password) : User(name,password){};
    /**
     * \brief Sets the name of the object
     * \param name variable that stores the name
     */
    void setName(std::string name);
    /**
     * \brief Sets the password of the object
     * \param password variable that stores the password
     */
    void setPassword(std::string password);
    /**
     * \brief Returns the object name
     */
    std::string getName();
    /**
     * \brief Returns the object password
     */
    std::string getPassword();
    /**
     * \brief logs the user into the system
     * 
     * Gets m_name and m_password then concatenates it
     * to the variable l. The file is opened and checked
     * whether there is a line similar to the variable l
     * if yes, the function welcomes the user, if not informs 
     * about it and does not move to another stage 
     * 
     * \param p2 goes to the next stage after logging in 
     */
    void login (bool &p2);
   /**
     * \brief Loads data from a file into the matrix
     * 
     * Opens the file and inserts the values ​​into the matrix
     * 
     * \param matrix is ​​the matrix in which they are stored 
     * seating 
     * \param f is the name of the file in which they are saved 
     * seating
     */
    void loadS(std::vector<std::vector<int>>&matrix,std::string f);
    /**
     * \brief Displays a list of available videos
     * 
     * Loads videos from a file and displays them on the screen
     * \param line is used to read lines from a file 
     * \param and is used to number movies 
     */
    void showMovies();
    /**
     * \brief displays available seats in the hall
     * 
     * Loads matrices with the loadS a function
     * then displays the available seats in the selected one 
     * room, depending on the selected number, loads the appropriate one
     * matrix
     * 
     * \param c is the room number
     * \param matrix1 is the matrix in which they are stored 
     * seating in room 1
     * \param matrix2 is the matrix in which they are stored 
     * seating in room 2
     */
    void showSeat(int c,std::vector<std::vector<int>>&matrix1,std::vector<std::vector<int>>&matrix2);
    /**
     * \brief Registers a new user
     * 
     * Retrieves data from the user then opens the file
     * and checks if there is already such a user with this
     * with a password if it says so and ends if it is not entered 
     * user to file 
     */
    void registration();
    /**
     * \brief Used to enter the movie class
     * 
     * Opening a file and then separating data after (,)
     * then saves them to the data description 
     * and loads it into the Movie class vector
     * 
     * \param movies is a vector of the Movie class which 
     *saves video data 
     */
    void loadM(std::vector<Movie>&movies);
    /**
     * \brief Allows you to select a seat in the room 
     * 
     * Requests from the user what row and column he wants to occupy
     * then if the conditions are met and there is a place 
     * free, it reserves them and saves them in the file
     * 
     * \param matrix is ​​the matrix in which they are stored 
     * seating 
     * \param f is the name of the file in which it is saved 
     *there are seats 
     * \param row is the row number
     * \param coulmn is the column number 
     * 
     */
    void pickSeat(std::vector<std::vector<int>>matrix,std::string f,int &row,int &column);
    /**
     * \brief Allows a customer to buy a ticket 
     * 
     * Loads videos into the matrix and displays them to the client 
     * then the customer chooses the movie he wants to see 
     * if the selection meets the conditions, they are displayed 
     * seats in the room where the film and the client are 
     *You can choose your seat at the end of your ticket being printed
     * 
     * \param movies is a vector of the Movie class which 
     * saves data about videos 
     * \param row is the row number
     * \param coulmn is the column number 
     * \param matrix1 is the matrix in which they are stored 
     * seating in room 1
     * \param matrix2 is the matrix in which they are stored 
     * seating in room 2
     */
    void buyTicket(std::vector<Movie>movies,int &row,int &column,std::vector<std::vector<int>>&matrix1,std::vector<std::vector<int>>&matrix2);
    /**
     * \brief Deletes an object
     */
    ~Client(){};
};
}

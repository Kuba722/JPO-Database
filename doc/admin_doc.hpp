#pragma once 
#include<iostream>
#include<fstream>
#include <vector>
#include"user.hpp"
#include"movie.hpp"

using std::cout;
using std::cin;
using std::endl;

namespace jl{
    class Admin : public User{
    std::string m_name; /**admin name */
    std::string m_password; /**admin password */
    public:
	/**
	* \brief Default constructor
	* 
	* Creates a object with the default name and password.
	*/
    Admin():User(){};
    /**
	 * \brief Parametric constructor.
	 * 
	 * Creates a object using the given name and password.
     * \param name variable that stores the name
     * \param password variable that stores the password
     */
    Admin(std::string name,std::string password) : User(name,password){};
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
    void login(bool &p2);
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
    * \brief allows the administrator to add a video 
    * 
    * Retrieves the necessary data from the administrator 
    * then throwing the object at the end of the vector 
    *classic movie. Opening a file and saving data after 
    *comma 
    * \param movies is a vector of the Movie class which 
    *saves video data 
    */
    void addMovie(std::vector<Movie>movies);
    /**
     * \brief Displays a list of available videos
     * 
     * Loads videos from a file and displays them on the screen
     * \param line is used to read lines from a file 
     * \param and is used to number movies 
     */
    void showMovies();
    /**
     * \brief Allows the administrator to delete the video
     * 
     * Opens a file and writes lines to a lines vector
     * asks the user to enter the video they want to delete
     * then deletes the selected lines and saves the file to
     *new 
     */
    void deleteMovie();
    /**
     * \brief Allows you to reset the room for a given movie
     * 
     * Makes the entire room available again and 
     *all places are available 
     * 
     * \param matrix is ​​the matrix in which they are stored 
     * seating 
     * \param f is the name of the file in which it is saved 
     *there are seats 
     */
    void reset(std::vector<std::vector<int>>&matrix,std::string f);
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
     * \brief Deletes an object
     */
    ~Admin();

    };
}


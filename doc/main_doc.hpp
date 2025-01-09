#include <iostream>
#include<vector>
#include<fstream>
#include"movie.hpp"
#include"admin.hpp"
#include"client.hpp"

using std::cout;
using std::cin;
using std::endl;




std::vector<std::vector<int>>matrix1(5,std::vector<int>(5,0));/** seats in the first room */
std::vector<std::vector<int>>matrix2(5,std::vector<int>(5,0));/** seats in the second room */
std::vector<Movie>movies; /** movie class vector */
jl::Admin admin1; /** create the admin object */
jl::Client client1; /** create a client object */

int c1;/** variable for selections in main */
int c2;/** variable for selection in client and admin functions */
int row; /** represents the rows in the room */
int column; /** represents the columns in the room */
bool p1 =true;/** needed to handle loops */
bool p2=true;/** needed to handle loops */

/**
 * \brief choose whether we want to enable admin or client
 * 
 * after selecting the appropriate option, the function is called 
 * admin or client 
 */
int main();

/**
 * \brief handling admin selections
 * 
 * at the beginning we choose whether we want to log in or register
 * if login is successful, you have access to five functions 
 * described in the admin class
 */
void admin();
/**
 * \brief handling client selections
 * 
 * at the beginning we choose whether we want to log in or register
 * if login is successful, you have access to five functions 
 * described in the client class
 */
void client();

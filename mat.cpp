/**
 * Author: Nadav Moyal
 */
#include "mat.hpp"
#include<iostream>
#include<vector>
#include <stdexcept>  
#include <string>   
using namespace std;
namespace ariel{
    std::string mat(int col , int row, char c, char d){
        int const MaxChar=126;
        int const MinChar=33;

        if((col%2==0)||(row%2==0)){
            //throw expction & break = even input
            throw runtime_error("even input to 'col' or 'row'");
        }
        if((col<=0)||(row<=0)){  
           //throw expction & break = zero or negative input
            throw runtime_error("zero or negative input to 'col' or 'row'");
        }
        if ((c < MinChar) || (c > MaxChar)){
            //throw expction & break = Unsupported char
            throw runtime_error("Unsupported char - not in the ascii table");
        }
        if((d < MinChar) || (d > MaxChar)){
            //throw expction & break = Unsupported char
            throw runtime_error("Unsupported char - not in the ascii table");
        }

        //creating the first matrix 
        vector<vector<int>> matrix(row, vector<int>(col));
        // filling the matrix by the min of (i,j)
        int i = 0;
        static int j = 0;
        while(i<row){
            j=0;
            while(j<col){
                matrix [i][j] = min(i,j);
                j++;
            }
            i++;
        } 
        //creating the second matrix 
        // fill the second matrix by the min of min(row-i-1,col-j-1) it's kind of mirror of the first matrix.
        //calculating the final matrix by the min of (first matrix[i][j],second matrix[i][j])
        vector<vector<int>> RevMatrix(row, vector<int>(col));
        i = 0;
        j = 0;
        while(i<row){
          j=0;
            while(j<col){
                RevMatrix [i][j] = min(row-i-1,col-j-1);
                matrix [i][j] = min(matrix[i][j],RevMatrix[i][j]);
                j++;
            }
            i++;
        }

        string result;
        //fill the final string with the correct chars by the final matrix .
        i = 0;
        j = 0;
        while(i<row){
            j=0;
            while(j<col){
            if ((matrix[i][j] % 2) == 0)   // If this is true ,then it's the first char. otherwise ,it's the second char.
            {
                 result += c; // True = first char
            }
            else{
                 result += d;  // false = second char
                }
               j++;
            }
            result += "\n";  //  line break
            i++;
        }    

        // printing the matrix for double check 
        //         for ( i = 0; i < row; i++)
        // {
        //    for ( j = 0; j < col; j++)
        //    {
        //       cout << matrix[i][j] << " ";
        //    }
     
        //    // Newline for new row
        //    cout << endl;
        // }     

        return result;
    }




}
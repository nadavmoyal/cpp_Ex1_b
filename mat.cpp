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
            //throw expction & break
            throw runtime_error("even input to 'col' or 'row'");
        }
        if((col<=0)||(row<=0)){  
           //throw expction & break 
            throw runtime_error("zero or negative input to 'col' or 'row'");
        }
        if ((c < MinChar) || (c > MaxChar)){
            //throw expction & break
            throw runtime_error("Unsupported char - not in the ascii table");
        }
        if((d < MinChar) || (d > MaxChar)){
            //throw expction & break
            throw runtime_error("Unsupported char - not in the ascii table");
        }

        //creating the first matrix 
        vector<vector<int>> matrix(row, vector<int>(col));
        // filling the matrix 
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
        

        //  creating the second matrix 
        vector<vector<int>> RevMatrix(row, vector<int>(col));
        i = 0;
        j = 0;
        while(i<row){
          j=0;
            while(j<col){
                RevMatrix [i][j] = min(row-i-1,col-j-1);
                j++;
            }
            i++;
        }

        // create the final martix that we need to fill  
        i = 0;
        j = 0;
        while(i<row){
            j=0;
            while(j<col){
                matrix [i][j] = min(matrix[i][j],RevMatrix[i][j]);
                j++;
            }
            i++;
        } 


        string result;
        //fill the final string in the correct chars by the matrix.
        i = 0;
        j = 0;
        while(i<row){
            j=0;
            while(j<col){
            if ((matrix[i][j] % 2) == 0)
            {
                 result += c;
            }
            else{
                 result += d;
                }
               j++;
            }
            result += "\n";
            i++;
        }    
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
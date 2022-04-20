// Lab9B
// Programmer: Luke Tascone 

#include <iostream>
#include <memory> 
#include <fstream> 

using namespace std; 

int* arrayExpander ( int [], int );
int validateInput ( int );

int* arrayPtr = nullptr; 

int main ()
{

    int numInt; 

    int size;

    int arrayA [49];

    cout << "Enter the numbers of integers to read into the arrray: ";
    cin >> numInt;

    size = validateInput(numInt);

    /////////////

    ifstream inputFile; 
    inputFile.open("/Users/luketascone/Desktop/lrtascone_lab9B/data.txt");

    if (inputFile)
    {

        int count = 0;    

        for ( count = 0; count < size; count++)
        {
            inputFile >> arrayA[count];
            count++;
        }

        inputFile.close();

    }

    ///////// Initial Array 

    cout << "Initial array:" << endl;
    
    for ( int count = 0; count < size; count++ )
    {
        cout << *(arrayA + count) << " ";
    }
    cout << endl;

    ///////// Expanded Arrray 

    int* arrayB = arrayExpander ( arrayA, size ); 

    cout << "Expanded array:" << endl;
    
    for ( int count = 0; count < size; count++ )
    {
        cout << *(arrayB + count) << " "; 
    }
    cout << endl; 

    delete[] newArray;  

    return 0; 
}

int* arrayExpander ( int arr[], int SIZE )
{

    int count = 0;
    int *newArray = new int newArray[2*SIZE];

    while ( count < SIZE )
    {
        newArray = &arr[count];

        count++;
    }

    while ( count < 2*SIZE )
    {
        newArray[count] = 0;

        count++; 
    }
    
    return newArray;      
}

int validateInput ( int input )
{

    if ( input >= 0 && input <= 19 )
        {
            return input;
        }
    else 
    {
        cout << "Values should be between 1 and 20. Enter postition again:";
        cin >> input;
    }    

    return input;    

    ///////

    if ( input > 50 || input < 1 )
        {
            cout << "Error, number must be between 1 and 50." << endl;
            cout << "Enter the number of integers to read into the array: ";
            cin >> input;  
        }
    else 
    {
        return input;
    }    

    return input;

}
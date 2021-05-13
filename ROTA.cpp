#include <iostream>
using namespace std;

int dec_bin(int n)  //decimal to binary

{
    int Bin[32]={0};  //store binary number
    int i = 0;  // counter for binary array

    while (n > 0) {
        Bin[i] = n % 2;   // storing remainder
        n = n / 2;
        i++;
    }

    i=i <= 8 ? 8:i <= 16 ? 16:32;   //make it a standerd bin-num

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--){
        cout << Bin[j];
        if (j%4 == 0)   //to print them in four format 000 111 000
            cout<<" ";
    }
    return i;   //return length of the Binary num
}

int main ()
{
unsigned int num;   //the decimal number input
unsigned int bits;  //how many bits do you wanna to move
unsigned int result;    //store the transformed result
int Rotation=1; //Right or Left

start:

cout << "Number: ";
cin >> num;
cout << "\t";
unsigned int length = dec_bin(num);

cout << endl << "Rotation type (1=right || 0=Left): ";
cin >> Rotation;

cout << "Number of bits for rotation: ";
cin >> bits;

if (Rotation)   //Right rotation
{
    result = ( (num >> (length - bits) ) | (num << bits) ) ^ ( (num >> (length - bits) ) << length) ;

    //printing Right-rotated number + binary
    cout << "Rotate right: " << result << endl << "\t"; 
    dec_bin(result);    
    cout << endl;
}

else    //Left rotation
{
    result = ( ( (num & ((1 << bits) - 1) ) << length ) | num) >> bits;

    //printing Lift-rotated number + binary
    cout << "Rotate left: " << result << endl << "\t";
    dec_bin(result);
    cout << endl;
}

goto start;

return 0;
}
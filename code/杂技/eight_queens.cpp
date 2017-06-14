//eight_queens.cpp  
#include <iostream>  
using namespace std;  
int data[ 8 ][ 8 ]; //chess(double dimensional array)  
int a[ 8 ];   //column(列)  
int b[ 15 ];  //主对角线(左上至右下)  
int c[ 15 ];  //从对角线(右上至左下)  
int count = 0;  
   
void eightQueens( int );  
void output( const int [][ 8 ], int );  
   
int main()  
{  
 int i, j;  
   
 for( i = 0; i < 15; ++i ) //主、从对角线  
  b[ i ] = c[ i ] = 0; //表示安全  
  
 for( i = 0; i < 8; ++i )//chess  
 {  
  a[ i ] = 0;    //i列安全  
  for( j = 0; j < 8; ++j )  
   data[ i ][ j ] = 0;  
 }  
   
 eightQueens( 0 );  
  
 cout << "\ncount = " << count << endl;  
 return 0;  
}  
   
void eightQueens( int line )  
{  
 if( 8 == line )//八个皇后安置就位，输出  
 {  
  output( data, 8 );  
  cout << endl;  
  return;  
 }  
   
  
 for( int column = 0; column < 8; ++column )  
 {  
  if( 0 == a[ column ] && 0 == b[ line - column + 7 ] && 0 == c[ line + column ] )  
  {  
   data[ line ][ column ] = 1; //  安置皇后  
   a[ column ] = 1;   //此列被占  
   b[ line - column + 7 ] = 1; //主对角线被占  
   c[ line + column ] = 1;  //从对角线被占  
   eightQueens( line + 1 ); //下一个皇后  
   //重置  
   data[ line ][ column ] = 0;  
   a[ column ] = 0;  
   b[ line - column + 7 ] = 0;  
   c[ line + column ] = 0;  
  }  
 }  
}  
   
//output chess  
void output( const int data[][ 8 ], int size )  
{  
 for( int i = 0; i < size; ++i )  
 {  
  for( int j = 0; j < size; ++j )  
   cout << data[ i ][ j ] << ' ';  
  cout << endl;  
 }  
 ++count;  
}  

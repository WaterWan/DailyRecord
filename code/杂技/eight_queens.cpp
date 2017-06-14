//eight_queens.cpp  
#include <iostream>  
using namespace std;  
int data[ 8 ][ 8 ]; //chess(double dimensional array)  
int a[ 8 ];   //column(��)  
int b[ 15 ];  //���Խ���(����������)  
int c[ 15 ];  //�ӶԽ���(����������)  
int count = 0;  
   
void eightQueens( int );  
void output( const int [][ 8 ], int );  
   
int main()  
{  
 int i, j;  
   
 for( i = 0; i < 15; ++i ) //�����ӶԽ���  
  b[ i ] = c[ i ] = 0; //��ʾ��ȫ  
  
 for( i = 0; i < 8; ++i )//chess  
 {  
  a[ i ] = 0;    //i�а�ȫ  
  for( j = 0; j < 8; ++j )  
   data[ i ][ j ] = 0;  
 }  
   
 eightQueens( 0 );  
  
 cout << "\ncount = " << count << endl;  
 return 0;  
}  
   
void eightQueens( int line )  
{  
 if( 8 == line )//�˸��ʺ��þ�λ�����  
 {  
  output( data, 8 );  
  cout << endl;  
  return;  
 }  
   
  
 for( int column = 0; column < 8; ++column )  
 {  
  if( 0 == a[ column ] && 0 == b[ line - column + 7 ] && 0 == c[ line + column ] )  
  {  
   data[ line ][ column ] = 1; //  ���ûʺ�  
   a[ column ] = 1;   //���б�ռ  
   b[ line - column + 7 ] = 1; //���Խ��߱�ռ  
   c[ line + column ] = 1;  //�ӶԽ��߱�ռ  
   eightQueens( line + 1 ); //��һ���ʺ�  
   //����  
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

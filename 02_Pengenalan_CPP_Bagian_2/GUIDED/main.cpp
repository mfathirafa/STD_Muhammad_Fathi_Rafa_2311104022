/*
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int x, y; //x dan y bertipe intp
    int *px;//px merupakan variabel pointer menunjuk ke variabel int
    x = 87;
    px = &x;
    y = *px;
    cout <<" alamat x= " << &x << endl;
    cout <<" isi px= " << px << endl;
    cout <<" isi x= " << x << endl;
    cout <<" nilai yang ditunjuk px= " << *px << endl;
    cout <<" nilai y= " << y << endl;
    getch();
    return 0;
}
*/
/*
#include <iostream>
#include <conio.h>
#define MAX 5
 using namespace std;

 int main(){
 int i,j;
 float nilai_total, rata_rata;
 float nilai[MAX];
 static int nilai_tahun[MAX][MAX]=
 { {0,2,2,0,0},
 {0,1,1,1,0},
 {0,3,3,3,0},
 {4,4,0,0,4},
 {5,0,0,0,5}
 };
 /*inisialisasi array dua dimensi */
 /*for (i=0; i<MAX; i++){
 cout<<"masukkan nilai ke-"<<i+1<<endl;
 cin>>nilai[i];
 }
 cout<<"\ndata nilai siswa :\n";

 /*menampilkan array satu dimensi */
 /*for (i=0; i<MAX; i++)
 cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
 cout<<"\n nilai tahunan : \n";

 /* menampilkan array dua dimensi */
 /*for(i=0; i<MAX; i++){
 for(j=0; j<MAX; j++)
 cout<<nilai_tahun[i][j];
 cout<<"\n";
 }
 getch(); // fungsi getch menahan layar ketika program dijalankan
 return 0;
 }
*/
/*
#include <iostream>
using namespace std;

// Fungsi untuk mencari nilai maksimum dari tiga bilangan
int maksimal(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main() {
    int bil1, bil2, bil3;
    cout << "Masukkan nilai bilangan ke-1: ";
    cin >> bil1;
    cout << "Masukkan nilai bilangan ke-2: ";
    cin >> bil2;
    cout << "Masukkan nilai bilangan ke-3: ";
    cin >> bil3;

    int hasil = maksimal(bil1, bil2, bil3);
    cout << "Nilai maksimum adalah: " << hasil << endl;

    return 0;
}
*/

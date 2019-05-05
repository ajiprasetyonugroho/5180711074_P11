#include <iostream>
using namespace std;

char member,barang[50];
string nomor [5]={"A001","A002","A003","A007","A008"};
string nama[5]= {"bayu","irvan","susiati","diana","roni"};
string no,nam,nama_non;
int i,jumlah,jumlah_barang;
float harga,biaya=0,diskon,total=0;

void id(){
cout<<"masukan no id : ";cin>>no;
for(i=0; i<5; i++)
        if(no==nomor[i])
            {
            nam=nama[i];
            }
        cout<<"anda member"<<endl;
        cout<<"nomor identitas : "<<no<<endl;
        cout<<"nama : "<<nam;
}

double data(){
cout<<"\nmasukan jumlah unit barang : ";cin>>jumlah;
for(i=0; i<jumlah; i++){
    cout<<"masukan nama barang ke-"<<i+1<<" : ";cin>>barang;cout<<endl;
    cout<<"masukan harga barang ke-"<<i+1<<" : ";cin>>harga;cout<<endl;
    cout<<"masukan jumlah barang ke-"<<i+1<<" : ";cin>>jumlah_barang;cout<<endl;
    biaya=biaya+(harga*jumlah);
}}

void output(){
    cout<<"\ntotal sebelum kena diskon : "<<biaya;
    diskon=biaya*0.05;
    cout<<"\ntotal potongan            : "<<diskon;
    total=biaya-diskon;
    cout<<"\ntotal setelah kena diskon : "<<total;
}

main(){
cout<<"apakah anda member (Y/T) : ";cin>>member;
if(member=='Y'||member=='y'){
    id();
    data();
    output();
}
else if(member=='T'||member=='t'){
    cout<<"\nmasukan nama : ";cin>>nama_non;
    data();
    cout<<"total bayar : "<<biaya;

}}

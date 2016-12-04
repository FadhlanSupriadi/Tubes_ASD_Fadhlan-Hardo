#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

using namespace std;

int main()
{
    List l;
    mentor x;
    jadwal y;
    address_mentor p;
    address_jadwal q;
    creatementor(l);
    int pilihan;
    int cariID;

    while (pilihan!=13)
    {
        system("CLS");
        cout << "                     SELAMAT DATANG DI CALCULUS FIRST                      " <<"\n"
             << "===========================================================================" <<"\n"
             << "PILIHAN MENU: "<<"\n"
             << "1. Add Mentor"<<"\n"
             << "2. Find Mentor By ID"<<"\n"
             << "3. Delete Mentor and Jadwal"<<"\n"
             << "4. Edit Mentor (Kelompok)"<<"\n"
             << "5. Add Jadwal"<<"\n"
             << "6. Find Jadwal by ID"<<"\n"
             << "7. Delete Jadwal from Mentor"<<"\n"
             << "8. Sorting Kapasitas from Jadwal (Kelompok)"<<"\n"
             << "9. View List Jadwal from Mentor"<<"\n"
             << "10. Cari Kapasitas terbanyak (Reporting)"<<"\n"
             << "11. Cari Kapasitas terdikit (Reporting) "<<"\n"
             << "12. Cari total kapasitas (Reporting) "<<"\n"
             << "13. Exit"<<"\n"
             << "Pilihan: ";
        cin >> pilihan;

        if (pilihan==1)
        {
            system("CLS");
            add_mentor(x);
            address_mentor r=findelm_mentor(l,x.id_mentor);
            if(r==NULL)
            {
                p=alokasi_mentor(x);
                insertlast_mentor(l,p);
                system("CLS");
                cout <<"Data Berhasil di Input"<< endl
                     <<"======================"<<endl;
                printinfo_mentor(l);
            }
            else
            {
                cout << "Data sudah ada";
            };
            getch();
        }
        else if (pilihan==2)
        {
            system("CLS");
            cout << "Masukkan ID mentor yang akan dicari : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if (p != NULL)
            {
                cout<<endl<<"Data sebagai berikut : \n" << endl
                    <<"ID mentor            : "<<info_mentor(p).id_mentor<<endl
                    <<"Nama mentor          : "<<info_mentor(p).nama<<endl
                    <<"Jenis Kelamin Mentor : "<<info_mentor(p).jenis_kelamin<<endl
                    <<"Umur mentor          : "<<info_mentor(p).umur<<endl
                    <<"Alamat mentor        : "<<info_mentor(p).alamat<<endl
                    <<"No.HP mentor         : "<<info_mentor(p).nohp<<endl<<endl;
            }
            else
            {
                cout << endl;
                cout << "Data tidak ada";
            }
            getch();
            system("CLS");
        }
        else if (pilihan==3)
        {
            system("CLS");
            address_jadwal q;
            address_mentor prec;
            printinfo_mentor(l);
            cout << "Masukkan ID mentor yang ingin anda hapus: ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if (p!=NULL)
            {
                while(firstjadwal(p)!=NULL)
                {
                    deletefirst_jadwal(p,q);
                }
                prec = findprec(l,p);
                deleteafter_mentor(l,prec,p);
                system("CLS");
                cout << "Data berhasil dihapus, berikut data sekarang: "<<endl<<endl;
                if(p==NULL)
                {
                    cout << "Tidak ada data lagi";
                }
                else
                {
                    printinfo_mentor(l);
                }
            }
            else
            {
                cout << "Mentor tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==4)
        {
            system("CLS");
            cout << "Data mentor yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_mentor(l);
            cout << endl;
            cout << "Masukkan ID mentor yang ingin Anda ubah : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if (p!=NULL)
            {
                cout<<"Nama mentor          : ";
                cin >> info_mentor(p).nama;
                cout<<"Jenis Kelamin mentor : ";
                cin >> info_mentor(p).jenis_kelamin;
                cout<<"Umur mentor          : ";
                cin >> info_mentor(p).umur;
                cout<<"Alamat mentor        : ";
                cin >> info_mentor(p).alamat;
                cout<<"No.Hp mentor         : ";
                cin >> info_mentor(p).nohp;
                cout << endl;
                cout << "Data berhasil di ubah";
            }
            else
            {
                cout << "Data tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==5)
        {
            system("CLS");
            cout << "Data mentor yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_mentor(l);
            cout << endl;
            cout << "Masukkan ID mentor untuk input Data Jadwal: ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            cout << endl;
            if(p!=NULL)
            {
                cout <<endl;
                add_jadwal(y,p);
                address_jadwal q=alokasi_jadwal(y);
                cout << endl;
                insertlast_jadwal(p,q);
                system("CLS");
                cout << "Data berhasil di input"<<endl<<endl;
                printinfo_jadwal(p,q);
            }
            else
            {
                cout << "Mentor tidak ada";
            }
            getch();
        }
        else if (pilihan==6)
        {
            system("CLS");
            cout << "Data mentor yang ada" << endl
                 << "====================" << endl<<endl;
            printinfo_mentor(l);
            cout << endl;
            cout << "Masukkan ID mentor untuk mencari Data Jadwal : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                cout << endl << "Masukkan ID Jadwal yang Anda cari : " ;
                cin >> cariID;
                q = findelm_jadwal(p,cariID);
                if(q!=NULL)
                {
                    system("CLS");
                    cout<<"Data Jadwal sebagai berikut :" << endl << endl
                        << "ID jadwal : "<< info_jadwal(q).id_jadwal<<endl
                        << "Jam Mulai : "<< info_jadwal(q).jam << endl
                        << "Hari      : "<< info_jadwal(q).hari << endl
                        << "Bulan     : "<< info_jadwal(q).bulan << endl
                        << "Tahun     : "<< info_jadwal(q).tahun << endl
                        << "Kapasitas : "<< info_jadwal(q).kapasitas << endl << endl;
                }
                else
                {
                    system("CLS");
                    cout << endl <<"ID Jadwal tidak ada";
                }
            }
            else
            {
                cout << "Mentor tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==7)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << endl;
            cout << "Masukkan ID mentor untuk menghapus Data Jadwal: ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                int h;
                system("CLS");
                printinfo_jadwal(p,q);
                cout << "Masukkan ID Jadwal yang ingin dihapus: ";
                cin >> h;
                address_jadwal hapus=findelm_jadwal(p,h);
                if(hapus!=NULL)
                {
                    deleteafter_jadwal(p,q,h);
                    cout<<endl;
                    printinfo_jadwal(p,q);
                }
                else
                {
                    cout << "Jadwal tidak ditemukan";
                }
            }
            else
            {
                cout <<"ID mentor belum di input";
            }

            getch();
        }
        else if (pilihan==8)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << endl << "Masukkan ID mentor yang jadwalnya akan di sorting dari kecil ke besar : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                system("CLS");
                SortingKapasitas(p);
            }
            else
            {
                cout << "Mentor tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==9)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << "Masukkan ID mentor untuk menampilkan Data Jadwal : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                system("CLS");
                printinfo_jadwal(p,q);
            }
            else
            {
                cout <<"ID mentor belum di input";
            }
            getch();
        }
        else if (pilihan==10)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << endl << "Masukkan ID mentor untuk mencari kapasitas terbesar dari suatu jadwal : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                system("CLS");
                printinfo_jadwal(p,q);
                cout << endl;
                int x=kapasitasbanyak(p);
                cout << "Kapasitas terbesar pada mentor ini adalah: "<<x;
            }
            else
            {
                system("CLS");
                cout << endl <<"Jadwal tidak ada";
            }
            getch();
        }
        else if (pilihan==11)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << endl << "Masukkan ID mentor untuk mencari kapasitas terdikit dari suatu jadwal : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                system("CLS");
                printinfo_jadwal(p,q);
                cout << endl;
                int x=kapasitassedikit(p);
                cout << "Kapasitas terdikit  pada mentor ini adalah: "<<x;
            }
            else
            {
                system("CLS");
                cout << endl <<"Jadwal tidak ada";
            }
            getch();
        }
        else if (pilihan==12)
        {
            system("CLS");
            printinfo_mentor(l);
            cout << endl << "Masukkan ID mentor untuk mencari total kapasitas dari beberapa jadwal : ";
            cin >> cariID;
            p=findelm_mentor(l,cariID);
            if(p!=NULL)
            {
                system("CLS");
                printinfo_jadwal(p,q);
                cout << endl;
                int x=kapasitastotal(p);
                cout << "Total kapasitas  pada mentor ini adalah: "<<x;
            }
            else
            {
                system("CLS");
                cout << endl <<"Jadwal tidak ada";
            }
            getch();
        }
    }
    return 0;
}


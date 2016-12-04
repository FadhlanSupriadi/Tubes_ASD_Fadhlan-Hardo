#include <iostream>
#include "list.h"

using namespace std;

void creatementor (List &l)
/**
    * FS : first(l) diset NULL
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    first(l) = NULL;
}

//ALOKASI
address_mentor alokasi_mentor (mentor x)
/**
    * FS : Mengembalikan elemen list mentor baru dengan info = x, next elemen = NULL, firstjadwal(p) = NULL
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    address_mentor p=new elmmentor;
    info_mentor(p)=x;
    next(p)=NULL;
    firstjadwal(p)=NULL;
    return p;
}

address_jadwal alokasi_jadwal (jadwal y)
/**
    * FS : Mengembalikan elemen list jadwal baru dengan info = y, next elemen = NULL, prev elemen = NULL
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    address_jadwal p=new elmjadwal;
    info_jadwal(p)=y;
    next(p)=NULL;
    prev(p)=NULL;
    return p;
}

//INSERT FIRST
void insertfirst_mentor (List &l, address_mentor p)
/**
    * IS : List l mentor mungkin kosong
    * FS : Elemen yang ditunjuk p menjadi elemen pertama pada List l mentor
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    if (first(l)==NULL)
    {
        first(l)=p;
    }
    else
    {
        next(p)=first(l);
        first(l)=p;
    }
}

void insertfirst_jadwal (address_mentor &p, address_jadwal &q)
/**
    * IS : List jadwal mungkin kosong
    * FS : Elemen yang ditunjuk q menjadi elemen pertama pada list jadwal
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    if (firstjadwal(p)==NULL)
    {
        firstjadwal(p)=q;
    }
    else
    {
        next(q)=firstjadwal(p);
        prev(firstjadwal(p))=q;
        firstjadwal(p)=q;
    }
}

//INSERT AFTER
void insertafter_mentor (List &l, address_mentor p, address_mentor prec)
/**
    * IS : Prec dan p tidak NULL
    * FS : Elemen yang ditunjuk p menjadi elemen di belakang elemen yang
    *      ditunjuk pointer prec
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    if (next(prec) != NULL)
    {
        next(p) = next(prec);
        next(prec) = p;
    }
    else
    {
        next(prec) = p;
        next(p) = NULL;
    }
}

void insertafter_jadwal (address_mentor &p, address_jadwal &q,int x)
/**
    * IS : Prec dan qtidak NULL
    * FS : Elemen yang ditunjuk q menjadi elemen di belakang elemen yang
    *      ditunjuk pointer prec
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    address_jadwal prec=firstjadwal(p);
    if(prec==NULL)
    {
        insertfirst_jadwal(p,q);
    }
    else
    {
        while (info_jadwal(prec).id_jadwal!=x)
        {
            prec=next(prec);
            {
            }
            if(next(prec)==NULL)
            {
                insertlast_jadwal(p,q);
            }
            else
            {
                prev(q)=prec;
                next(q)=next(prec);
                prev(next(prec))=q;
                next(prec)=q;
            }
        }
    }
}

//INSERT LAST
void insertlast_mentor (List &l, address_mentor p)
/**
    * IS : List mentor l mungkin kosong
    * FS : Elemen yang ditunjuk p menjadi elemen terakhir pada List mentor l
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    address_mentor q;

    if(first(l)==NULL)
    {
        info_mentor(p).id_mentor=1;
        first(l)=p;
    }
    else
    {
        q = first(l);
        while (next(q) != NULL)
        {
            q = next(q);
        }
        info_mentor(p).id_mentor=info_mentor(q).id_mentor+1;
        next(q) = p;
        next(p) = NULL;
    }
}

void insertlast_jadwal (address_mentor &p, address_jadwal &q)
/**
    * IS : List jadwal mungkin kosong
    * FS : Elemen yang ditunjuk q menjadi elemen terakhir pada List jadwal
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    if (firstjadwal(p)==NULL)
    {
        info_jadwal(q).id_jadwal=1;
        firstjadwal(p)=q;
    }
    else
    {
        address_jadwal x = firstjadwal(p);
        while(next(x)!=NULL)
        {
            x=next(x);
        }
        info_jadwal(q).id_jadwal=info_jadwal(x).id_jadwal+1;
        prev(q)=x;
        next(x)=q;
        lastjadwal(p)=q;
    }
}


//DELETE FIRST
void deletefirst_mentor (List &l, address_mentor p)
/**
    * IS : List mentor l mungkin kosong
    * FS : Elemen pertama di dalam List mentor l dilepas dan ditunjuk oleh p
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    if (first(l)==NULL)
    {
        cout << "data tidak ada";
    }
    else
    {
        p=first(l);
        first(l)=next(first(l));
        next(p)=NULL;
    }
}

void deletefirst_jadwal (address_mentor &p, address_jadwal &q)
/**
    * IS : List jadwal mungkin kosong
    * FS : Elemen pertama di dalam List jadwal dilepas dan disimpan/ditunjuk oleh q
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    if (firstjadwal(p)!=NULL)
    {
        q=firstjadwal(p);
        if (next(q)!=NULL)
        {
            firstjadwal(p)=next(firstjadwal(p));
            next(q)=NULL;
            prev(firstjadwal(p))=NULL;
        }
        else
        {
            firstjadwal(p)=NULL;
        }
    }
}

//DELETE AFTER
void deleteafter_mentor (List &l,address_mentor prec, address_mentor &p)
/**
    * IS : Prec tidak NULL
    * FS : Elemen yang berada di belakang elemen prec dilepas
    *      dan ditunjuk oleh p
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    if(p==first(l))
    {
        deletefirst_mentor(l,p);
    }
    else if(next(p) == NULL)
    {
        deletelast_mentor(l,p);
    }
    else
    {
        next(prec) = next(next(prec));
    }
}

void deleteafter_jadwal (address_mentor &p, address_jadwal &q,int y)
/**
    * IS : Q tidak NULL
    * FS : Elemen yang berada di belakang elemen prec dilepas
    *      dan disimpan/ditunjuk oleh q
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    q=firstjadwal(p);
    if (q!= NULL)
    {
        while (info_jadwal(q).id_jadwal!=y)
        {
            q=next(q);
        }
        if(q == firstjadwal(p))
        {
            deletefirst_jadwal(p,q);
        }
        else if(next(q)==NULL)
        {
            deletelast_jadwal(p,q);
        }
        else
        {
            address_jadwal prec=prev(q);
            next(prec)=next(q);
            prev(next(q))=prec;
            prev(q)=NULL;
            next(q)=NULL;
        }

    }
    else
    {
        cout << "Data jadwal belum ada";
    }
}

//DELETE LAST
void deletelast_mentor (List &l, address_mentor &p)
/**
    * IS : List mentor l mungkin kosong
    * FS : Elemen terakhir di dalam List mentor l dilepas dan ditunjuk oleh p
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    address_mentor q;
    q = first(l);
    if (next(q) != NULL)
    {
        while (next(next(q)) != NULL)
            q = next(q);
        p = next(q);
        next(q) = NULL;
    }
    else
    {
        cout << "data tidak ada";
    }
}

void deletelast_jadwal (address_mentor &p, address_jadwal &q)
/**
    * IS : List jadwal mungkin kosong
    * FS : Elemen terakhir di dalam list jadwal dilepas dan disimpan/ditunjuk oleh q
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    q=lastjadwal(p);
    if(q!=NULL)
    {
        lastjadwal(p)=prev(q);
        prev(q)=NULL;
        next(lastjadwal(p))=NULL;
    }
    else
    {
        cout << "data tidak ada";
    }
}

//FINDELM
address_mentor findprec(List l, address_mentor p)
{
    /**
        * IS : List mentor l mungkin kosong
        * FS : Mengembalikan elemen dengan info.id_mentor = prec,
        */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
    address_mentor q = first(l);
    while(next(q) != NULL)
    {
        if(info_mentor(next(q)).id_mentor == info_mentor(p).id_mentor)
        {
            return q;
        }
        q = next(q);
    }
}

address_mentor findelm_mentor (List l,int x)
/**
    * IS : List mentor l mungkin kosong
    * FS : Mengembalikan elemen dengan info.id_mentor = x,
           Mengembalikan NULL jika tidak ditemukan
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    address_mentor p;
    p=first(l);
    while(p!=NULL)
    {
        if (info_mentor(p).id_mentor==x)
        {
            return p;
        }
        else
        {
            p=next(p);
        }
    }
}

address_jadwal findelm_jadwal (address_mentor p,int y)
/**
    * IS : List jadwal mungkin kosong
    * FS : Mengembalikan elemen dengan info.id_jadwal = x,
           Mengembalikan NULL jika tidak ditemukan
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    address_jadwal q;
    q=firstjadwal(p);
    while(q!=NULL)
    {
        if(info_jadwal(q).id_jadwal==y)
        {
            return q;
        }
        else
        {
            q=next(q);
        }
    }
}

//PRINTINFO
void printinfo_mentor (List l)
/**
    * FS : Menampilkan info seluruh elemen list mentor
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    address_mentor p;
    address_jadwal q;
    p=first(l);
    while (p!=NULL)
    {
        cout <<"ID mentor            : "<<info_mentor(p).id_mentor<<endl
             <<"Nama mentor          : "<<info_mentor(p).nama<<endl
             <<"Jenis Kelamin Mentor : "<<info_mentor(p).jenis_kelamin<<endl
             <<"Umur mentor          : "<<info_mentor(p).umur<<endl
             <<"Alamat mentor        : "<<info_mentor(p).alamat<<endl
             <<"No.HP mentor         : "<<info_mentor(p).nohp<<endl<<endl;
        p=next(p);
    }
}
void printinfo_jadwal (address_mentor &p,address_jadwal q)
/**
    * FS : Menampilkan info seluruh elemen list jadwal
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    if (firstjadwal(p)!=NULL)
    {
        q=firstjadwal(p);
        while(q!=NULL)
        {
            cout << "ID jadwal : "<< info_jadwal(q).id_jadwal<<endl
                 << "Jam Mulai : "<< info_jadwal(q).jam << endl
                 << "Hari      : "<< info_jadwal(q).hari << endl
                 << "Bulan     : "<< info_jadwal(q).bulan << endl
                 << "Tahun     : "<< info_jadwal(q).tahun << endl
                 << "Kapasitas : "<< info_jadwal(q).kapasitas << endl << endl;
            q=next(q);
        }
    }
}

//ADD
void add_mentor(mentor &x)
/**
    * FS : mengisi data elemen list mentor
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    cout <<"Nama Mentor          : ";
    cin >> x.nama;
    cout <<"Jenis Kelamin Mentor : ";
    cin >> x.jenis_kelamin;
    cout <<"Umur Mentor          : ";
    cin >> x.umur;
    cout <<"Alamat Mentor        : ";
    cin >> x.alamat;
    cout <<"No.Hp Mentor         : ";
    cin >> x.nohp;
}
void add_jadwal(jadwal &y,address_mentor &p)
/**
    * FS : mengisi data elemen list mentorld
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    cout <<"Jam       : ";
    cin >> y.jam;
    cout <<"Hari      : ";
    cin >> y.hari;
    cout <<"Bulan     : ";
    cin >> y.bulan;
    cout <<"Tahun     : ";
    cin >> y.tahun;
    cout <<"Kapasitas : ";
    cin >> y.kapasitas;
}

//REPORTING
int kapasitasbanyak (address_mentor p)
/**
    * IS : Menginputkan id mentor dari list mentor
    * FS : Menampilkan data kapasitas terbanyak dari list jadwal
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    int temp=0;
    address_jadwal q=firstjadwal(p);
    if(q!=NULL)
    {
        while (q!=NULL)
        {
            if (info_jadwal(q).kapasitas > temp)
            {
                temp=info_jadwal(q).kapasitas;
            }
            q=next(q);
        }
        return temp;
    }
    else
    {
        cout <<"anda belum menginput jadwal";
    }
}

int kapasitassedikit (address_mentor p)
/**
    * IS : Menginputkan id mentor dari list mentor
    * FS : Menampilkan data kapasitas terdikit dari list jadwal
    */
    //----------------------------------------
    //NIM : 1301154202
    //----------------------------------------
{
    int temp=999;
    address_jadwal q = firstjadwal(p);
    if(q!=NULL)
    {
        while (q!=NULL)
        {
            if (info_jadwal(q).kapasitas < temp)
            {
                temp = info_jadwal(q).kapasitas;
            }
            q = next(q);
        }
        return temp;
    }
    else
    {
        cout <<"anda belum menginput jadwal";
    }

}

int kapasitastotal (address_mentor p)
/**
    * IS : Menginputkan id mentor dari list mentor
    * FS : Menampilkan data kapasitas total dari list jadwal
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    int temp=0;
    address_jadwal q=firstjadwal(p);
    if(q!=NULL)
    {
        while (q!=NULL)
        {
            temp = temp + info_jadwal(q).kapasitas;
            q=next(q);
        }
        return temp;
    }
    else
    {
        cout <<"anda belum menginput jadwal";
    }

}

//SORTING
void SortingKapasitas (address_mentor &p)
/**
    * IS : Menginputkan id mentor dari list mentor
    * FS : Menampilkan data kapasitas terurut dari terkecil ke terbesar dari list jadwal
    */
    //----------------------------------------
    //NIM : 1301154216
    //----------------------------------------
{
    address_jadwal Q = NULL;
    while(Q != firstjadwal(p))
    {

        address_jadwal R = firstjadwal(p);
        address_jadwal N = firstjadwal(p);
        if (Q == NULL)
        {
            while(R != NULL)
            {
                cout<"B";
                if(info_jadwal(R).kapasitas < info_jadwal(N).kapasitas)
                {
                    N = R;
                }
                R = next(R);
            }
        }
        else
        {
            while(R != Q)
            {
                if(info_jadwal(R).kapasitas < info_jadwal(N).kapasitas)
                {
                    N = R;
                }
                R = next(R);
            }
        }

        address_jadwal z;
        if(prev(N) == NULL)
        {
            deletefirst_jadwal(p, N);
        }
        else if(next(N) == NULL)
        {
            deletelast_jadwal(p, N);
        }
        else
        {
            next(prev(N)) = next(N);
            prev(next(N)) = prev(N);
            next(N) = NULL;
            prev(N) = NULL;

        }
        insertlast_jadwal(p, N);
        z=N;
        if (Q == NULL)
        {
            Q = z;
        }
    }
    cout << "Hasil sorting jadwal berdasarkan kapasistas dari terkecil ke terbesar : " <<endl << endl;
    printinfo_jadwal(p,Q);
}




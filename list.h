#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

#define info_mentor(p) (p)->info_mentor
#define info_jadwal(p) (p)->info_jadwal
#define next(p) (p)->next
#define next_jadwal(p) (p)->next_jadwal
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define firstjadwal(p) (p)->firstjadwal
#define lastjadwal(p) (p)->lastjadwal
#define nil NULL

using namespace std;

typedef struct elmmentor *address_mentor;
typedef struct elmjadwal *address_jadwal;

//DEKLARASI MENTOR
struct mentor
{
    int id_mentor;
    string nama;
    string jenis_kelamin;
    string umur;
    string alamat;
    string nohp;
};

struct elmmentor
{
    mentor info_mentor;
    address_mentor next,prev;
    address_jadwal firstjadwal,lastjadwal;
};

//DEKLARASI JADWAL
struct jadwal
{
    int id_jadwal;
    int jam;
    string hari;
    string bulan;
    string tahun;
    int kapasitas;
};

struct elmjadwal
{
    jadwal info_jadwal;
    address_jadwal next,prev;
};

//LIST
struct List
{
    address_mentor first,last;
};

//DEKLARASI PROCEDURE DAN FUNCTION
void creatementor (List & );

address_mentor alokasi_mentor (mentor x);
address_jadwal alokasi_jadwal (jadwal y);

void insertfirst_mentor (List &l, address_mentor p);
void insertfirst_jadwal (address_mentor &p, address_jadwal &q);

void insertafter_mentor (List &l, address_mentor p, address_mentor prec);
void insertafter_jadwal (address_mentor &p, address_jadwal &q,int x);

void insertlast_mentor (List &l, address_mentor p);
void insertlast_jadwal (address_mentor &p, address_jadwal &q);

void deletefirst_mentor (List &l, address_mentor p);
void deletefirst_jadwal (address_mentor &p, address_jadwal &q);

void deleteafter_mentor (List &l,address_mentor prec, address_mentor &p);
void deleteafter_jadwal (address_mentor &p, address_jadwal &q,int y);

void deletelast_mentor (List &l, address_mentor &p);
void deletelast_jadwal (address_mentor &p, address_jadwal &q);

address_mentor findprec(List l, address_mentor p);
address_mentor findelm_mentor (List l,int x);
address_jadwal findelm_jadwal (address_mentor p,int y);

void printinfo_mentor (List l);
void printinfo_jadwal (address_mentor &p,address_jadwal q);

void add_mentor(mentor &x);
void add_jadwal(jadwal &y,address_mentor &p );

int kapasitasbanyak (address_mentor p);
int kapasitassedikit (address_mentor p);
int kapasitastotal (address_mentor p);

void SortingKapasitas (address_mentor &p);
#endif // LIST_H_INCLUDED

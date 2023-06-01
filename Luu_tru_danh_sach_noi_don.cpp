#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

typedef struct vdv{
    string name;
    string clb;
    int tuoi;
    int sohuychuong;
}vdv;

struct node{
    vdv vandongvien;
    node* next;
};

typedef node* ptr_node;

void display_title(){
    cout<<setw(20)<<"Ho va ten";
    cout<<setw(15)<<"CLB";
    cout<<setw(10)<<"Tuoi";
    cout<<setw(20)<<"So huy chuong"<<"\n";
}
void create(vdv& element){
    cout<<"Ho va ten: ";    cin>>element.name;
    cout<<"Cau lac bo: ";   cin>>element.clb;
    cout<<"Tuoi: "; cin>>element.tuoi;
    cout<<"So huy chuong: ";    cin>>element.sohuychuong;
}

bool Is_empty(ptr_node P){
    if(P == NULL)   return 1;
    return 0;
}

void display_vdv(vdv element){
    cout<<setw(20)<<element.name<<setw(15)<<element.clb<<setw(10)<<element.tuoi<<setw(20)<<element.sohuychuong<<"\n";
}

void add(ptr_node& P, vdv element){
    ptr_node a, b;
    a = new node();
    b = new node();
    a->vandongvien = element;
    if(Is_empty(P))
        P = a;
    else{
        b = P;
        while(b->next != NULL)
            b = b->next;
        b->next = a;
    }
}

void input(ptr_node& P){
    ptr_node a,b;
    vdv element;
    char c;
    do{
    a = new node();
    create(element);
    a->vandongvien = element;
    if(Is_empty(P))
        P = a;
    else{
        b->next = a;
    }
    b = a;
    cout<<"Ban co muon nhap them khong (c/k): ";
    fflush(stdin);
    c = getchar();
    }while(c == 'c');
}

void display_data(ptr_node P){
    display_title();
    while(P != NULL){
        display_vdv(P->vandongvien);
        P = P->next;
    }
}

main(){
    ptr_node P = nullptr;
    vdv a;
    input(P);
    display_data(P);
    create(a);
    add(P,a);
    display_data(P);
}

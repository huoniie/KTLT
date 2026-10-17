#include <bits/stdc++.h>
using namespace std;

class SinhVien {
	int msv;
	char name[30];
	float gpa;
	public:
		void nhap(){
			for ( int i=0 ; i<5 ; i++ ){
				cout<<"Sinh vien" <<i+1;
				cout<<"\nNhap MSV: ";
				 cin >>msv ;
				
				getchar();
				cout<<"Nhap ten: ";
				cin>>name ;
				
				cout<<"Nhap gpa: ";
				cin >>gpa;
			}
		}
};

int main(){
	SinhVien sv;
	sv.nhap();
}

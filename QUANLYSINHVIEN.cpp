#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

struct Date {
	int day, month, year;
};
struct sv {
	string MSSV, tenSV;
	float Diem;
	Date ngaySinh;
};

list <sv> dsSinhVien;

Date XuLiNgaySinh(Date& x) {
	cout << "	+Nam sinh: ";
	cin >> x.year;
	do {	//nhập tháng
		cout << "	+Thang sinh: ";
		cin >> x.month;
	} while (x.month < 0 || x.month>12);	//buộc người dùng phải nhập tháng từ 1-12
	bool kTra;	//hàm kiểm tra này sẽ kiểm tra xem năm nhập vô là năm nhuận hay năm ko nhuận
	if ((x.year % 4 == 0 && x.year % 100 != 0) || (x.year % 400 == 0)) {
		kTra = true;	//nếu nhuận trả về true
	}
	else
	{
		kTra = false;	//còn ko nhuận trả về false
	}
	switch (x.month)	//sử dụng switch case để ràng buộc nhập đúng số ngày từ các tháng nhập vô
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12 :	//nhập ngày cho các tháng có 31 ngày
			do {
				cout << "	+Ngay sinh: ";
				cin >> x.day;
			} while (x.day < 1 || x.day>31);	//buộc người dùng phải nhập ngày từ 1-31
		break;
		case 4: case 6: case 9: case 11:	//nhập ngày cho các tháng có 30 ngày
			do {
				cout << "	+Ngay sinh: ";
				cin >> x.day;
			} while (x.day < 1 || x.day>30);	//buộc người dùng phải nhập ngày từ 30
			break;
		case 2:
			if (kTra == true)	
			{
				x.day = 29;	//Năm nhuận tháng 2 có 29 ngày
			}
			else	
			{
				x.day = 28;	//Năm không nhuận tháng 2 có 28 ngày
			}
			cout << "Ngay sinh: " << x.day << endl;
			break;
	}
	return x;
}
void InDate(Date x) {
	cout << x.day << "/" << x.month << "/" << x.year;
}
string XuLiTen(sv& sv) {
	stringstream ss(sv.tenSV);	//cắt tên sinh viên thành từng "từ" riêng lẻ
	string word;	//tạo ra 1 string để hứng các "từ" của tên sinh viên được cắt ra
	vector<string> a;	//tạo 1 vector a
	while (ss >> word)
	{
		a.push_back(word);	//gán từng "từ" từ tên sinh viên vào string word ban nảy tạo
	}
	for (int i = 0; i < a.size(); i++)	//Dùng hàm for để duyệt từng từ trong vector a chứa tên sinh viên
	{
		a[i][0] = toupper(a[i][0]);	//lúc này i = 0 có nghĩa nếu tên nhập vô là "le hoang luan" thì a[i] = le và a[i][0] = l và sẽ in hoa chữ l lên
		for (int j = 1; j < a.size(); j++)
		{
			a[i][j] = tolower(a[i][j]);	//các chữ còn lại viết thường
		}
	}
	sv.tenSV = "";	//khởi tạo lại tên sinh viên là 1 chuỗi rỗng để lưu lại tên mới đã qua xử lí
	for (int i = 0; i < a.size(); i++)
	{
		if (i > 0) sv.tenSV += " ";	//thêm dấu cách vào từ chữ thứ 1 trở đi
		sv.tenSV += a[i];	//gán từng chữ trong vector a vào tên sinh viên;
	}
	return sv.tenSV;	//trả về tên sinh viên
}
sv NhapSV() {
	sv sv;	//tạo ra 1 sinh viên mới
	cout << "MSSV: ";
	cin.ignore();
	getline(cin, sv.MSSV);	//nhập mssv
	cout << "Ten sinh vien: ";
	getline(cin, sv.tenSV);	//nhập tên sinh viên
	cout << "Nhap ngay sinh sinh vien:" << endl;
	sv.ngaySinh = XuLiNgaySinh(sv.ngaySinh);	//nhập năm sinh
	cout << "Diem: ";
	cin >> sv.Diem;	//nhập điểm
	sv.tenSV = XuLiTen(sv); //gọi hàm xử lí tên gán ngược về tên sv
	return sv;	//trả về dữ liệu của sinh viên
}
void InSinhVien(sv x) {
	cout << "Mssv: " << x.MSSV;
	cout << " - Ten sinh vien: " << x.tenSV << " - Ngay sinh: ";
	InDate(x.ngaySinh);
	cout << " - Diem: " << x.Diem << endl;
}

int main()
{
	int chon, count = 1 ;
	cout << "\t\tCHUONG TRINH QUAN LY SINH VIEN";
	cout << "\n1. Them vao sinh vien moi";
	cout << "\n2. In ra thong tin sinh vien";
	cout << "\n3. Xoa sinh vien";
	cout << "\n4. Sua sinh vien";
	cout << "\n5. In ra toan bo danh sach sinh vien";
	cout << "\n6.Thoat";
	do {
		cout << "\nHay nhap tuy chon cua ban: ";
		cin >> chon;
		sv sv;
		string s = " ";
		switch (chon)
		{
		case 1: //nhập thông tin sinh viên mới
			cout << "\nNhap thong tin sinh vien thu " << count << endl;
			dsSinhVien.push_back(NhapSV());
			count++;
			break;
		case 2: //truy vấn sinh viên
			cin.ignore();
			cout << "Nhap mssv can tim:";
			getline(cin, s);			
			for (auto x : dsSinhVien) {
				if (x.MSSV == s) {
					InSinhVien(x);
				}
			}
			break;
		case 3: // xoá sinh viên

			break;
		case 4: // sửa thông tin sinh viên
				
			break;
		case 5: // in ra nguyên danh sách
			for (auto x : dsSinhVien) {
				InSinhVien(x);
			}
			break;
		case 6:
			break;
		}
	} while (chon > 0 && chon < 6);
	return 0;
}
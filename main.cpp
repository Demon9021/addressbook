#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
void Showall();
void Showbirth();
void Tellbirth();
using namespace std;
class adressbook
{
public:
virtual void Initial(const char *)=0;
virtual void Entry(const char*)=0;
virtual void Inquire(const char*)=0;
virtual void Change(const char*)=0;
virtual void Delete(const char*)=0;
};
class students:  public adressbook
{
public:
 void Initial(const char *fileDat);	
 void Entry(const char*fileDat);
 void Inquire(const char*fileDat);
 void Change(const char*fileDat);
 void Delete(const char*fileDat);
};
struct student
{
	string name;
	string birthdate;
	string month;
    string number;
	string email;
	string schoolname;
};
const char*fileDat="d:\\studentsfile.dat";
const student mark={"noname\0","nobirthdate\0","nomonth\0","nonumber\0","noemail\0","noschoolname\0"};
void students ::Initial(const char *fileDat)
{
cout<<"若同学通讯录文件存在，将删除原有数据，要进行文件初始化吗？（Y/N)\n";
char answer;
cin>>answer;
if(answer=='Y'||answer=='y')
{
	fstream fdat(fileDat,ios::out|ios::binary);
	fdat.seekp(0,ios::beg);
fdat.write((char*)&mark,sizeof(student));
system("cls");
cout<<"同学文件已初始化\n";
fdat.close();
}
else if(answer=='N'||answer=='n') 
	{
		system("cls");
		cout<<"取消操作\n";
		return;
}
}
 int endMark(student book)
 {
	 if( book.name=="noname\0")
		 return 1;
	 else return 0;
 }
 void students :: Entry(const char*fileDat)
 {
	 student book;
	 char choice;
	 {
	 fstream fdat(fileDat,ios::in|ios::out|ios::binary);
	 if(!fdat)
	 {    
		  system("cls");
		 cout<<"同学通讯录文件不存在，请进行初始化操作\n";
		 fdat.close();
	 return;
	 }
	 }
	  system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t**************************录入信息****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:录入\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
fstream fdat(fileDat,ios::in|ios::out|ios::binary);
	 fdat.seekg(0,ios::beg);
	 do
	 {
		 fdat.read((char*)&book,sizeof(student));
	 }
	 while(!endMark(book));
	 fdat.seekp(-long(sizeof(student)),ios::cur);
	 cout<<"请输入相关信息：\n";
	 cout<<"姓名："<<endl;
	 cin>>book.name;
     do
	 {
		 cout<<"请输入正确的生日格式：（年.月.日）"<<endl;
		  cin>>book.birthdate;
	 }
		 while((book.birthdate.find(".")!=4)&&(book.birthdate.find(".",5)!=7));
		 cout<<"请再次确认出生月份（Jan.Feb.Mar.Apr.May.Jun.Jul.Aug.sep.Oct.Nov.Dec)"<<endl;
		 cin>>book.month;
	 cout<<"电话："<<endl;
	 cin>>book.number;
	 cout<<"邮箱："<<endl;
	 cin>>book.email;
	 cout<<"学校："<<endl;
	 cin>>book.schoolname;
	 fdat.write((char*)&book,sizeof(student));
	 fdat.write((char*)&mark,sizeof(student));
	 cout<<"录入成功"<<endl;
	 fdat.close();
	 break;
	 }; 
		 case '2':
			 {
				 system("cls");
		return ;
			 };
		 }
	 }
 }
void students:: Inquire(const char*fileDat)
{
	student book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************查询*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:按姓名查询\t"<<"2：浏览\t"<<"3:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat,ios::in|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(student));
				 }
				 while(book.name!=key&&!endMark(book));
				 if(book.name==key)
					 {
						 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"学校\t"<<endl;
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.schoolname<<'\n';
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			 {
				 fstream fdat(fileDat,ios::in|ios::binary);
				 if(!fdat)
				 {
					 cout<<"学生文件不存在，请进行初始化操作\n";
					 fdat.close();
					 return;
				 }
				 else
				 {
				string min[50][5];
				 int t;
				 int x=0;
				 string a[50][5];
				 fdat.seekg(0,ios::beg);
				 for(int i=0;!endMark(book);i++)
				 {
					 fdat.read((char*)&book,sizeof(student));
					 if(!endMark(book))
					 {
					 a[i][0]=book.name;
					 a[i][1]=book.birthdate;
					 a[i][2]=book.number;
					 a[i][3]=book.email;
					 a[i][4]=book.schoolname;
					 x++;
				 }
				 }
				 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"学校\t"<<endl;
				 for(int i=0;i<x-1;i++)
				 {
					 t=i;
					 for(int j=i+1;j<x;j++)
					 {
						 if(a[j][0]<a[t][0])
					t=j;
						 if(t!=i)
						 {
							 min[i][0]=a[i][0];
							  min[i][1]=a[i][1];
							   min[i][2]=a[i][2];
							    min[i][3]=a[i][3];
								 min[i][4]=a[i][4];
							 a[i][0]=a[t][0];
							  a[i][1]=a[t][1];
							   a[i][2]=a[t][2];
							    a[i][3]=a[t][3];
								 a[i][4]=a[t][4];
						     a[t][0]=min[i][0];
							  a[t][1]=min[i][1];
							   a[t][2]=min[i][2];
							    a[t][3]=min[i][3];
								 a[t][4]=min[i][4];
						 }
					 }
				 }
 for(int i=0;i<x;i++)
				 {	
cout<<a[i][0]<<'\t'<<a[i][1]<<'\t'<<a[i][2]<<'\t'<<a[i][3]<<'\t'<<a[i][4]<<'\n';
				 }
			 
				  fdat.close();
				  break;
				 }
			 };
		 case'3':
			 
			{  
				system("cls");
			return;
			};
		 }
	 }
}
void students::Change(const char*fileDat)
{
	fstream fdat(fileDat,ios::in|ios::out|ios::binary);
	student book;
	char choice;
	string key;
	system("cls");
 cout<<"\n\t**************************************************************\n";
 cout<<"\n\n\t*****************************修改*****************************\n";
 cout<<"\n\t**************************************************************\n";
 while(1)
{
	cout<<"请输入操作选择\n"<<"1:修改\t"<<"2:退出\n";
	cin>>choice;
	switch(choice)
		case'1':
			 {
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(student));
				 }
				 while(book.name!=key&&!endMark(book));
				 if(book.name==key)
				 {
					 
					 char choice;
					 cout<<"请选择修改项\n"<<"a:电话\t"<<"b:邮箱\t"<<"c:学校\t"<<"d:退出\n";
					 cin>>choice;
					 switch(choice)
					 {
		case'a':{
			cout<<"请输入要修改的电话号码：\n";
			cin>>book.number;
			fdat.seekp(-long(sizeof(student)),ios::cur);
			fdat.write((char*)&book,sizeof(student));
			cout<<"修改成功"<<endl;
			break;
				};
		case'b':{
			cout<<"请输入要修改的邮箱地址：\n";
			cin>>book.email;
			fdat.seekp(-long(sizeof(student)),ios::cur);
			fdat.write((char*)&book,sizeof(student));
			cout<<"修改成功"<<endl;
			break;
				};
		case'c':{
			cout<<"请输入要修改的学校名称：\n";
			cin>>book.schoolname;
			fdat.seekp(-long(sizeof(student)),ios::cur);
			fdat.write((char*)&book,sizeof(student));
			cout<<"修改成功"<<endl;
			break;
				};
		case'd':{
			fdat.close();
			system("cls");
			return;
				};
				 }
				 }
				 else
					 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 };
		case'2':
			{
				fdat.close();
			system("cls");
			return;
			};
			 }
}
}
void students::Delete(const char*fileDat)
{student book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************删除*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:删除\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat,ios::in|ios::out|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(student));
				 }
				 while(book.name!=key&&!endMark(book));
				 if(book.name==key)
					 {
						 string a[50][5];
						 int i=0;
						 fdat.seekp(-long(sizeof(student)),ios::cur);
						book.name="\0";
								book.birthdate="\0";
									book.number="\0";
										book.email="\0";
										book.schoolname="\0";
				fdat.write((char*)&book,sizeof(student));
				fdat.seekg(0,ios::beg);
				for(;!endMark(book);)
				{
					fdat.read((char*)&book,sizeof(student));
					if(book.name!="\0")
					{
                          a[i][0]=book.name;
						  a[i][1]=book.birthdate;
						  a[i][2]=book.number;
						  a[i][3]=book.email;
						  a[i][4]=book.schoolname;
						  i++;
					}
					else
						continue;
				}
				fdat.seekp(0,ios::beg);
				fdat.write((char*)&mark,sizeof(student));
				fdat.seekp(0,ios::beg);
				for(int k=0;k<i;k++)
				{
					book.name=a[k][0];
					book.birthdate=a[k][1];
					book.number=a[k][2];
					book.email=a[k][3];
					book.schoolname=a[k][4];
					fdat.write((char*)&book,sizeof(student));
				}
fdat.write((char*)&mark,sizeof(student));
	 cout<<"删除成功！"<<endl;
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			{ 
				system("cls");
			return;
			};
		 }
	 }
}
class mates:  public adressbook
{
public:
 void Initial(const char *fileDat1);	
 void Entry(const char*fileDat1);
 void Inquire(const char*fileDat1);
 void Change(const char*fileDat1);
 void Delete(const char*fileDat1);
};
struct mate
{
	string name;
	string birthdate;
	string month;
    string number;
	string email;
	string companyname;
};
const char*fileDat1="d:\\matesfile.dat";
const mate mark1={"noname\0","nobirthdate\0","nomonth\0","nonumber\0","noemail\0","nocompanyname\0"};
void mates ::Initial(const char *fileDat1)
{
cout<<"若同事通讯录文件存在，将删除原有数据，要进行文件初始化吗？（Y/N)\n";
char answer;
cin>>answer;
if(answer=='Y'||answer=='y')
{
	fstream fdat(fileDat1,ios::out|ios::binary);
	fdat.seekp(0,ios::beg);
fdat.write((char*)&mark1,sizeof(mate));
system("cls");
cout<<"同事文件已初始化\n";
fdat.close();
}
else if(answer=='N'||answer=='n') 
	{
		system("cls");
		cout<<"取消操作\n";
		return;
}
}
 int endMark1(mate book)
 {
	 if( book.name=="noname\0")
		 return 1;
	 else return 0;
 }
 void mates :: Entry(const char*fileDat1)
 {
	 mate book;
	 char choice;
	 {
	 fstream fdat(fileDat1,ios::in|ios::out|ios::binary);
	 if(!fdat)
	 {    
		  system("cls");
		 cout<<"同事通讯录文件不存在，请进行初始化操作\n";
		 fdat.close();
	 return;
	 }
	 }
	  system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t**************************录入信息****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:录入\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
fstream fdat(fileDat1,ios::in|ios::out|ios::binary);
	 fdat.seekg(0,ios::beg);
	 do
	 {
		 fdat.read((char*)&book,sizeof(mate));
	 }
	 while(!endMark1(book));
	 fdat.seekp(-long(sizeof(mate)),ios::cur);		
	 cout<<"请输入相关信息：\n";
	 cout<<"姓名："<<endl;
	 cin>>book.name;
 do
	 {
		 cout<<"请输入正确的生日格式：（年.月.日）"<<endl;
		  cin>>book.birthdate;
	 }
		 while((book.birthdate.find(".")!=4)&&(book.birthdate.find(".",5)!=7));
		  cout<<"请再次确认出生月份（Jan.Feb.Mar.Apr.May.Jun.Jul.Aug.sep.Oct.Nov.Dec)"<<endl;
		 cin>>book.month;
	 cout<<"电话："<<endl;
	 cin>>book.number;
	 cout<<"邮箱："<<endl;
	 cin>>book.email;
	 cout<<"公司："<<endl;
	 cin>>book.companyname;
	 fdat.write((char*)&book,sizeof(mate));
	 fdat.write((char*)&mark1,sizeof(mate));
	 cout<<"录入成功"<<endl;
	 fdat.close();
	 break;
	 }; 
		 case '2':
			 { 
				 system("cls");
		return ;
			 };
		 }
	 }
 }
void mates:: Inquire(const char*fileDat1)
{
	mate book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************查询*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:按姓名查询\t"<<"2：浏览\t"<<"3:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat1,ios::in|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(mate));
				 }
				 while(book.name!=key&&!endMark1(book));
				 if(book.name==key)
					 {
						 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"公司\t"<<endl;
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.companyname<<'\n';
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			 {
				 fstream fdat(fileDat1,ios::in|ios::binary);
				 if(!fdat)
				 {
					 cout<<"同事文件不存在，请进行初始化操作\n";
					 fdat.close();
					 return;
				 }
				 else
				 {
				string min[50][5];
				 int t;
				 int x=0;
				 string a[50][5];
				 fdat.seekg(0,ios::beg);
				 for(int i=0;!endMark1(book);i++)
				 {
					 fdat.read((char*)&book,sizeof(mate));
					 if(!endMark1(book))
					 {
					 a[i][0]=book.name;
					 a[i][1]=book.birthdate;
					 a[i][2]=book.number;
					 a[i][3]=book.email;
					 a[i][4]=book.companyname;
					 x++;
				 }
				 }
				 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"公司\t"<<endl;
				 for(int i=0;i<x-1;i++)
				 {
					 t=i;
					 for(int j=i+1;j<x;j++)
					 {
						 if(a[j][0]<a[t][0])
					t=j;
						 if(t!=i)
						 {
							 min[i][0]=a[i][0];
							  min[i][1]=a[i][1];
							   min[i][2]=a[i][2];
							    min[i][3]=a[i][3];
								 min[i][4]=a[i][4];
							 a[i][0]=a[t][0];
							  a[i][1]=a[t][1];
							   a[i][2]=a[t][2];
							    a[i][3]=a[t][3];
								 a[i][4]=a[t][4];
						     a[t][0]=min[i][0];
							  a[t][1]=min[i][1];
							   a[t][2]=min[i][2];
							    a[t][3]=min[i][3];
								 a[t][4]=min[i][4];
						 }
					 }
				 }
				 
 for(int i=0;i<x;i++)
				 {	
					
cout<<a[i][0]<<'\t'<<a[i][1]<<'\t'<<a[i][2]<<'\t'<<a[i][3]<<'\t'<<a[i][4]<<'\n';
				 }
			 
				  fdat.close();
				  break;}
			 
			 };
		 case'3':
			{ 
				system("cls");
			return;
			};
		 }
	 }
}

void mates::Change(const char*fileDat1)
{
	fstream fdat(fileDat1,ios::in|ios::out|ios::binary);
	mate book;
	char choice;
	string key;
	system("cls");
 cout<<"\n\t**************************************************************\n";
 cout<<"\n\n\t*****************************修改*****************************\n";
 cout<<"\n\t**************************************************************\n";
 while(1)
{
	cout<<"请输入操作选择\n"<<"1:修改\t"<<"2:退出\n";
	cin>>choice;
	switch(choice)
		case'1':
			 {
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(mate));
				 }
				 while(book.name!=key&&!endMark1(book));
				 if(book.name==key)
				 {
					 char choice;
					 cout<<"请选择修改项\n"<<"a:电话\t"<<"b:邮箱\t"<<"c:公司\t"<<"d:退出\n";
					 cin>>choice;
					 switch(choice)
					 {
		case'a':{
			cout<<"请输入要修改的电话号码：\n";
			cin>>book.number;
			fdat.seekp(-long(sizeof(mate)),ios::cur);
			fdat.write((char*)&book,sizeof(mate));
			cout<<"修改成功"<<endl;
			break;
				};
		case'b':{
			cout<<"请输入要修改的邮箱地址：\n";
			cin>>book.email;
			fdat.seekp(-long(sizeof(mate)),ios::cur);
			fdat.write((char*)&book,sizeof(mate));
			cout<<"修改成功"<<endl;
			break;
				};
		case'c':{
			cout<<"请输入要修改的公司名称：\n";
			cin>>book.companyname;
			fdat.seekp(-long(sizeof(mate)),ios::cur);
			fdat.write((char*)&book,sizeof(mate));
			cout<<"修改成功"<<endl;
			break;
				};
		case'd':{
			fdat.close();
			system("cls");
			return;
				};
				 }
				 }
				 else				 	
					 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }; 
		case'2':
			{
				fdat.close();
			system("cls");
			return;
			};			 
			 }
}
}
void mates::Delete(const char*fileDat1)
{mate book;
	 char choice;
	string key;	 
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************删除*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:删除\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat,ios::in|ios::out|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(mate));
				 }
				 while(book.name!=key&&!endMark1(book));
				 if(book.name==key)
					 {
						 string a[50][5];
						 int i=0;
						 fdat.seekp(-long(sizeof(mate)),ios::cur);
						book.name="\0";
								book.birthdate="\0";
									book.number="\0";
										book.email="\0";
										book.companyname="\0";
				fdat.write((char*)&book,sizeof(mate));
				fdat.seekg(0,ios::beg);
				for(;!endMark1(book);)
				{
					fdat.read((char*)&book,sizeof(mate));
					if(book.name!="\0")
					{
                          a[i][0]=book.name;
						  a[i][1]=book.birthdate;
						  a[i][2]=book.number;
						  a[i][3]=book.email;
						  a[i][4]=book.companyname;
						  i++;
					}
					else
						continue;
				}
				fdat.seekp(0,ios::beg);
				fdat.write((char*)&mark,sizeof(mate));
				fdat.seekp(0,ios::beg);
				for(int k=0;k<i;k++)
				{
					book.name=a[k][0];
					book.birthdate=a[k][1];
					book.number=a[k][2];
					book.email=a[k][3];
					book.companyname=a[k][4];
					fdat.write((char*)&book,sizeof(mate));
				}
fdat.write((char*)&mark,sizeof(mate));
	 cout<<"删除成功！"<<endl;
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };		
		 case'2': 
			{  system("cls");
			return;};
		 }
	 }
}
class partners:  public adressbook
{
public:
 void Initial(const char *fileDat);	
 void Entry(const char*fileDat);
 void Inquire(const char*fileDat);
 void Change(const char*fileDat);
 void Delete(const char*fileDat);
};
struct partner
{
	string name;
	string birthdate;
	string month;
    string number;
	string email;
	string placename;
};
const char*fileDat2="d:\\partnersfile.dat";
const partner mark2={"noname\0","nobirthdate\0","nomonth","nonumber\0","noemail\0","noplacename\0"};
void partners ::Initial(const char *fileDat2)
{
cout<<"若朋友通讯录文件存在，将删除原有数据，要进行文件初始化吗？（Y/N)\n";
char answer;
cin>>answer;
if(answer=='Y'||answer=='y')
{
	fstream fdat(fileDat2,ios::out|ios::binary);
	fdat.seekp(0,ios::beg);
fdat.write((char*)&mark2,sizeof(partner));
system("cls");
cout<<"朋友文件已初始化\n";
fdat.close();
}
else if(answer=='N'||answer=='n') 
	{
		system("cls");
		cout<<"取消操作\n";
		return;
}
}
 int endMark2(partner book)
 {
	 if( book.name=="noname\0")
		 return 1;
	 else return 0;
 }
 void partners:: Entry(const char*fileDat2)
 {
	 partner book;
	 char choice;
	 {
	 fstream fdat(fileDat2,ios::in|ios::out|ios::binary);
	 if(!fdat)
	 {    
		  system("cls");
		 cout<<"朋友通讯录文件不存在，请进行初始化操作\n";
		 fdat.close();
	 return;
	 }
	 }
	  system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t**************************录入信息****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:录入\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
fstream fdat(fileDat2,ios::in|ios::out|ios::binary);
	 fdat.seekg(0,ios::beg);
	 do
	 {
		 fdat.read((char*)&book,sizeof(partner));
	 }
	 while(!endMark2(book));
	 fdat.seekp(-long(sizeof(partner)),ios::cur);
	 cout<<"请输入相关信息：\n";
	 cout<<"姓名："<<endl;
	 cin>>book.name;
     do
	 {
		 cout<<"请输入正确的生日格式：（年.月.日）"<<endl;
		  cin>>book.birthdate;
	 }
		 while((book.birthdate.find(".")!=4)&&(book.birthdate.find(".",5)!=7));
		  cout<<"请再次确认出生月份（Jan.Feb.Mar.Apr.May.Jun.Jul.Aug.sep.Oct.Nov.Dec)"<<endl;
		 cin>>book.month;
	 cout<<"电话："<<endl;
	 cin>>book.number;
	 cout<<"邮箱："<<endl;
	 cin>>book.email;
	 cout<<"认识地点："<<endl;
	 cin>>book.placename;
	 fdat.write((char*)&book,sizeof(partner));
	 fdat.write((char*)&mark2,sizeof(partner));
	 cout<<"录入成功"<<endl;
	 fdat.close();
	 break;
	 }; 
		 case '2':
			 {
				 system("cls");
		return ;
			 };
		 }
	 }
 }
void partners:: Inquire(const char*fileDat2)
{
	partner book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************查询*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:按姓名查询\t"<<"2：浏览\t"<<"3:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat2,ios::in|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(partner));
				 }
				 while(book.name!=key&&!endMark2(book));
				 if(book.name==key)
					 {
						 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"认识地点\t"<<endl;
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.placename<<'\n';	
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			 {
				 fstream fdat(fileDat2,ios::in|ios::binary);
				 if(!fdat)
				 {
					 cout<<"朋友文件不存在，请进行初始化操作\n";
					 fdat.close();
					 return;
				 }
				 else
				 {
				string min[50][5];
				 int t;
				 int x=0;
				 string a[50][5];
				 fdat.seekg(0,ios::beg);
				 for(int i=0;!endMark2(book);i++)
				 {
					 fdat.read((char*)&book,sizeof(partner));
					 if(!endMark2(book))
					 {
					 a[i][0]=book.name;
					 a[i][1]=book.birthdate;
					 a[i][2]=book.number;
					 a[i][3]=book.email;
					 a[i][4]=book.placename;
					 x++;
				 }
				 }
				 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"地点\t"<<endl;
				 for(int i=0;i<x-1;i++)
				 {
					 t=i;
					 for(int j=i+1;j<x;j++)
					 {
						 if(a[j][0]<a[t][0])
					t=j;
						 if(t!=i)
						 {
							 min[i][0]=a[i][0];
							  min[i][1]=a[i][1];
							   min[i][2]=a[i][2];
							    min[i][3]=a[i][3];
								 min[i][4]=a[i][4];
							 a[i][0]=a[t][0];
							  a[i][1]=a[t][1];
							   a[i][2]=a[t][2];
							    a[i][3]=a[t][3];
								 a[i][4]=a[t][4];
						     a[t][0]=min[i][0];
							  a[t][1]=min[i][1];
							   a[t][2]=min[i][2];
							    a[t][3]=min[i][3];
								 a[t][4]=min[i][4];
						 }
					 }
				 }
 for(int i=0;i<x;i++)
				 {	
					
cout<<a[i][0]<<'\t'<<a[i][1]<<'\t'<<a[i][2]<<'\t'<<a[i][3]<<'\t'<<a[i][4]<<'\n';
				 }
			 
				  fdat.close();
				  break;}
			 };
		 case'3':
			{  
				system("cls");
			return;
			};
		 }
	 }	
}
void partners::Change(const char*fileDat2)
{
	fstream fdat(fileDat2,ios::in|ios::out|ios::binary);
	partner book;
	char choice;
	string key;
	system("cls");
 cout<<"\n\t**************************************************************\n";
 cout<<"\n\n\t*****************************修改*****************************\n";
 cout<<"\n\t**************************************************************\n";
 while(1)
{
	cout<<"请输入操作选择\n"<<"1:修改\t"<<"2:退出\n";
	cin>>choice;
	switch(choice)
		case'1':
			 {			
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(partner));
				 }
				 while(book.name!=key&&!endMark2(book));
				 if(book.name==key)
				 {
					 
					 char choice;
					 cout<<"请选择修改项\n"<<"a:电话\t"<<"b:邮箱\t"<<"c:学校\t"<<"d:退出\n";
					 cin>>choice;
					 switch(choice)
					 {
		case'a':{
			cout<<"请输入要修改的电话号码：\n";
		
			cin>>book.number;
			fdat.seekp(-long(sizeof(partner)),ios::cur);
			fdat.write((char*)&book,sizeof(partner));
			cout<<"修改成功"<<endl;
			break;
				};
		case'b':{
			cout<<"请输入要修改的邮箱地址：\n";
			cin>>book.email;
			fdat.seekp(-long(sizeof(partner)),ios::cur);
			fdat.write((char*)&book,sizeof(partner));
			cout<<"修改成功"<<endl;
			break;
				};
		case'c':{
			cout<<"请输入要修改的地点名称：\n";
			cin>>book.placename;
			fdat.seekp(-long(sizeof(partner)),ios::cur);
			fdat.write((char*)&book,sizeof(partner));
			cout<<"修改成功"<<endl;
			break;
				};
		case'd':{fdat.close();
			system("cls");
			return;
				};
				 }
				 }
				 else	
					 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 };
		case'2':
			{
				fdat.close();
			system("cls");
			return;
			};	 
			 }
}
}
void partners::Delete(const char*fileDat2)
{
	partner book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************删除*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:删除\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				  fstream fdat(fileDat,ios::in|ios::out|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(partner));
				 }
				 while(book.name!=key&&!endMark2(book));
				 if(book.name==key)
					 {
						 string a[50][5];
						 int i=0;
						 fdat.seekp(-long(sizeof(partner)),ios::cur);
						book.name="\0";
								book.birthdate="\0";
									book.number="\0";
										book.email="\0";
										book.placename="\0";
				fdat.write((char*)&book,sizeof(partner));
				fdat.seekg(0,ios::beg);
				for(;!endMark2(book);)
				{
					fdat.read((char*)&book,sizeof(partner));
					if(book.name!="\0")
					{
                          a[i][0]=book.name;
						  a[i][1]=book.birthdate;
						  a[i][2]=book.number;
						  a[i][3]=book.email;
						  a[i][4]=book.placename;
						  i++;
					}
					else
						continue;
				}
				fdat.seekp(0,ios::beg);
				fdat.write((char*)&mark,sizeof(partner));
				fdat.seekp(0,ios::beg);
				for(int k=0;k<i;k++)
				{
					book.name=a[k][0];
					book.birthdate=a[k][1];
					book.number=a[k][2];
					book.email=a[k][3];
					book.placename=a[k][4];
					fdat.write((char*)&book,sizeof(partner));
				}
fdat.write((char*)&mark,sizeof(partner));
	 cout<<"删除成功！"<<endl;
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2': 
			{  
				system("cls");
			return;
			};
		 }
	 }	
}
class relatives:  public adressbook
{
public:
 void Initial(const char *fileDat3);	
 void Entry(const char*fileDat3);
 void Inquire(const char*fileDat3);
 void Change(const char*fileDat3);
 void Delete(const char*fileDat3);
};
struct relative
{
	string name;
	string birthdate;
	string month;
    string number;
	string email;
	string callname;
};
const char*fileDat3="d:\\relativesfile.dat";
const relative mark3={"noname\0","nobirthdate\0","nomonth\0","nonumber\0","noemail\0","nocallname\0"};
void relatives ::Initial(const char *fileDat3)
{
cout<<"若亲戚通讯录文件存在，将删除原有数据，要进行文件初始化吗？（Y/N)\n";
char answer;
cin>>answer;
if(answer=='Y'||answer=='y')
{
	fstream fdat(fileDat3,ios::out|ios::binary);
	fdat.seekp(0,ios::beg);
fdat.write((char*)&mark,sizeof(relative));
system("cls");
cout<<"亲戚文件已初始化\n";
fdat.close();
}
else if(answer=='N'||answer=='n') 
	{
		system("cls");
		cout<<"取消操作\n";
		return;
}
}
 int endMark3(relative book)
 {
	 if( book.name=="noname\0")
		 return 1;
	 else return 0;
 }
 void relatives:: Entry(const char*fileDat3)
 {
	 relative book;
	 char choice;
	 {
	 fstream fdat(fileDat3,ios::in|ios::out|ios::binary);
	 if(!fdat)
	 {    
		  system("cls");
		 cout<<"亲戚通讯录文件不存在，请进行初始化操作\n";
		 fdat.close();
	 return;
	 }
	 }
	  system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t**************************录入信息****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:录入\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
fstream fdat(fileDat3,ios::in|ios::out|ios::binary);
	 fdat.seekg(0,ios::beg);
	 do
	 {
		 fdat.read((char*)&book,sizeof(relative));
	 }
	 while(!endMark3(book));
	 fdat.seekp(-long(sizeof(relative)),ios::cur);
	
	
	 cout<<"请输入相关信息：\n";
	 cout<<"姓名："<<endl;
	 cin>>book.name;
     do
	 {
		 cout<<"请输入正确的生日格式：（年.月.日）"<<endl;
		  cin>>book.birthdate;
	 }
		 while((book.birthdate.find(".")!=4)&&(book.birthdate.find(".",5)!=7));
		  cout<<"请再次确认出生月份（Jan.Feb.Mar.Apr.May.Jun.Jul.Aug.sep.Oct.Nov.Dec)"<<endl;
		 cin>>book.month;
	 cout<<"电话："<<endl;
	 cin>>book.number;
	 cout<<"邮箱："<<endl;
	 cin>>book.email;
	 cout<<"称呼："<<endl;
	 cin>>book.callname;
	 fdat.write((char*)&book,sizeof(relative));
	 fdat.write((char*)&mark3,sizeof(relative));
	 cout<<"录入成功"<<endl;
	 fdat.close();
	 break;
	 }; 
		 case '2':
			 { 
				 system("cls");
		return ;
			 };
		 }
	 }
 }
void relatives:: Inquire(const char*fileDat3)
{
	relative book;
	 char choice;
	string key; 
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************查询*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:按姓名查询\t"<<"2：浏览\t"<<"3:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat3,ios::in|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(relative));
				 }
				 while(book.name!=key&&!endMark3(book));
				 if(book.name==key)
					 {
						 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"称呼\t"<<endl;
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.callname<<'\n';			
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			 {
				  fstream fdat(fileDat3,ios::in|ios::binary);
				 if(!fdat)
				 {
					 cout<<"亲戚文件不存在，请进行初始化操作\n";
					 fdat.close();
					 return;
				 }
				 else
				 {
				string min[50][5];
				 int t;
				 int x=0;
				 string a[50][5];
				 fdat.seekg(0,ios::beg);
				 for(int i=0;!endMark3(book);i++)
				 {
					 fdat.read((char*)&book,sizeof(relative));
					 if(!endMark3(book))
					 {
					 a[i][0]=book.name;
					 a[i][1]=book.birthdate;
					 a[i][2]=book.number;
					 a[i][3]=book.email;
					 a[i][4]=book.callname;
					 x++;
				 }
				 }
				 for(int i=0;i<x-1;i++)
				 {
					 t=i;
					 for(int j=i+1;j<x;j++)
					 {
						 if(a[j][0]<a[t][0])
					t=j;
						 if(t!=i)
						 {
							 min[i][0]=a[i][0];
							  min[i][1]=a[i][1];
							   min[i][2]=a[i][2];
							    min[i][3]=a[i][3];
								 min[i][4]=a[i][4];
							 a[i][0]=a[t][0];
							  a[i][1]=a[t][1];
							   a[i][2]=a[t][2];
							    a[i][3]=a[t][3];
								 a[i][4]=a[t][4];
						     a[t][0]=min[i][0];
							  a[t][1]=min[i][1];
							   a[t][2]=min[i][2];
							    a[t][3]=min[i][3];
								 a[t][4]=min[i][4];
						 }
					 }
				 } 
cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"称呼\t"<<endl;	
 for(int i=0;i<x;i++)
				 {		
cout<<a[i][0]<<'\t'<<a[i][1]<<'\t'<<a[i][2]<<'\t'<<a[i][3]<<'\t'<<a[i][4]<<'\n';
				 }
				  fdat.close();
				  break;
				 }
			 };
		 case'3':		 
			{  
				system("cls");
			return;
			};
		 }
	 }
}
void relatives::Change(const char*fileDat3)
{
	fstream fdat(fileDat3,ios::in|ios::out|ios::binary);
	relative book;
	char choice;
	string key;
	system("cls");
 cout<<"\n\t**************************************************************\n";
 cout<<"\n\n\t*****************************修改*****************************\n";
 cout<<"\n\t**************************************************************\n";
 while(1)
{
	cout<<"请输入操作选择\n"<<"1:修改\t"<<"2:退出\n";
	cin>>choice;
	switch(choice)
		case'1':
			 {		
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(relative));
				 }
				 while(book.name!=key&&!endMark3(book));
				 if(book.name==key)
				 {	 
					 char choice;
					 cout<<"请选择修改项\n"<<"a:电话\t"<<"b:邮箱\t"<<"c:称呼\t"<<"d:退出\n";
					 cin>>choice;
					 switch(choice)
					 {
		case'a':{
			cout<<"请输入要修改的电话号码：\n";
			cin>>book.number;
			fdat.seekp(-long(sizeof(relative)),ios::cur);
			fdat.write((char*)&book,sizeof(relative));
			cout<<"修改成功"<<endl;
			break;
				};
		case'b':{
			cout<<"请输入要修改的邮箱地址：\n";
			cin>>book.email;
			fdat.seekp(-long(sizeof(relative)),ios::cur);
			fdat.write((char*)&book,sizeof(relative));
			cout<<"修改成功"<<endl;
			break;
				};
		case'c':{
			cout<<"请输入要修改的称呼名称：\n";
			cin>>book.callname;
			fdat.seekp(-long(sizeof(relative)),ios::cur);
			fdat.write((char*)&book,sizeof(relative));
			cout<<"修改成功"<<endl;
			break;
				};
		case'd':{
			fdat.close();
			system("cls");
			return;
				};
				 }
				 }
				 else
					 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }; 
		case'2':
			{
				fdat.close();
			system("cls");
			return;
			};
			 }
}
}
void relatives::Delete(const char*fileDat3)
{
	 relative book;
	 char choice;
	string key;
	 system("cls");
	 cout<<"\n\t**************************************************************\n";
	 cout<<"\n\n\t*****************************删除*****************************\n";
	 cout<<"\n\t**************************************************************\n";
	 while(1)
	 {
		 cout<<"请输入操作选择\n"<<"1:删除\t"<<"2:退出\n";
		 cin>>choice;
		 switch(choice)
		 {
		 case'1':
			 {
				 fstream fdat(fileDat,ios::in|ios::out|ios::binary);
				 fdat.seekg(0,ios::beg);
				 cout<<"姓名？\n";
				 cin>>key;
				 do
				 { 
					 fdat.read((char*)&book,sizeof(relative));
				 }
				 while(book.name!=key&&!endMark3(book));
				 if(book.name==key)
					 {
						 string a[50][5];
						 int i=0;
						 fdat.seekp(-long(sizeof(relative)),ios::cur);
						book.name="\0";
								book.birthdate="\0";
									book.number="\0";
										book.email="\0";
										book.callname="\0";
				fdat.write((char*)&book,sizeof(relative));
				fdat.seekg(0,ios::beg);
				for(;!endMark3(book);)
				{
					fdat.read((char*)&book,sizeof(relative));
					if(book.name!="\0")
					{
                          a[i][0]=book.name;
						  a[i][1]=book.birthdate;
						  a[i][2]=book.number;
						  a[i][3]=book.email;
						  a[i][4]=book.callname;
						  i++;
					}
					else
						continue;
				}
				fdat.seekp(0,ios::beg);
				fdat.write((char*)&mark,sizeof(relative));
				fdat.seekp(0,ios::beg);
				for(int k=0;k<i;k++)
				{
					book.name=a[k][0];
					book.birthdate=a[k][1];
					book.number=a[k][2];
					book.email=a[k][3];
					book.callname=a[k][4];
					fdat.write((char*)&book,sizeof(relative));
				}
fdat.write((char*)&mark,sizeof(relative));
	 cout<<"删除成功！"<<endl;
				 }
				 else
				 {
					 cout<<"姓名输入错误或文件不存在\n";
				 continue;
				 }
				  fdat.close();
				 break;
			 };
		 case'2':
			{ 
				system("cls");
			return;
			};
		 }
	 }
}
void Showall()
{
		student book;
		mate book1;
		partner book2;
		relative book3;
		fstream fdat(fileDat,ios::in|ios::binary);
		if(fdat)
		{
			fdat.seekg(0,ios::beg);
		 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"学校\t"<<endl;
do
{	
	fdat.read((char*)&book,sizeof(student));
	if(!endMark(book))
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.schoolname<<'\n';	
}
while(!endMark(book));
		}
		else 
			cout<<"同学文件不存在"<<endl;
fdat.close();
fstream fdat1(fileDat1,ios::in|ios::binary);
if(fdat1)
{
	fdat1.seekg(0,ios::beg);
 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"公司\t"<<endl;
do
{	
	fdat1.read((char*)&book1,sizeof(mate));
	if(!endMark1(book1))
cout<<book1.name<<'\t'<<book1.birthdate<<'\t'<<book1.number<<'\t'<<book1.email<<'\t'<<book1.companyname<<'\n';	
}
while(!endMark1(book1));
}
else
			cout<<"同事文件不存在"<<endl;
fdat1.close();
fstream fdat2(fileDat2,ios::in|ios::binary);
if(fdat2)
{
	fdat2.seekg(0,ios::beg);
	 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"地点\t"<<endl;
do
{		
	fdat2.read((char*)&book2,sizeof(partner));
	if(!endMark2(book2))
cout<<book2.name<<'\t'<<book2.birthdate<<'\t'<<book2.number<<'\t'<<book2.email<<'\t'<<book2.placename<<'\n';
}
while(!endMark2(book2));
}
else 
			cout<<"朋友文件不存在"<<endl;
fdat2.close();
fstream fdat3(fileDat3,ios::in|ios::binary);
if(fdat3)
{
	fdat3.seekg(0,ios::beg);
	 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"称呼\t"<<endl;
do
{
	
	fdat3.read((char*)&book3,sizeof(relative));
	if(!endMark3(book3))
cout<<book3.name<<'\t'<<book3.birthdate<<'\t'<<book3.number<<'\t'<<book3.email<<'\t'<<book3.callname<<'\n';
}
while(!endMark3(book3));
}
else 
			cout<<"亲戚文件不存在"<<endl;
fdat3.close();
}
void Showbirth()
{
	student book;
		mate book1;
		partner book2;
		relative book3;
		time_t t;
 char tstr[32];
 t=time(NULL);
 ctime_s(tstr,32,&t);
		fstream fdat(fileDat,ios::in|ios::binary);
		if(fdat)
		{
			fdat.seekg(0,ios::beg);
		 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"学校\t"<<endl;
do
{	
	fdat.read((char*)&book,sizeof(student));
	if(!endMark(book))
	{
	if((string(tstr).substr(4,3)==book.month)&&((string(tstr).substr(8,9)).capacity()-(book.birthdate.substr(8,9)).capacity())<=5)	
cout<<book.name<<'\t'<<book.birthdate<<'\t'<<book.number<<'\t'<<book.email<<'\t'<<book.schoolname<<'\n';	
}
}
while(!endMark(book));
		}
		else 
			cout<<"同学文件不存在"<<endl;
fdat.close();
fstream fdat1(fileDat1,ios::in|ios::binary);
if(fdat1)
{
	fdat1.seekg(0,ios::beg);
 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"公司\t"<<endl;
do
{	
	fdat1.read((char*)&book1,sizeof(mate));
	if(!endMark1(book1))
	{
		if((string(tstr).substr(4,3)==book1.month)&&((string(tstr).substr(8,9)).capacity()-(book1.birthdate.substr(8,9)).capacity())<=5)	
cout<<book1.name<<'\t'<<book1.birthdate<<'\t'<<book1.number<<'\t'<<book1.email<<'\t'<<book1.companyname<<'\n';	
}
}
while(!endMark1(book1));
}
else 
			cout<<"同事文件不存在"<<endl;
fdat1.close();
fstream fdat2(fileDat2,ios::in|ios::binary);
if(fdat2)
{
	fdat2.seekg(0,ios::beg);
	 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"地点\t"<<endl;
do
{		
	fdat2.read((char*)&book2,sizeof(partner));
	if(!endMark2(book2))
	{
		if((string(tstr).substr(4,3)==book2.month)&&((string(tstr).substr(8,9)).capacity()-(book2.birthdate.substr(8,9)).capacity())<=5)	
cout<<book2.name<<'\t'<<book2.birthdate<<'\t'<<book2.number<<'\t'<<book2.email<<'\t'<<book2.placename<<'\n';
}
}
while(!endMark2(book2));
}
else 
			cout<<"朋友文件不存在"<<endl;
fdat2.close();
fstream fdat3(fileDat3,ios::in|ios::binary);
if(fdat3)
{
	fdat3.seekg(0,ios::beg);
	 cout<<"姓名\t"<<"生日\t"<<"电话\t"<<"邮箱\t"<<"称呼\t"<<endl;
do
{
	
	fdat3.read((char*)&book3,sizeof(relative));
	if(!endMark3(book3))
	{
		if((string(tstr).substr(4,3)==book3.month)&&((string(tstr).substr(8,9)).capacity()-(book3.birthdate.substr(8,9)).capacity())<=5)	
cout<<book3.name<<'\t'<<book3.birthdate<<'\t'<<book3.number<<'\t'<<book3.email<<'\t'<<book3.callname<<'\n';
}
}
while(!endMark3(book3));
}
else 
			cout<<"亲戚文件不存在"<<endl;
fdat3.close();
}
void Tellbirth()
{
	int x=0;
	string key;
	cout<<"请输入月份（01/02/03/04/05/06/07/08/09/10/11/12)"<<endl;
	cin>>key;
	    student book;
		mate book1;
		partner book2;
		relative book3;
		fstream fdat(fileDat,ios::in|ios::binary);
		if(fdat)
		{
			fdat.seekg(0,ios::beg);
do
{	
	fdat.read((char*)&book,sizeof(student));
	if(!endMark(book))
	{
		if((book.birthdate.substr(5,2)==key))
			x++;
	}
}
while(!endMark(book));
		}
		else 
			cout<<"同学文件不存在"<<endl;
fdat.close();
fstream fdat1(fileDat1,ios::in|ios::binary);
if(fdat1)
{
	fdat1.seekg(0,ios::beg);
do
{	
	fdat1.read((char*)&book1,sizeof(mate));
	if(!endMark1(book1))
	{
		if((book.birthdate.substr(5,2)==key))
			x++;
	}
}
while(!endMark1(book1));
}
else 
			cout<<"同事文件不存在"<<endl;
fdat1.close();
fstream fdat2(fileDat2,ios::in|ios::binary);
if(fdat2)
{
	fdat2.seekg(0,ios::beg);
do
{		
	fdat2.read((char*)&book2,sizeof(partner));
	if(!endMark2(book2))
	{
		if((book.birthdate.substr(5,2)==key))
			x++;
	}
}
while(!endMark2(book2));
}
else 
			cout<<"朋友文件不存在"<<endl;
fdat2.close();
fstream fdat3(fileDat3,ios::in|ios::binary);
if(fdat3)
{
	fdat3.seekg(0,ios::beg);
do
{
	
	fdat3.read((char*)&book3,sizeof(relative));
	if(!endMark3(book3))
	{
		if((book.birthdate.substr(5,2)==key))
			x++;
	}
}
while(!endMark3(book3));
}
else 
cout<<"亲戚文件不存在"<<endl;
fdat3.close();
cout<<"您有"<<x<<"位联系人在此月出生";
	cout<<endl;
}
int main()      
{ char choice;
	students stu;
	mates mat;
	partners par;
	relatives rel;
while(1)
{
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************欢迎使用!****************************\n";
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t**********************通讯录管理系统**************************\n请输入操作选择\n"
	<<"1:同学\t"<<"2:同事\t"<<"3:朋友\t"<<"4:亲戚\t"<<"5:Messagebox\t"<<"6:退出\t";
cout<<endl;
cout<<"#提示：输入操作选择后按回车键即可进行下一步的操作#";
cout<<endl;
cout<<"\t*********************Input Your Choice:***********************\n";
cout<<endl;
cin>>choice;
switch(choice)
{
case'1':
	{
		system("cls");  
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************同学信息界面*************************\n";
cout<<"\n\t**************************************************************\n";
		cout<<"请输入操作选择\n"
			<<"0:初始化\t"<<"1:录入\t"<<"2:查询\t"<<"3:修改\t"<<"4:删除\t"<<"5:退出\t";
	cout<<endl;
	char n1;
	cin>>n1;
  switch(n1)     
       { 
       case '0':  {
		   stu.Initial(fileDat);        
		   break;
				  };
	   case'1': {
		   stu.Entry(fileDat);
		   break;
				};
	   case'2':{
		   stu.Inquire(fileDat);
		   break;
			   };
	   case'3':{
		   stu.Change(fileDat);
		   break;
			   };
	   case'4':{
		   stu.Delete(fileDat);
		   break;
			   }
			    case'5':{
					system("cls");
		   break;
						};
  }
	break;
	};
	case'2':
	{
		  system("cls");
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************同事信息界面*************************\n";
cout<<"\n\t**************************************************************\n";
		cout<<"请输入操作选择\n"
			<<"0:初始化\t"<<"1:录入\t"<<"2:查询\t"<<"3:修改\t"<<"4:删除\t"<<"5:退出\t";
	cout<<endl;
	char n2;
	cin>>n2;
  switch(n2)     
       { 
       case '0':  {
		   mat.Initial(fileDat1);        
		   break;
				  };
	   case'1': {
		   mat.Entry(fileDat1);
		   break;
				};
	   case'2':{
		   mat.Inquire(fileDat1);
		   break;
			   };
	   case'3':{
		   mat.Change(fileDat1);
		   break;
			   };
		    case'4':{
				mat.Delete(fileDat1);
				break;
					};
				 case'5':{
					 system("cls");
		   break;
						 };
  }
	break;
	};
case'3':
	{
		  system("cls");
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************朋友信息界面*************************\n";
cout<<"\n\t**************************************************************\n";
		cout<<"请输入操作选择\n"
			<<"0:初始化\t"<<"1:录入\t"<<"2:查询\t"<<"3:修改\t"<<"4:删除\t"<<"5:退出\t";
	cout<<endl;
	char n3;
	cin>>n3;
  switch(n3)     
       { 
       case '0':  {
		   par.Initial(fileDat2);        
		   break;
				  };
	   case'1': {
		   par.Entry(fileDat2);
		   break;
				};
	   case'2':{
		   par.Inquire(fileDat2);
		   break;
			   };
	   case'3':{
		   par.Change(fileDat2);
		   break;
			   };
		    case'4':{
				par.Delete(fileDat2);
				break;
					};
				case'5':{
					system("cls");
		   break;
						};
  }
	break;
	};
case'4':
	{
		  system("cls");
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************亲戚信息界面*************************\n";
cout<<"\n\t**************************************************************\n";
		cout<<"请输入操作选择\n"
			<<"0:初始化\t"<<"1:录入\t"<<"2:查询\t"<<"3:修改\t"<<"4:删除\t"<<"5:退出\t";
	cout<<endl;
	char n4;
	cin>>n4;
  switch(n4)     
       { 
       case '0':  {
		   rel.Initial(fileDat3);        
		   break;
				  };
	   case'1': {
		   rel.Entry(fileDat3);
		   break;
				};
	   case'2':{
		   rel.Inquire(fileDat3);
		   break;
			   };
	   case'3':{
		   rel.Change(fileDat3);
		   break;
			   };
		   case'4':{
			   rel.Delete(fileDat3);
		   break;
				   }
				   case'5':{
					   system("cls");
		   break;
						   };
  }
	break;
	};
case'5':{
	system("cls");
cout<<"\n\t**************************************************************\n";
cout<<"\n\n\t*************************展示信息界面*************************\n";
cout<<"\n\t**************************************************************\n";
cout<<"请输入操作选择\n"
			<<"1：成员罗列\t"<<"2:生日提醒\t"<<"3:生日查询\t"<<"4:退出\t";
	cout<<endl;
	char n5;
	cin>>n5;
  switch(n5)     
       { 
  case'1':{
	  Showall();
	break;
		  };
	   case'2':{
	  Showbirth();
	break;
		  };
		    case'3':{
	  Tellbirth();
	break;
		  };
  case'4':{
	  system("cls");
	  break;
		};
}
  break;
}
case'6':
	{
		system("cls");
	cout<<"\n\n\t*************************退出系统!****************************\n";
	return 0;
	};
default:{
	system("cls");
	cout<<"输入错误，请重新输入\n";
		};
}
}
}

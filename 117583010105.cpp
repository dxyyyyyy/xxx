#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
int n=1;

void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsd(float v);

struct zhigong
{
    char number[10];
    char name[10];
    float post_wage;
    float pay_salary;
    float duty_allowance;
    float merit_pay;
    float gross_pay;
    float income_tax;
    float payroll;
    
};
struct zhigong zggz[100];

void read()
{
   
    ifstream DF_01("gx.dat",ios::in);
    if(!DF_01)
    {	
        cout<<"文件打开失败！"<<endl;
        abort();
    }
    int i=0;
    while(DF_01>>zggz[i].number)
    {
        n++;
    }
    n=i;
    DF_01.close();

    cout<<"按任意键返回主菜单";
    getch();
    return;
}

void write()
{
    FILE *fp;
    ofstream DF_05("gz.dat",ios::out);
    if(n>0)
    {	
        cout<<"文件打开失败！"<<endl;
        abort();
    }
    for(int i=0;i<n;i++)
    {
        fwrite(&zggz,sizeof(zggz),1,fp);
    }
    DF_05.close();

    cout<<"按任意键返回主菜单";
    getch();
    return;
}

void find()
{
    char gonghao[10];
    int i=0;
    cout<<"请输入查询的工号";
    gets(gonghao);
    for(i;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            cout<<"------------------------------------该职工工资信息如下------------------------------------"<<endl;
            cout<<"职工工号丨职工姓名丨岗位工资丨薪级工资丨职务津贴丨绩效工资丨应发工资丨个人所得税丨实发工资"<<endl;
            cout<<zggz[i].number[10]<<zggz[i].name[10]<<zggz[i].post_wage<<zggz[i].pay_salary<<zggz[i].duty_allowance
                <<zggz[i].merit_pay<<zggz[i].gross_pay<<zggz[i].income_tax<<zggz[i].payroll<<endl;
        }
        return;
    }
    
    cout<<"您所输入的职工工号有误或不存在！"<<endl;
    cout<<"按任意键返回主菜单";
    getch();
    return;
    
}

void list()
{
    cout<<"-----------------------------------全体职工工资信息如下-----------------------------------"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"职工工号丨职工姓名丨岗位工资丨薪级工资丨职务津贴丨绩效工资丨应发工资丨个人所得税丨实发工资"<<endl;
        cout<<zggz[i].number[10]<<zggz[i].name[10]<<zggz[i].post_wage<<zggz[i].pay_salary<<zggz[i].duty_allowance
            <<zggz[i].merit_pay<<zggz[i].gross_pay<<zggz[i].income_tax<<zggz[i].payroll<<endl;
    }
    
    cout<<"按任意键返回主菜单";
    getch();
    return;
}

void modify()
{
    char gonghao[10];
    cout<<"请输入查询的工号";
    gets(gonghao);
    for(int i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            cout<<"------------------------------------该职工工资信息如下------------------------------------"<<endl;
            cout<<"职工工号丨职工姓名丨岗位工资丨薪级工资丨职务津贴丨绩效工资丨应发工资丨个人所得税丨实发工资"<<endl;
            cout<<zggz[i].number[10]<<zggz[i].name[10]<<zggz[i].post_wage<<zggz[i].pay_salary<<zggz[i].duty_allowance
                <<zggz[i].merit_pay<<zggz[i].gross_pay<<zggz[i].income_tax<<zggz[i].payroll<<endl;
        }
    }
    
    cout<<"请输入该职工新的岗位工资："<<endl;
    cin>>zggz[i].post_wage;
    cout<<endl;
    cout<<"请输入该职工新的薪级工资："<<endl;
    cin>>zggz[i].pay_salary;
    cout<<endl;
    cout<<"请输入该职工新的政务津贴："<<endl;
    cin>>zggz[i].duty_allowance;
    cout<<endl;
    cout<<"请输入该职工新的绩效工资："<<endl;
    cin>>zggz[i].merit_pay;
    cout<<endl;
    
    zggz[i].gross_pay=zggz[i].post_wage+zggz[i].pay_salary+zggz[i].duty_allowance+zggz[i].merit_pay;    //计算应发工资
    zggz[i].income_tax=grsd(zggz[i].gross_pay);    //计算个人所得税
    zggz[i].payroll=zggz[i].gross_pay=zggz[i].income_tax;    //计算应发工资
    
    cout<<"该职工的应发工资为："<<zggz[i].gross_pay<<endl;
    cout<<"该职工的个人所得税为："<<zggz[i].income_tax<<endl;
    cout<<"该职工的应发工资为："<<zggz[i].payroll<<endl;
    
    cout<<"按任意键返回主菜单";
    getch();
    return;
}

void del()
{
    char gonghao[10];
    cout<<"请输入要删除的职工号";
    gets(gonghao);
    char flg;
    for(int i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            cout<<"------------------------------------该职工工资信息如下------------------------------------"<<endl;
            cout<<"职工工号丨职工姓名丨岗位工资丨薪级工资丨职务津贴丨绩效工资丨应发工资丨个人所得税丨实发工资"<<endl;
            cout<<zggz[i].number[10]<<zggz[i].name[10]<<zggz[i].post_wage<<zggz[i].pay_salary<<zggz[i].duty_allowance
                <<zggz[i].merit_pay<<zggz[i].gross_pay<<zggz[i].income_tax<<zggz[i].payroll<<endl;
        }
    }
    
}

void add()
{
    n=n+1;
    cout<<"请输入该职工的职工工号："<<endl;
    cin>>zggz[n].number;
    cout<<"/n请输入该职工的职工姓名："<<endl;
    cin>>zggz[n].name;
    cout<<"/n请输入该职工的岗位工资："<<endl;
    cin>>zggz[n].post_wage;
    cout<<"/n请输入该职工的薪级工资："<<endl;
    cin>>zggz[n].pay_salary;
    cout<<"/n请输入该职工的政务津贴："<<endl;
    cin>>zggz[n].duty_allowance;
    cout<<"/n请输入该职工的绩效工资："<<endl;
    cin>>zggz[n].merit_pay;
    
    zggz[n].gross_pay=zggz[n].post_wage+zggz[n].pay_salary+zggz[n].duty_allowance+zggz[n].merit_pay;    //计算应发工资
    zggz[n].income_tax=grsd(zggz[n].gross_pay);    //计算个人所得税
    zggz[n].payroll=zggz[n].gross_pay=zggz[n].income_tax;    //计算应发工资

            cout<<"------------------------------------该职工工资信息如下------------------------------------"<<endl;
            cout<<"职工工号丨职工姓名丨岗位工资丨薪级工资丨职务津贴丨绩效工资丨应发工资丨个人所得税丨实发工资"<<endl;
            cout<<zggz[n].number[10]<<zggz[n].name[10]<<zggz[n].post_wage<<zggz[n].pay_salary<<zggz[n].duty_allowance
                <<zggz[n].merit_pay<<zggz[n].gross_pay<<zggz[n].income_tax<<zggz[n].payroll<<endl;

    cout<<"按任意键返回主菜单";
    getch();
    return;
}

float grsd(float v)
{
    float x=v;
    float y=0;
    int n;
    
    if(x>0)
    {
        if(x<500)    n=1;
        else if(x<2000)    n=2;
        else if(x<5000)    n=3;
        else if(x<20000)    n=4;
        else if(x<40000)    n=5;
        else if(x<60000)    n=6;
        else if(x<80000)    n=7;
        else if(x<100000)    n=8;
        else n=9;
    }
    
    switch(n)
    {
    case 1:y=y+x*0.05;
    case 2:y=y+(x-500)*0.1;
    case 3:y=y+(x-2000)*0.15;
    case 4:y=y+(x-5000)*0.2;
    case 5:y=y+(x-20000)*0.25;
    case 6:y=y+(x-40000)*0.3;
    case 7:y=y+(x-60000)*0.35;
    case 8:y=y+(x-80000)*0.4;
    case 9:y=y+(x-100000)*0.45;
    }
    
    return y;
}

void main()
{
    read();
    int flg;
    cout<<"┌───────────欢迎使用职工工资管理系统───────────┐"<<endl;
    cout<<"├──────────────┤1、 查询├──────────────┤"<<endl;
    cout<<"├──────────────┤2、 修改├──────────────┤"<<endl;
    cout<<"├──────────────┤3、 添加├──────────────┤"<<endl;
    cout<<"├──────────────┤4、 删除├──────────────┤"<<endl;
    cout<<"├──────────────┤5、 保存├──────────────┤"<<endl;
    cout<<"├──────────────┤6、 浏览├──────────────┤"<<endl;
    cout<<"├──────────────┤7、 修改├──────────────┤"<<endl;
    cout<<"├─────────────请输入一个数字──────────────┤"<<endl;
    cout<<"└──────────────────────────────────┘"<<endl;
    cin>>flg;

    switch(flg)
    {
    case 1:find();break;
    case 2:modify();break;
    case 3:add();break;
    case 4:del();break;
    case 5:write();break;
    case 6:list();break;
    case 7:return;
    }

    return;
    
}
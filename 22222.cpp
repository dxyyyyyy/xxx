#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
int n=0;

void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsd(float v);

struct zhigong
{   char number[10];
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
    FILE*Read=fopen("gx.dat","ab+");
    if(Read)
    {   
        while(!feof(Read))
        {
            char A=fgetc(Read);
			char a=EOF;
            if(A!=a)
            {
                fscanf(Read,"%s%s%f%f%f%f%f%f%f",&zggz[n].number,&zggz[n].name,&zggz[n].post_wage,&zggz[n].pay_salary,
                    &zggz[n].duty_allowance,&zggz[n].merit_pay,&zggz[n].gross_pay,&zggz[n].income_tax,&zggz[n].payroll);
                n++;
            }
        }
        fclose(Read);
    }
    else
    {
        printf("\n文件打开失败！");
    }
    
}

void write()
{
    FILE*DF_05=fopen("gx.dat","wb");
    if(DF_05)
    {   
         for(int i=0;i<n;i++)
        {
            fprintf(DF_05,"%-10s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\n",zggz[i].number,zggz[i].name,zggz[i].post_wage,
                zggz[i].pay_salary,zggz[i].duty_allowance,zggz[i].merit_pay,zggz[i].gross_pay,zggz[i].income_tax,zggz[i].payroll);
        }
        fclose(DF_05);
        printf("\n文件保存成功！");
    }
    else
    {
        printf("\n文件打开失败！");
    }
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
}

void find()
{
    char gonghao[10];
	printf("请输入查询的工号");
    scanf("%s",gonghao);
    for(int i=0;i<n;i++)
    {	
        if(strcmp(gonghao,zggz[i].number)==0)
        {
			printf("-------------------------------该职工工资信息如下------------------------------");
			printf(	"丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
					"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
					"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
				zggz[i].number, zggz[i].name, zggz[i].post_wage, 
				zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
				zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
			i=1;
			break;
			
		}
    }
	if(!i)
	{
    printf("您所输入的职工工号有误或不存在！");
	}
	printf("\n按任意键返回主菜单");
	if(getch())
	{   
		system("cls");
		return;
	}
	
}

void list()
{
    ofstream DF_05("gx.dat");
    printf("------------------------------全体职工工资信息如下------------------------------\n");
    for(int i=0;i<n;i++)
    {
      	printf(	"丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
				"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
				"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n\n",
				zggz[i].number, zggz[i].name, zggz[i].post_wage, 
				zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
				zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
	    }

    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
}

void modify()
{
    char gonghao[10];
    printf("请输入查询的工号");
    scanf("%s",gonghao);
    for(int i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            printf("------------------------------------该职工工资信息如下------------------------------------");
            printf(	"丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
					"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
					"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
					zggz[i].number, zggz[i].name, zggz[i].post_wage, 
					zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
					zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);        
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
    
    printf("该职工的应发工资为：%-15f\n",zggz[i].gross_pay);
    printf("该职工的个人所得税为：%-15f\n",zggz[i].income_tax);
    printf("该职工的应发工资为：%-15f",zggz[i].payroll);
    
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
}

void del()
{
    char gonghao[10];
    cout<<"请输入要删除的职工号";
    scanf("%s",gonghao);
   
    for(int i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
			printf("--------------------------------查到该职工工资信息如下--------------------------------\n");;
            printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
					"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
					"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
					zggz[i].number, zggz[i].name, zggz[i].post_wage, 
					zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
					zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
			printf("你真的要删除这个职工的工资信息？\n");
			printf("是，请按1\t\t否，请按2\n");
			char flg;
			scanf("%d",flg);
			if(flg)
			{
				for(int j=i;j<n-1;j++)
				{
					zggz[j]=zggz[j+1];
				
				}
				strcpy(zggz[n-1].number, " "); 
				strcpy(zggz[n-1].name, " "); 
				zggz[n-1].post_wage=0; 
				zggz[n-1].pay_salary=0;
				zggz[n-1].duty_allowance=0; 
				zggz[n-1].merit_pay=0;
				zggz[n-1].gross_pay=0;
				zggz[n-1].income_tax=0;
				zggz[n-1].payroll=0;
			}

		}
    }
	printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
    
}

void add()
{
    n=n+1;
    printf("请输入该职工的职工工号,职工姓名,岗位工资,薪级工资,政务津贴,绩效工资\n");
    scanf("%s%s%f%f%f%f",&zggz[n-1].number,&zggz[n-1].name,&zggz[n-1].post_wage,&zggz[n-1].pay_salary,&zggz[n-1].duty_allowance,&zggz[n-1].merit_pay);

    zggz[n-1].gross_pay=zggz[n-1].post_wage + zggz[n-1].pay_salary + zggz[n-1].duty_allowance + zggz[n-1].merit_pay;    //计算应发工资
    zggz[n-1].income_tax=grsd(zggz[n-1].gross_pay);    //计算个人所得税
    zggz[n-1].payroll=zggz[n-1].gross_pay - zggz[n-1].income_tax;    //计算应发工资

	printf(	"------------------------添加成功，这个职工的信息为：------------------------\n");
	printf(	"丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
			"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
			"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
			zggz[n-1].number,zggz[n-1].name,zggz[n-1].post_wage,
			zggz[n-1].pay_salary,zggz[n-1].duty_allowance,zggz[n-1].merit_pay,
			zggz[n-1].gross_pay,zggz[n-1].income_tax,zggz[n-1].payroll);

    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
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
        case 8:y=y+(x-80000)*0.4;
        case 7:y=y+(x-60000)*0.35;
        case 6:y=y+(x-40000)*0.3;
        case 5:y=y+(x-20000)*0.25;
        case 4:y=y+(x-5000)*0.2;
        case 3:y=y+(x-2000)*0.15;
        case 2:y=y+(x-500)*0.1;
        case 1:y=y+x*0.05;
    }

    return y;
}

void main()
{

	system("cls");
    read();
    int flg;
	while(1)
	{
		cout<<n<<endl;
		printf("┌─────────☆─欢迎使用职工工资管理系统─☆─────────┐\n");
		printf("├────────☆─────┤1、 查询├─────☆────────┤\n");
		printf("├───────☆──────┤2、 修改├──────☆───────┤\n");
		printf("├──────☆───────┤3、 添加├───────☆──────┤\n");
		printf("├─────☆────────┤4、 删除├────────☆─────┤\n");
		printf("├────☆─────────┤5、 保存├─────────☆────┤\n");
		printf("├───☆──────────┤6、 浏览├──────────☆───┤\n");
		printf("├──☆───────────┤7、 退出├───────────☆──┤\n");
		printf("├─☆─────────请输入一个数字(￣▽￣)~*─────────☆─┤\n");
		printf("└☆────────────────────────────────☆┘\n");

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
	}

    return;
    
}
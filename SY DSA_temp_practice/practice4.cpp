#include<iostream>
#include<cstring>
using namespace std;

class market
{
    public:
    int stock,date,month,year;
    string item_name,category;

    public:
    market(){
        stock=0;
        date=0;
        month=0;
        year=0;
    }

    void getdata(){
        cout<<"Enter item name: ";
        cin>>item_name;
        cout<<"Enter Stock Available: ";
        cin>>stock;
        cout<<"Enter the date of purchase: ";
        cout<<"day: ";cin>>date;cout<<"month: ";cin>>month;cout<<"year :";cin>>year;cout<<"Enter category: ";
        cin>>category;
    }

    void display(){
        cout<<'\n';
        cout<<"Item name: "<<item_name<<endl;
        cout<<"Date of purchase: "<<date<<"/"<<month<<"/"<<year<<endl;
        cout<<"Stock Available: "<<stock<<endl;
        cout<<"Category: "<<category<<endl;
    }

    void stock_sort(market m[],int f,int l){
            if(f<l)
            {
                int pivot=f;
                int i=f+1;
                int j=l;
                while(i<j)
                {
                    while(m[i].stock < m[pivot].stock)
                    {i++;}
                    while(m[j].stock > m[pivot].stock)
                    {j--;}
                    if(i<j)
                    {
                        market temp=m[i];
                        m[i]=m[j];
                        m[j]=temp;
                    }
                    else{
                        break;
                    }
                }
                market t;
                t=m[j];
                m[j]=m[pivot];
                m[pivot]=t;

                stock_sort(m,f,j-1);
                stock_sort(m,j+1,l);
        }
    }
    
    void date_sort(market m[],int t,int d){
        int gap=t/2;
        while(gap>=1)
        {
            for(int j=gap;j<t;j++)
            {
                for(int i=j-gap;i>=0;i=i-gap)
                {
                    if(d==0){
                      if(m[i+gap].date>=m[i].date)
                        {
                            break;
                        }
                        else{
                            market temp;
                            temp=m[i+gap];
                            m[i+gap]=m[i];
                            m[i]=temp;
                       }  
                    }

                    if(d==1){
                        if(m[i+gap].month>=m[i].month)
                        {
                            break;
                        }
                        else{
                            market temp;
                            temp=m[i+gap];
                            m[i+gap]=m[i];
                            m[i]=temp;
                        }
                    }

                    if(d==2){
                        if(m[i+gap].year>=m[i].year)
                        {
                            break;
                        } 
                        else{
                            market temp;
                            temp=m[i+gap];
                            m[i+gap]=m[i];
                            m[i]=temp;
                        }
                    }
                
                }
            } 
            gap=gap/2;
        }
    }

    void category_sort(market m[],int n,string a)
    {
        for(int i=0;i<n;i++){
            if(m[i].category==a){
                m[i].display();
            }
        }
    }
};

int main(){
    int n;
    cout<<"Enter no. of items: ";
    cin>>n;
    string a,ch;
    market m[n],x;
    int f=0,l=n-1;
    int t;
    do
    {
        cout<<"\n1.To add data \n2.To display data \n3.Sort according to date \n4.Sort according to stock \n5.To sort According to Category \n7.To update \n6.Exit \n";
        cout<<"Enter respective no.: ";
        cin>>t;
        switch(t)
            {
                case 1:for(int i=0;i<n;i++){
                            m[i].getdata();
                        }
                        break;
                case 2:for(int i=0;i<n;i++){
                            cout<<i+1;
                            m[i].display();
                        }
                        break;
                case 3:for(int i=0;i<3;i++){
                            x.date_sort(m,n,i);
                        }
                        for(int i=0;i<n;i++){
                            m[i].display();
                        }
                        break;
                case 4:x.stock_sort(m,f,l);
                        for(int i=0;i<n;i++){
                            m[i].display();
                        }
                        break;
                case 5:cout<<"Enter the category: ";
                    cin>>a;
                    x.category_sort(m,n,a);
                    break;
                case 6:return 0;
                default: break;
            }
            std::cout<<"To continue Enter y:";
            cin>>ch;
    }while(ch=="y");
    
    return 0;
}
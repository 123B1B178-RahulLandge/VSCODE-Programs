#include<iostream>
using namespace std;

class Employee{	
	int EmpID;
	string Name;
	int contact;
	
	public:
	int index;
	Employee(){
		EmpID = -1;
		Name = "";
		contact = -1;
		index = -1;
	}
	void setID(int id){EmpID = id;}
	void setName(int n){Name = n;}
	void setContact(int c){contact = c;}
	void setIndex(int i){ index = i;}
	
	int getID(){ return EmpID;}
	void setEmployee(int EmpID,string N,int contact,int index){
		this->EmpID = EmpID;
		Name = N;
		this->contact = contact;
		this->index = index;
	}
	void printEmployee(){
		cout<<"Details: "<<EmpID<<" - "<<Name<<" - "<<contact<<endl;
	}
	
};
class HashTable{
	int tableSize;
	Employee *ht;
	public:
	HashTable(int size){
		tableSize = size;
		ht = new Employee[tableSize];
	}
	int hash(int value){
		return(value%tableSize);
	}
	void insertIntoHT(int EmpID,string N,int contact){
		int ToBeInsertedAt = hash(EmpID);
		if(ht[ToBeInsertedAt].index == -1){ 
			ht[ToBeInsertedAt].setEmployee(EmpID,N,contact,ToBeInsertedAt);
		}
		else{
			for(int i=0;i<tableSize;i++){
				ToBeInsertedAt = (ToBeInsertedAt+1)%tableSize;
			
				if(ht[ToBeInsertedAt].index == -1){ 
				ht[ToBeInsertedAt].setEmployee(EmpID,N,contact,ToBeInsertedAt);
					return;
				}
			}
			cout<<"HashTable is full"<<endl;
		}
	}
	void searchInHT(int EmpID){
		int ToBeInsertedAt = hash(EmpID);
		if(ht[ToBeInsertedAt].getID() == EmpID){ //data found
			ht[ToBeInsertedAt].printEmployee();
		}
		else{
			for(int i=0;i<tableSize;i++){
				ToBeInsertedAt = (ToBeInsertedAt+1)%tableSize;
			
				if(ht[ToBeInsertedAt].getID() == EmpID){ 
					ht[ToBeInsertedAt].printEmployee();	
					return;
				}
			}
			cout<<EmpID<<"details not found"<<endl;
		}
	}
	void displayHT(){
		for(int i=0;i<tableSize;i++)
			ht[i].printEmployee();
	}
};

int main(){
	HashTable ht1(10);
	ht1.insertIntoHT(123,"ABC",98765);
	ht1.insertIntoHT(12,"PQR",98765);
	ht1.insertIntoHT(355,"ABC",98765);
	ht1.insertIntoHT(234,"ABC",98765);
	ht1.insertIntoHT(129,"ABC",98765);
	ht1.insertIntoHT(3,"ABC",98765);
	ht1.insertIntoHT(229,"ABC",98765);
	ht1.insertIntoHT(227,"ABC",98765);
	ht1.insertIntoHT(228,"ABC",98765);
	ht1.insertIntoHT(19,"ABC",98765);
	ht1.searchInHT(3);
	ht1.searchInHT(13);
	ht1.displayHT();
}
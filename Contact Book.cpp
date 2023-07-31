#include<iostream>
#include<fstream>
using namespace std;
class Node{
	private:
		friend class Contact_BOOK;
		string name;
		string phone_no;
		string group;
		Node* next;
		Node* prev;
	public:
		Node(){}
		Node(string name,string phone,string gro){
			this->name=name;
			this->phone_no=phone;
			this->group=gro;
			this->next=NULL;
			this->prev=NULL;
		}
};
class Contact_BOOK{
	private:
		
	Node* head=NULL;
	fstream FileName;
	public:
	void menu(){
		top:
		char op;
		
		
		cout<<"*************************************************************************"<<endl;
		cout<<"  1. Add Contact"<<endl;
    	cout<<"  2. Edit the Contact"<<endl;
    	cout<<"  3. Delete Contact"<<endl;
    	cout<<"  4. Search Contacts"<<endl;
    	cout<<"  5. Display Contacts"<<endl;
    	cout<<"  6. Exit"<<endl;
    	cout<<"************************************************************************"<<endl;
		cin>>op;
		switch(op){
			case '1':{
				system("cls");
				create();
				break;
			}
			case '2':{
				system("cls");
				Editrecord();
				break;
			}
			case '3':{
				system("cls");
				char op1;
				cout<<"1.For del specific contact."<<endl;
				cout<<"2.for del all contact"<<endl;
				cin>>op1;
				switch (op1)
				{
				case '1':
					
					deletedata();
					break;
				case '2':
					head=NULL;
					remove("Contacts.txt");
					cout<<"All record deleted...."<<endl;
					break;
				default:
					cout<<"Invalid input..."<<endl;
				}
				break;
			}
			case '4':{
				system("cls");
				search();
				break;
			}
			case '5':{
				system("cls");
				display();
				break;
			}
			case '6':{
				exit(0);
				break;
			}
			default:{
				cout<<"Invalid input......"<<endl;
			}
		
		
		}
		goto top;
	}

	void Editrecord(){
		int i=0;
		if(i==0){
			storefiledata();
			i++;
		}
		if(head==NULL){
			cout<<"Contact Book is empty...."<<endl;
			return;
		} 
		char op;
		Node* temp=head;
		cout<<"Do you want to edit:"<<endl;
		cout<<"1.Name"<<endl;
		cout<<"2.Phone Number"<<endl;
		cin>>op;
		switch(op){
			case '1':{
				string naam;
				bool flag=false;
				cout<<"Enter name of contact to be edited";
				cin>>naam;
				while(temp!=NULL){
					if(temp->name==naam){
						cout<<"Previous Info."<<endl;
						cout<<"Name:"<<temp->name<<endl;
						cout<<"Phone Number:"<<temp->phone_no<<endl;
						cout<<"Label:"<<temp->group<<endl<<endl;
						cout<<"Enter new info."<<endl;
						cout<<"Name:";
						cin>>temp->name;
						cout<<"Wanna label this contact(y/n)";
						cin>>op;
						if(op=='y' || op=='Y'){
							naam=option();
						}
						else{
							naam="Basic";
						}
						temp->group=naam;
						flag=true;
						break;
					}
					temp=temp->next;
				}
				if(!flag){
					cout<<"Invalid info"<<endl;
				}
				break;
			}
			case '2':{
				string phone;
				bool flag=false;
				cout<<"Enter phone number of contact to be edited";
				cin>>phone;
				while(temp!=NULL){
					if(temp->phone_no==phone){
						cout<<"Previous Info:"<<endl;
						cout<<"Name:"<<temp->name<<endl;
						cout<<"Phone Number:"<<temp->phone_no<<endl;
						cout<<"Label:"<<temp->group<<endl<<endl;
						cout<<"Enter new info."<<endl;
						cout<<"Phone Number:";
						cin>>temp->phone_no;
						flag=true;
						break;
					}
					temp=temp->next;
				}
				if(!flag){
					cout<<"Invalid info"<<endl;
				}
				break;
			}
			default:{
				cout<<"Invalid input....."<<endl;
			}
		}
		storedatafromLL();
	}

	void search(){
		int i=0;
		if(i==0){
			storefiledata();
			i++;
		}
		if(head==NULL){
			cout<<"Contact Book is empty..."<<endl;
			return;
		}
		char op;
		Node* temp=head;
		cout<<"1.Do you want to search by name"<<endl;
		cout<<"2.Do you want to search by Phone number"<<endl;
		cin>>op;
		switch(op){
			case '1':{
				bool flag=false;
				string naam;
				cout<<"Enter contact name";
				cin>>naam;
				while(temp!=NULL){
					if(temp->name==naam){
						cout<<temp->name<<"\t"<<temp->phone_no<<"\t"<<temp->group<<endl;
						flag=true;
						break;
					}
					temp=temp->next;
				}
				if(!flag){
					cout<<"Contact not found...."<<endl;
				}
				break;
			}
			case '2':{
				bool flag=false;
				string naam;
				cout<<"Enter Phone number";
				cin>>naam;
				while(temp!=NULL){
					if(temp->phone_no==naam){
						cout<<temp->name<<"\t"<<temp->phone_no<<"\t"<<temp->group<<endl;
						flag=true;
						break;
					}
					temp=temp->next;
				}
				if(!flag){
					cout<<"Contact not found...."<<endl;
				}
				break;
			}
			default:
				cout<<"Invalid input...."<<endl;
		}
	}
	
	string option(){
		up:
		char op;
		cout<<"1.Family"<<endl;
		cout<<"2.Friend"<<endl;
		cout<<"3.Emergency"<<endl;
		cin>>op;
		switch(op){
			case '1':{
				return "Family";
				break;
			}
			case '2':{
				return "Friend";
				break;
			}
			case '3':{
				return "Emergency";
				break;
			}
			default:{
				cout<<"Enter valid number:"<<endl;
				goto up;
			}
		}
	}
	
	bool del(){
		Node* temp=head;
		char op;
		string name;
		string no;
		bool found=false;
		cout<<"1.To del by name"<<endl;
		cout<<"2.to del by number"<<endl;
		cin>>op;
		if(op=='1'){
			cout<<"Enter name of contact"<<endl;
			cin>>name;
			if(temp->name==name){
				head=head->next;
				head->prev=NULL;
				temp->next=NULL;
				delete temp;
				cout<<"Contact deleted...."<<endl;
				return true;
			}
			while(temp!=NULL){
				if(temp->name==name){
					found=true;
					break;
				}
				temp=temp->next;
			}
			if(found){
				if(temp->next==NULL){
					temp->prev->next=NULL;
					temp->prev=NULL;
					delete temp;
					cout<<"Contact deleted...."<<endl;
					return true;
				}
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				temp->next=NULL;
				temp->prev=NULL;
				delete temp;
				cout<<"Contact deleted....."<<endl;
				return true;
			}
			return false;
		} else if(op=='2'){
			cout<<"Enter number of contact"<<endl;
			cin>>no;
			if(temp->phone_no==no){
				head=head->next;
				head->prev=NULL;
				temp->next=NULL;
				delete temp;
				cout<<"Contact deleted...."<<endl;
				return true;
			}
			while(temp->next!=NULL){
				if(temp->phone_no==no){
					found=true;
					break;
				}
				temp=temp->next;
			}
			if(found){
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				temp->next=NULL;
				temp->prev=NULL;
				delete temp;
				cout<<"Contact deleted....."<<endl;
				return true;
			}
			return false;
		} else{
			return false;
		}
	}
	
	void deletedata(){
	   FileName.open("Contacts.txt", ios::in);
	   if(FileName.peek()==EOF && head==NULL){
			cout<<"Contacts are already empty....."<<endl;
			FileName.close();
			return;
	   }
	   if(!(FileName.eof()) && head==NULL){
			FileName.close();
			storefiledata();
			if(del()){
				storedatafromLL();
			}
			return;
	   }
	   if(!(FileName.eof()) && head!=NULL){
			string word;
			FileName>>word;
			if(word!=head->name){
				FileName.close();
				storefiledata();
				if(del()){
					storedatafromLL();
				}
			}
	   }
	}
	void storedatafromLL(){
		remove("Contacts.txt");
		FileName.open("Contacts.txt",ios::app);
		Node* temp=head;
		while(temp!=NULL){
			FileName<<temp->name<<"\t"<<temp->phone_no<<"\t"<<temp->group<<"\t"<<endl;
			temp=temp->next;
		}
		FileName.close();
	}

	void storefiledata(){
		head=NULL;
		bool fl=false;
		FileName.open("Contacts.txt",ios::in);
		string word,word1,word2;
		while ( !FileName.eof() )
        {
			FileName>>word;
			FileName>>word1;
			FileName>>word2;
			Node* node=new Node(word,word1,word2);
			if(head==NULL){
				node->next=head;
				node->prev=NULL;
				head=node;
				fl=true;
			}else{

				Node* temp=head;
				while (temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=node;
				node->prev=temp;
				fl=true;
			}
        }
		if(fl){
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->prev->next=NULL;
			temp->prev=NULL;
			delete temp;
			FileName.close();
		}

	}
	void create(){
		FileName.open("Contacts.txt",ios::app);
		string name,phone,label;
		char op;
		cout<<"Name of Contact:";
		cin>>name;
		cout<<"Phone Number:";
		cin>>phone;
		cout<<"Do you want to label this contact(y/n)";
		cin>>op;
		if(op=='y' || op=='Y'){
			label=option();
		}
		else{
			label="Basic";
		}
		FileName<<name<<"\t"<<phone<<"\t"<<label<<"\t"<<endl;
		FileName.close();
		Node* node=new Node(name,phone,label);
		if(head==NULL){
			node->next=head;
			node->prev=NULL;
			head=node;
			return;
		}
		Node* temp=head;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=node;
		node->prev=temp;
	}
	
	void DisplayAll(){
		Node* temp=head;
		int count=0;
		cout<<"Name\t\tPhone\tLabel"<<endl;
		while(temp!=NULL){
			cout<<temp->name<<"\t\t";
			cout<<temp->phone_no<<"\t";
			cout<<temp->group<<"\t\t"<<endl;
			temp=temp->next;
			count++;		 
		}
		cout<<"Total contacts ="<<count<<endl;
	}

	void displayspecific(string n){
		Node* temp=head;
		int count=0;
		cout<<"Name\t\tPhone\t\tLabel"<<endl;
		while(temp!=NULL){
			if(temp->group==n){
				cout<<temp->name<<"\t\t";
				cout<<temp->phone_no<<"\t";
				cout<<temp->group<<endl;
					count++;
			}
			temp=temp->next;
			
		}
		cout<<"total "<< n<<" contacts ="<<count<<endl;
	}

	void display(){
		int i=0;
		if(i==0){
			storefiledata();
			i++;
		}
		if(head==NULL){
			cout<<"Contact Book is empty"<<endl;
			return;
		}
		BubbleSort();
		char op;
		cout<<"Do you want to display:"<<endl;
		cout<<"1.All Contact"<<endl;
		cout<<"2.Specific label Contact"<<endl;
		cin>>op;
		switch(op){
			case '1':{
				DisplayAll();
				break;
			}
			case '2':{
				a:
				char op1;
				cout<<"1.Family"<<endl;
				cout<<"2.Friend"<<endl;
				cout<<"3.Emergency"<<endl;
				cin>>op1;
				if(op1=='1'){
					displayspecific("Family");
				}else if(op1=='2'){
					displayspecific("Friend");
				}else if(op1=='3'){
					displayspecific("Emergency");
				} else{
					cout<<"Invalid input..";
					goto a;
				}
				break;
			}
			default:{
				cout<<"Invalid Input....."<<endl;
			}
		}
	}

	void BubbleSort(){
		if(head== NULL){
			cout<<"Contact Book is empty...."<<endl;
			return;
		}
		Node* temp=head;
		Node *i,*j;
		string n;
		for(i=temp;i->next!=NULL;i=i->next){
			for(j=i->next;j!=NULL;j=j->next){
				if(i->name > j->name){
					n=i->name;
					i->name=j->name;
					j->name=n;

					n=i->phone_no;
					i->phone_no=j->phone_no;
					j->phone_no=n;

					n=i->group;
					i->group=j->group;
					j->group=n;
				}
			}
		}
		
		storedatafromLL();
	}
};
int main(){
	Contact_BOOK obj;
	obj.menu();
}

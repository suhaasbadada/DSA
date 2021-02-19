#include <iostream>
using namespace std;

struct Node{
	struct Node* next;
	int data;

	Node(int data){
		this->data=data;
		next=NULL;
	}
};

struct LinkedList{
	Node* head;
	LinkedList(){
		head=NULL;
	}

	void insertbeg(int data){
		Node* temp=new Node(data);
		temp->next=head;
		head=temp;
	}

	void insertend(int data){
		Node* nn=new Node(data);
		Node* temp=head;
		if(head==NULL){
			head=nn;
		}
		else{
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=nn;
		}
	}

	void insertafter(int num,int data){
		Node* nn=new Node(data);
		Node* temp=head;

		while(temp->data!=num){
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	void reverse_k(int k){
		Node* current=head;
		Node *prev=NULL;
		Node *t=NULL;

		int counter=k;
		while(counter-- && current!=NULL){
			t=current->next;
			current->next=prev;

			prev=current;
			current=t;
			
		}
		head=prev;

		Node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}		
		
		temp->next=t;
	}

	
};


int main(){

	LinkedList l;
	l.insertend(1);
	l.insertend(2);
	l.insertend(2);
	l.insertend(4);
	l.insertend(5);
	l.insertend(6);
	l.insertend(7);
	l.insertend(8);
	l.print();

	l.reverse_k(4);
	l.print();
	
	return 0;
}
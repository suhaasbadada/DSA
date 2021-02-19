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

	void insertafter(int num,int data){
		Node* temp=head;
		Node* nn=new Node(data);

		while(temp->data!=num){
			temp=temp->next;
		}
		nn->next=temp->next;	
		temp->next=nn;
	}

	void insertend(int data){
		Node* nn=new Node(data);
		Node* temp=head;
		
		if(temp==NULL){
			head=nn;
		}
		else{
			while(temp->next!=NULL){
				temp=temp->next;				
			}
			temp->next=nn;			
		}
		//free(temp);
	}

	void deletenode(int num){
		Node* temp=head;
		if(temp->data==num){
			head=temp->next;
		}
		else{
			while(temp->next->data!=num){
				temp=temp->next;
			}
			temp->next=temp->next->next;
		}
				
	}	

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	Node* getHead(){
		return head;
	}

	Node* getTail(){
		Node* temp=head;

		while(temp->next!=NULL){
			temp=temp->next;
		}

		return temp;
	}
};

void makeCircular(LinkedList l){
	Node* h=l.getHead();
	Node* t=l.getTail();
	t->next=h;
}

void makeLinear(LinkedList l){
	Node* t=l.getHead();

	while(t->next!=l.getHead()){
		t=t->next;
	}
	t->next=NULL;
}

void printCircular(LinkedList l){
	Node* temp=l.getHead();

	while(temp->next!=l.getHead()){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}

int main(){
	LinkedList l;
	l.insertend(10);
	l.insertend(8);
	l.insertend(5);
	l.insertend(7);
	l.insertend(2);
	makeCircular(l);
	makeLinear(l);
	l.deletenode(2);
	makeCircular(l);
	printCircular(l);
	
	//l.print();
	
	return 0;
}
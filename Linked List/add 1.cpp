#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;

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

	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

	void reverse_itr(){
		Node* current=head;
		Node *prev=NULL;
		Node *next=NULL;

		while(current!=NULL){
			next=current->next;
			current->next=prev;

			prev=current;
			current=next;
		}
		head=prev;
	}

};

void add_1(LinkedList l){
	l.reverse_itr();
	Node* temp=l.getHead();
	Node* tail=l.getTail();	
	
	int carry;

	while(temp->data==9){
		temp->data=0;
		temp=temp->next;
	}
	temp->data=temp->data+1;
	l.reverse_itr();
}

int main(){

	LinkedList l;

	l.insertend(1);
	l.insertend(2);
	l.insertend(3);

	add_1(l);
	
	l.print();

	

	return 0;
}
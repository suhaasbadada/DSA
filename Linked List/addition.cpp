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

	void reverse_recurs();


};

void add(LinkedList l1,LinkedList l2){

	LinkedList res;
	Node* h1=l1.getHead();
	Node* h2=l2.getHead();

	
	int carry=0;
	int digit;

	while(h1!=NULL || h2!=NULL || carry){
		int sum=0;

		if(h1!=NULL){
			sum+=h1->data;
			h1=h1->next;
		}

		if(h2!=NULL){
			sum+=h2->data;
			h2=h2->next;
		}

		sum+=carry;
		carry=sum/10;
		digit=sum%10;
		res.insertend(digit);
	}
	res.print();
}



int main(){

	LinkedList l1,l2;
	l1.insertend(3);
	l1.insertend(4);
	l1.insertend(2);

	l2.insertend(9);
	l2.insertend(7);
	l2.insertend(6);
	l2.insertend(5);

	l1.reverse_itr();
	l2.reverse_itr();

	l1.print();
	l2.print();

	add(l1,l2);

	return 0;
}
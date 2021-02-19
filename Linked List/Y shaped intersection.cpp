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

};

void add(LinkedList l1,LinkedList l2){
	Node* tail=l1.getTail();
	tail->next=l2.getHead();

}

Node* Y_intersection(LinkedList l1,LinkedList l2){
	Node* temp1=l1.getHead();
	Node* temp2=l2.getHead();


	if(temp1==NULL || temp2==NULL){
		return NULL;
	}

	while(temp1!=temp2){
		temp1=temp1->next;
		temp2=temp2->next;

		if(temp1==NULL){
			temp1=l2.getHead();
		}

		if(temp2==NULL){
			temp2=l1.getHead();
		}

	}
	return temp1;
}

int main(){

	LinkedList l1;
	LinkedList l2;
	LinkedList common;


	l1.insertend(3);
	l1.insertend(6);
	l1.insertend(9);

	l2.insertend(10);

	common.insertend(15);
	common.insertend(30);

	add(l1,common);
	add(l2,common);
	
	
	l1.print();
	l2.print();

	cout<<Y_intersection(l1,l2)->dataptr;
	

	return 0;
}
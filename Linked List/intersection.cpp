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
	
	void print(){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}

};

void intersection(LinkedList l1,LinkedList l2){
		Node* t1=l1.getHead();
		Node* t2=l2.getHead();

		LinkedList intersected;

		while(t1!=NULL && t2!=NULL){
			if(t1->data==t2->data){
				
				intersected.insertend(t2->data);
				t1=t1->next;
				t2=t2->next;
			}
			else if(t1->data < t2->data){
				t1=t1->next;
			}else{
				t2=t2->next;
			}
		}

		intersected.print();
	}


int main(){

	LinkedList l1;
	LinkedList l2;


	l1.insertend(1);
	l1.insertend(2);
	l1.insertend(3);
	l1.insertend(4);
	l1.insertend(6);

	l2.insertend(2);
	l2.insertend(4);
	l2.insertend(6);
	l2.insertend(8);


	
	
	l1.print();
	l2.print();

	intersection(l1,l2);
	

	return 0;
}
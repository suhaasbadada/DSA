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

	bool isCircular(){
		
		Node* ptr=head;
		Node* temp=head;

		while(true){

			ptr=ptr->next;

			if(ptr==NULL){
				return false;
				break;
			}
			else if(ptr==head){
				return true;
				break;
			}
			
		}
	}

};

void circularHalves(LinkedList l){
	Node* h=l.getHead();
	Node* temp=l.getHead();
	Node* oneStep=l.getHead();
	Node* twoSteps=l.getHead();

	cout<<"First Half:";
	cout<<oneStep->data<<" ";
	oneStep=oneStep->next;			
	//twoSteps=twoSteps->next->next;	

	if(l.isCircular()){
		while(twoSteps->next->next!=h && twoSteps->next!=h){

			cout<<oneStep->data<<" ";
			oneStep=oneStep->next;			
			twoSteps=twoSteps->next->next;	

		}
		//cout<<oneStep->data;
	}

	cout<<"\nSecond Half:";
	
	while(oneStep!=h){
		cout<<oneStep->data<<" ";
		oneStep=oneStep->next;
	}

}


int main(){

	LinkedList l1;


	l1.insertend(11);
	l1.insertend(2);
	l1.insertend(56);
	l1.insertend(12);
	//l1.insertend(5);
	//l1.insertend(6);
	
	Node* h=l1.getHead();
	Node* t=l1.getTail();
	t->next=h;


	circularHalves(l1);
	

	return 0;
}
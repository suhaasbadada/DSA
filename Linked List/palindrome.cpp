#include <iostream>
#include <stack>
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


	Node* getHead(){
		return head;
	}

	Node* getMid(){
		Node* oneStep=head;
		Node* twoSteps=head;
		// left one for even length
		if(head!=NULL){
			while(twoSteps->next!=NULL && twoSteps->next->next!=NULL){
				oneStep=oneStep->next;
				twoSteps=twoSteps->next->next;
			}
		}

		return oneStep;
	}


};


void checkPalindrome(LinkedList l){
		stack <int> s;
		Node* oneStep=l.getHead();
		Node* twoSteps=l.getHead();
		
		if(l.getHead()!=NULL){
			while(twoSteps!=NULL && twoSteps->next!=NULL){
				s.push(oneStep->data);
				oneStep=oneStep->next;
				twoSteps=twoSteps->next->next;
			}
		}
		// odd length,middle one doesnt get pushed,so skip and check from remaining
		// even if twoSteps==NULL, odd if twoSteps->next==NULL
		bool pal=true;
		
		if(twoSteps==NULL){			
			//oneStep=oneStep;
		}else{
			oneStep=oneStep->next;
		}

		while(oneStep!=NULL && !s.empty()){
			if(oneStep->data==s.top()){					
				s.pop();
				oneStep=oneStep->next;
			}else{
				pal=false;
				break;
			}
		}		
		
		
	(pal==1)?(cout<<"Palindrome"):(cout<<"Not a palindrome");
}
	


int main(){

	LinkedList l;
	l.insertend(1);
	l.insertend(2);
	l.insertend(3);
	l.insertend(2);
	l.insertend(1);


	//l.reverse_itr();
	//l.print();
	checkPalindrome(l);
	return 0;
}
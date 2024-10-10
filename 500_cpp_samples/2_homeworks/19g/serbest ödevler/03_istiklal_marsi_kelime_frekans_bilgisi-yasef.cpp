/*
file1.txt dosyası (istiklal marşı) içerisindeki kelimelerin her birinin frekansını bulun, yani her kelimeden kaç kere geçiyor (kim 1 milyon ister yarışmasındaki 1 milyonluk soru için bir yazılım)

daha sonra en çok geçen kelimeden en az geçen kelimeye doğru kaç kere geçtiklerini ekrana yazın.

bonus: kelime yanında aynı zamanda harflerin frekansı da çıkarılırsa +1 puan daha. (yani hangi harften kaç kere geçmiş)

her kelimemin sonundaki özel karakterleri temizleyin
kelime arasında kesme işareti varsa demek ki çekim ekidir, kesme işaretinden sonraki karakterleri atın. benzer durum - gibi işaretler için de geçerli
*/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct node{
	string word;
	int counter;
	node *next;
};
struct nodeList{
	node *head;
	nodeList();
	void add(const string &e, const int &i);
	void print();

};

nodeList::nodeList(){
	head = NULL;
}

void nodeList::add(const string &e, const int &i){

	node *myNode = new node;
	myNode->word = e;
	myNode->counter = i;
	myNode->next = NULL;

	if(head == NULL) head = myNode;
	else{
		node *first = head;
		while(first->next != NULL){
			
			if(first->word == myNode->word){
				first->counter += 1;				
				return; 
			}
			
			first = first -> next;

			if(first->word == myNode->word){
				first->counter += 1;				
				return; 
			}						
		}		
		first->next = myNode;		
	}	
}

void nodeList::print(){
	int max = 0;
	string maxWord;
	node *first = head;
	while(first != NULL){
		if(first -> counter > max){
			max = first -> counter;
			maxWord = first -> word;
		}
		cout << first->word << " " << first->counter << endl;
		first = first->next;
	}
	cout << "Max : " << maxWord << " " << max << endl;
}

string deletePunctuation(string &str){

	char punctuation[] = {',', '.', '\'', ';', '!', '?', '-', ':'};
	int strSize = str.length();
	int puncSize = strlen(punctuation);

	for(int i = 0; i < strSize; i++){
		for(int j = 0; j < puncSize; j++){
			if(str[i] == punctuation[j]){
				strSize = str.length()-1;
				str.erase(i, 1);
				
			}
		}
	}
	return str;
}


int main()
{
	ifstream infile;
	infile.open("file1.txt");
	string s;
	nodeList list;

	while (!infile.eof())
	{
		infile >> s;
		string myString = deletePunctuation(s);
		std::for_each(myString.begin(), myString.end(), [](char &c) {
			c = ::tolower(c);
		});
		list.add(myString, 1);
	}
	list.print();
}

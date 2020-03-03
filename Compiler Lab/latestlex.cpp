#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int isKeyword(char buffer[]){
	char keywords[33][10] = {"auto","break","case","main","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
    set <char> s;
    string identi[100],key[100],oper[100];
	ifstream fin("testsample.txt");
	int i,j=0,k=0,l=0,m=0;

	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}

	while(!fin.eof()){
   		ch = fin.get();

		for(i = 0; i < 6; ++i){
   			if(ch == operators[i]){
                oper[k]=ch;
                k++;
   			}

   		}

   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;

   				if(isKeyword(buffer) == 1)
                    {key[l]=buffer;
                l++;}
   				else
   					{ identi[m]=buffer;
   					m++;}
   		}

	}
cout<<"Keywords:"<<endl;
for(int i=0;i<l;i++)
    cout<<key[i]<<" ";
    
cout<<endl;

cout<<"Identifiers:"<<endl;
for(int i=0;i<m-1;i++){
       // char temp=identi[i];
       cout<<identi[i]<<" ";
        //s.insert(temp);
    }
//for(auto i=s.begin();i!=s.end();i++){
    //    cout<<*i<<" ";
    //}
cout<<endl;
cout<<"operators:"<<endl;
for(int i=0;i<k;i++)
    cout<<oper[i]<<" ";
	fin.close();
	return 0;
}
 

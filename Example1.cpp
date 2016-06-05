#include<vector>
#include <iostream>
#include<string>
using namespace std;

string code(const string input)
{
	vector<char> output;
	for(int i=0;input[i]!='\0';i++){;
		if(input[i+1]=='\0')	
			output.push_back(input[i]);
		else if(input[i]=='_'){
			output.push_back('\\');
			output.push_back('U');
			output.push_back('L');
			output.push_back('_');
		}
		else if(input[i]-'0'<0||input[i]-'0'>9) {
			output.push_back(input[i]);
			output.push_back('_');
		}
		else if(input[i]-'0'>=0&&input[i]-'0'+1<=9&&input[i+1]!='_'){
			for(int j=1;j<=input[i]-'0'+1;j++)
				output.push_back(input[i+1]);
			output.push_back('_');
		}
		else if(input[i]-'0'>=0&&input[i]-'0'+1<=9&&input[i+1]=='_'){
			output.push_back(input[i]);
			output.push_back('_');
		}
	}
	vector<char>::iterator iter;
	for(iter=output.begin();iter<output.end();iter++)
		cout<<*iter;
	cout<<endl;
	return input;
}

string decode(const string input)
{
	vector<char> output;
	int mark=0;
	for(int i=0;input[i]!='\0';i++){;
		if(input[i]=='_') {
			if(mark!=0)	output.push_back(mark-1+'0');
			mark=0;
		}
		else if(input[i]=='\\'&&input[i+1]=='U'){
			output.push_back('_');
			i=i+2;
		}
		else if(input[i]==input[i+1]||input[i]==input[i-1]) mark++;
		else	output.push_back(input[i]);			
	}
	vector<char>::iterator iter;
	for(iter=output.begin();iter<output.end();iter++)
		cout<<*iter;
	cout<<endl;
	return input;
}

int main()
{
	const string a("24ab_2t2");
	const string b("444_aaaaa_a_b_\\UL_ttt_t_2");
	code(a);
    decode(b);
	system("pause");
	return 0;
}

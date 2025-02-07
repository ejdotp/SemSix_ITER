/*An election ballot is contested by 5 candidates. the candidats are numbered 1 to 5 and the voting is dones by marking the candidate number on the ballot paper. WAP to read the ballots and count the votes cast for each candidate using an array variable count. In case, a number read is outside the range 1 to 5, the ballot should be considered "spoilt ballot", and the program should also count the number of spoilt ballots.*/

#include <iostream>

using namespace std;

int* count = new int[6];

void ballotEntry(int x)
{
	if(x > 0 && x < 6)
		count[x-1]++;
	else
		count[5]++;
}

int main()
{
	cout<<"Voting System\nEnter the candidate numbers for voting: "<<endl;
	while(1){
		int temp;
		cout<<"Enter ballot: ";
		cin>>temp;
		if(temp == -1)
			break;
		ballotEntry(temp);
	}
	
	cout<<"\nVoting Results:"<<endl;
	for(int i = 0; i < 5; i++){
		cout<<"Candidate "<<(i+1)<<": "<<count[i]<<endl;
	}
	cout<<"Number of Spoiled Candidates = "<<count[5]<<endl;
		
	return 0;
}

//It can help students in junior high school recite and test their ZHENGZHI, and it also called DAODE YU FAZHI.
#include<bits/stdc++.h>
using namespace std;

bool ed[100005];
string s[100005];
int titn = 0;

void init()
{
	ifstream fin("./BEIZHENGZHI");
	if(!fin) cout << "[ERROR] Can't open the file of titles, './BEIZHENGZHI'!" << endl, exit(-1);
	while(fin >> s[++titn]);
	fin.close();
}

int main()
{
	init();
	int n;
	while(cin >> n && n > titn) getchar(), cout << "[ERROR] The number is too big. It must lesser than " << titn << "." << endl;
	getchar();
	system("cls");
	mt19937 myrand(time(0));
	int a;
	ofstream olog("./BEIZHENGZHI.log", ios::app);
	char nt[101];
	time_t t1;
	tm *tp1;
	t1=time(NULL);
	tp1=localtime(&t1);
	sprintf(nt, "%d/%02d/%02d %02d:%02d",tp1->tm_year+1900,tp1->tm_mon+1,tp1->tm_mday,tp1->tm_hour,tp1->tm_min);
	olog << "------------------------------------" << endl << nt << endl << endl;
	int tot = 0;
	while(a = myrand() % titn + 1)
		if(tot >= n) break;
		else if(!ed[a] && a <= n)
		{
			++tot;
			ed[a] = true;
			printf("(%d/%d) ", tot, n);
			cout << s[a] << endl;
			olog << a << ". " << s[a] << ' ';
			cout << "Finished? (Y/n) ";
			string c;
			while(getline(cin, c) && (c[0] != 'Y' && c[0] != 'y'))
			{
				if(c[0] == '\n') continue;
				if(c[0] == 'n')
				{
					olog << "PROBLEM: ";
					string problem;
					cout << "Please write down the problem: " << endl;
					getline(cin, problem);
					olog << problem;
					break;
				}
				cout << "Do you think your answer is true? (Y/n/...) ";
			}
			olog << endl;
			system("cls");
		}
	olog.close();
	return 0;
}

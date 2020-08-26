#include<iostream>
#include<cstring>
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
using namespace std;
int n;
char map[101][101];
bool visited[101][101];
void dfs(int y, int x);
int main()
{
	cin >> n;
	//�������� ���᰹��,�������� ���᰹��
	int normal = 0, unnormal = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	//������,������ �� �ι� dfs�ʿ�

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				normal++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'R')map[i][j] = 'G'; // R�ΰ��� G�� �ٲ��ֱ�
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				unnormal++;
			}
		}
	}
	cout << normal << " " << unnormal << endl;
}
void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		//�ʰ� ��� ��籸���� ���ǿ�ҿ� ���ƾ� dfs����
		if (ny >= 1 && ny <= 100 && nx >= 1 && nx <= 100) {
			if (!(visited[ny][nx]) && (map[y][x] == map[ny][nx]))
			{
				dfs(ny, nx);
			}
		}
	}
}
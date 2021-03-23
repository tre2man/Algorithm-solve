#include <iostream>

using namespace std;

#define BOARD_MAX 15

int			g_arr[BOARD_MAX];
int			g_sum;
int         n;

int			correct(int index)
{
	int		i;
	int		check;

	i = -1;
	while (++i < index)
	{
		check = g_arr[i] - g_arr[index];
		if (check < 0)
			check *= -1;
		if (g_arr[index] == g_arr[i] || check == index - i)
			return (0);
	}
	return (1);
}

void		rec(int start)
{
	int		i;

	i = -1;
	if (start == n)
	{
		g_sum++;
		return ;
	}
	while (++i < n)
	{
		g_arr[start] = i;
		if (correct(start))
			rec(start + 1);
	}
}

int			ten_queens_puzzle(void)
{
	int		i;

	i = -1;
	g_sum = 0;
	while (++i < n)
		g_arr[i] = 0;
	rec(0);
	return (g_sum);
}

int main()
{
    cin >> n;
    cout << ten_queens_puzzle() << endl;
}
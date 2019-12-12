#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int arr[501];
	int n,k;
	long double ans;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0;i<n-k+1;i++)
	{
		long double m=0,bs=0;
		for(int j=i;j<i+k;j++) m+=arr[j];
		m/=(long double)k;
		for(int j=i;j<i+k;j++) bs+=pow(arr[j]-m,2);
		bs/=k;
		bs=sqrt(bs);
		if(i==0) ans=bs;
		if(ans>bs) ans=bs;
	}	
	cout<<ans;
} 
 /*
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	int n, k, doll[505];
	long double min= 999999999999999999; // 적당히 아주 큰 수
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> doll[i];
	int i = 0;
	for (int i = 0; i <= n - k; i++) { //i 시작값
		for (int j = i + k - 1; j < n; j++) { //j 끝값 oboe 조심
			long double mean = 0;
			for (int l = i; l <= j; l++) mean += doll[l];
			mean /= (long double)(j - i + 1);
			long double sd = 0;
			for (int l = i; l <= j; l++) sd += (doll[l] - mean)*(doll[l] - mean);
			sd /= (long double)(j - i + 1);
			min = min > sd ? sd : min;
		}
	}
	cout.precision(11);
	cout << sqrt(min);
}
*/

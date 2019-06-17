#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
long long b[100005];
long long sum[100005];
long long answer[100005];
int q;

int main()
{
	int n;
	//retorna un entero 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%lld", &a[i]);
	sort(a + 1, a + 1 + n);

	for (int i = 1; i < n; i++)
		b[i] = a[i + 1] - a[i];
	sort(b + 1, b + n);

	for (int i = 1; i < n; i++)
		sum[i] += sum[i - 1] + b[i];
	//int q; 
	scanf_s("%d", &q);
	int a = q;

	while (q--) {

		long long  temp1, temp2;
		long long temp;
		scanf_s("%lld%lld", &temp1, &temp2);
		temp = temp2 - temp1 + 1;
		int pos = upper_bound(b + 1, b + n, temp) - b;

		long long ans = sum[pos - 1] + temp * (n - pos + 1);

		answer[q] = ans;
		//printf("%lld ", ans);
	}

	int i;

	for(i = a - 1 ; i>=0  ; i--)
	{
		printf("%lld ", answer[i]);
	}
}
